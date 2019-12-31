// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "services/device/hid/hid_service_fido.h"

#include <poll.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/socket.h>
#include <sys/un.h>

// TODO: should this guard be in fido.h instead?
extern "C" {
#include <fido.h>
}

#include <set>
#include <string>
#include <vector>

#include "base/bind.h"
#include "base/files/file_descriptor_watcher_posix.h"
#include "base/files/file_enumerator.h"
#include "base/files/file.h"
#include "base/location.h"
#include "base/logging.h"
#include "base/posix/eintr_wrapper.h"
#include "base/single_thread_task_runner.h"
#include "base/stl_util.h"
#include "base/strings/pattern.h"
#include "base/strings/stringprintf.h"
#include "base/strings/sys_string_conversions.h"
#include "base/strings/string_util.h"
#include "base/strings/string_split.h"
#include "base/task/post_task.h"
#include "base/threading/scoped_blocking_call.h"
#include "base/threading/thread_task_runner_handle.h"
#include "components/device_event_log/device_event_log.h"
#include "services/device/hid/hid_connection_fido.h"

namespace device {

namespace {

struct ConnectParams {
  ConnectParams(scoped_refptr<HidDeviceInfo> device_info,
                const HidService::ConnectCallback& callback)
      : device_info(std::move(device_info)),
        callback(callback),
        task_runner(base::ThreadTaskRunnerHandle::Get()),
        blocking_task_runner(
            base::CreateSequencedTaskRunner(HidService::kBlockingTaskTraits)) {}
  ~ConnectParams() {}

  scoped_refptr<HidDeviceInfo> device_info;
  HidService::ConnectCallback callback;
  scoped_refptr<base::SequencedTaskRunner> task_runner;
  scoped_refptr<base::SequencedTaskRunner> blocking_task_runner;
  base::ScopedFD fd;
};

void CreateConnection(std::unique_ptr<ConnectParams> params) {
  DCHECK(params->fd.is_valid());
  params->callback.Run(base::MakeRefCounted<HidConnectionFido>(
      std::move(params->device_info), std::move(params->fd),
      std::move(params->blocking_task_runner)));
}

void FinishOpen(std::unique_ptr<ConnectParams> params) {
  scoped_refptr<base::SequencedTaskRunner> task_runner = params->task_runner;

  task_runner->PostTask(
      FROM_HERE,
      base::Bind(&CreateConnection, base::Passed(&params)));
}

static int
terrible_ping_kludge(int fd, const std::string& path)
{
	u_char data[256];
	int i, n;
	struct pollfd pfd;

	for (i = 0; i < 4; i++) {
		memset(data, 0, sizeof(data));
		/* broadcast channel ID */
		data[1] = 0xff;
		data[2] = 0xff;
		data[3] = 0xff;
		data[4] = 0xff;
		/* Ping command */
		data[5] = 0x81;
		/* One byte ping only, Vasili */
		data[6] = 0;
		data[7] = 1;
		HID_LOG(EVENT) << "send ping " << i << " " << path;
		if (write(fd, data, 64) == -1)
			return -1;
		HID_LOG(EVENT) << "wait reply" << " " << path;
		memset(&pfd, 0, sizeof(pfd));
		pfd.fd = fd;
		pfd.events = POLLIN;
		if ((n = poll(&pfd, 1, 100)) == -1) {
		  HID_PLOG(EVENT) << "poll" << " " << path;
			return -1;
		} else if (n == 0) {
		  HID_LOG(EVENT) << "timed out" << " " << path;
			continue;
		}
		if (read(fd, data, 64) == -1)
			return -1;
		/*
		 * Ping isn't always supported on the broadcast channel,
		 * so we might get an error, but we don't care - we're
		 * synched now.
		 */
		HID_LOG(EVENT) << "got reply" << " " << path;
		return 0;
	}
	HID_LOG(EVENT) << "no response" << " " << path;
	return -1;
}

void OpenOnBlockingThread(
    std::unique_ptr<ConnectParams> params) {
  base::ScopedBlockingCall scoped_blocking_call(
      FROM_HERE, base::BlockingType::MAY_BLOCK);
  scoped_refptr<base::SequencedTaskRunner> task_runner = params->task_runner;

  base::FilePath device_path(params->device_info->device_node());
  base::File device_file;
  int flags =
      base::File::FLAG_OPEN | base::File::FLAG_READ | base::File::FLAG_WRITE;
  device_file.Initialize(device_path, flags);
  const auto& device_node = params->device_info->device_node();
  if (!device_file.IsValid()) {
    HID_LOG(EVENT) << "Failed to open '" << device_node
                   << "': "
                   << base::File::ErrorToString(device_file.error_details());
    task_runner->PostTask(FROM_HERE, base::Bind(params->callback, nullptr));
    return;
  }
  if (terrible_ping_kludge(device_file.GetPlatformFile(), device_node) != 0) {
    HID_LOG(EVENT) << "Failed to ping " << device_path;
    task_runner->PostTask(FROM_HERE, base::Bind(params->callback, nullptr));
    return;
  }
  params->fd.reset(device_file.TakePlatformFile());
  FinishOpen(std::move(params));
}

}

class HidServiceFido::BlockingTaskHelper {
 public:
  BlockingTaskHelper(base::WeakPtr<HidServiceFido> service)
      : service_(std::move(service)),
        task_runner_(base::ThreadTaskRunnerHandle::Get()) {
    DETACH_FROM_SEQUENCE(sequence_checker_);
  }

  ~BlockingTaskHelper() = default;

  void Start() {
    DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);
    base::ScopedBlockingCall scoped_blocking_call(
        FROM_HERE, base::BlockingType::MAY_BLOCK);

    fido_dev_info_t *devlist = NULL;
    fido_dev_t *dev = NULL;
    size_t devlist_len = 0, i;
    const char *path;
    int r;
    const int MAX_FIDO_DEVICES = 256;

    if ((devlist = fido_dev_info_new(MAX_FIDO_DEVICES)) == NULL) {
      HID_LOG(ERROR) << "fido_dev_info_new failed";
      goto out;
    }
    if ((r = fido_dev_info_manifest(devlist, MAX_FIDO_DEVICES,
				    &devlist_len)) != FIDO_OK) {
      HID_LOG(ERROR) << "fido_dev_info_manifest: " << fido_strerr(r);
      goto out;
    }

    HID_LOG(EVENT) << "fido_dev_info_manifest found "
		   << devlist_len << " device(s)";

    for (i = 0; i < devlist_len; i++) {
      const fido_dev_info_t *di = fido_dev_info_ptr(devlist, i);
      if (di == NULL) {
	HID_LOG(ERROR) << "fido_dev_info_ptr " << i << " failed";
	continue; 
      }
      if ((path = fido_dev_info_path(di)) == NULL) {
	HID_LOG(ERROR) << "fido_dev_info_path " << i << " failed";
	continue;
      }
      HID_LOG(EVENT) << "trying device " << i << ": " << path;
      if ((dev = fido_dev_new()) == NULL) {
	HID_LOG(ERROR) << "fido_dev_new failed";
	continue;
      }
      if ((r = fido_dev_open(dev, path)) != FIDO_OK) {
	HID_LOG(ERROR) << "fido_dev_open failed " << path;
	fido_dev_free(&dev);
	continue;
      }
      OnDeviceAdded(std::string(path));
      fido_dev_close(dev);
      fido_dev_free(&dev);
    }

  out:
    if (devlist != NULL)
      fido_dev_info_free(&devlist, MAX_FIDO_DEVICES);

    task_runner_->PostTask(FROM_HERE,
			   base::Bind(&HidServiceFido::FirstEnumerationComplete, service_));
  }

  void OnDeviceAdded(std::string device_node) {
    // Magic values produced by running USB_GET_REPORT_DESC as root
    // and without pledge. They were identical for a couple of
    // different security keys from Yubico. Apparently Chromium wants
    // to see these bytes, but fido devices prohibit this ioctl.
    std::vector<uint8_t> report_descriptor(
            { 0x06, 0xd0, 0xf1, 0x09, 0x01, 0xa1, 0x01, 0x09,
	      0x20, 0x15, 0x00, 0x26, 0xff, 0x00, 0x75, 0x08,
	      0x95, 0x40, 0x81, 0x02, 0x09, 0x21, 0x15, 0x00,
	      0x26, 0xff, 0x00, 0x75, 0x08, 0x95, 0x40, 0x91,
	      0x02, 0xc0
	    });
    // Dummy values work just fine.
    uint16_t vendor_id = 0xffff;
    uint16_t product_id = 0xffff;
    std::string product_name = "";
    std::string serial_number = "";
    scoped_refptr<HidDeviceInfo> device_info(new HidDeviceInfo(
        device_node, vendor_id, product_id, product_name, serial_number,
        device::mojom::HidBusType::kHIDBusTypeUSB,
        report_descriptor, device_node));

    task_runner_->PostTask(FROM_HERE, base::Bind(&HidServiceFido::AddDevice,
                                                 service_, device_info));
  }

  void OnDeviceRemoved(std::string device_node) {
    base::ScopedBlockingCall scoped_blocking_call(
        FROM_HERE, base::BlockingType::MAY_BLOCK);
    task_runner_->PostTask(
        FROM_HERE, base::Bind(&HidServiceFido::RemoveDevice, service_,
                              device_node));
  }

 private:

  SEQUENCE_CHECKER(sequence_checker_);

  // This weak pointer is only valid when checked on this task runner.
  base::WeakPtr<HidServiceFido> service_;
  scoped_refptr<base::SequencedTaskRunner> task_runner_;

  DISALLOW_COPY_AND_ASSIGN(BlockingTaskHelper);
};

HidServiceFido::HidServiceFido()
    : task_runner_(base::ThreadTaskRunnerHandle::Get()),
      blocking_task_runner_(
          base::CreateSequencedTaskRunner(kBlockingTaskTraits)),
      weak_factory_(this),
      helper_(std::make_unique<BlockingTaskHelper>(weak_factory_.GetWeakPtr())) {
  blocking_task_runner_->PostTask(
      FROM_HERE,
      base::Bind(&BlockingTaskHelper::Start, base::Unretained(helper_.get())));
}

HidServiceFido::~HidServiceFido() {
  blocking_task_runner_->DeleteSoon(FROM_HERE, helper_.release());
}

base::WeakPtr<HidService> HidServiceFido::GetWeakPtr() {
  return weak_factory_.GetWeakPtr();
}

void HidServiceFido::Connect(const std::string& device_guid,
                            const ConnectCallback& callback) {
  DCHECK_CALLED_ON_VALID_SEQUENCE(sequence_checker_);

  const auto& map_entry = devices().find(device_guid);
  if (map_entry == devices().end()) {
    base::ThreadTaskRunnerHandle::Get()->PostTask(
        FROM_HERE, base::Bind(callback, nullptr));
    return;
  }

  scoped_refptr<HidDeviceInfo> device_info = map_entry->second;

  auto params = std::make_unique<ConnectParams>(device_info, callback);

  scoped_refptr<base::SequencedTaskRunner> blocking_task_runner =
      params->blocking_task_runner;
  blocking_task_runner->PostTask(
      FROM_HERE, base::Bind(&OpenOnBlockingThread, base::Passed(&params)));
}

}  // namespace device
