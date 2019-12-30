// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_HID_HID_SERVICE_FIDO_H_
#define DEVICE_HID_HID_SERVICE_FIDO_H_

#include <string>

#include "base/macros.h"
#include "base/memory/ref_counted.h"
#include "base/memory/weak_ptr.h"
#include "base/timer/timer.h"
#include "services/device/hid/hid_service.h"
#include "net/base/io_buffer.h"

namespace device {

class HidServiceFido : public HidService {
 public:
  HidServiceFido();
  ~HidServiceFido() override;

  void Connect(const std::string& device_guid,
               const ConnectCallback& connect) override;
  base::WeakPtr<HidService> GetWeakPtr() override;

 private:
  struct ConnectParams;
  class BlockingTaskHelper;

  static void OpenOnBlockingThread(std::unique_ptr<ConnectParams> params);
  static void FinishOpen(std::unique_ptr<ConnectParams> params);
  static void CreateConnection(std::unique_ptr<ConnectParams> params);

  const scoped_refptr<base::SequencedTaskRunner> task_runner_;
  const scoped_refptr<base::SequencedTaskRunner> blocking_task_runner_;
  // |helper_| lives on the sequence |blocking_task_runner_| posts to and holds
  // a weak reference back to the service that owns it.
  std::unique_ptr<BlockingTaskHelper> helper_;
  base::WeakPtrFactory<HidServiceFido> weak_factory_;

  DISALLOW_COPY_AND_ASSIGN(HidServiceFido);
};

}  // namespace device

#endif  // DEVICE_HID_HID_SERVICE_FIDO_H_
