# $OpenBSD: Makefile.template,v 1.85 2019/09/09 19:19:05 kmos Exp $

COMMENT =	library and command line tool for configuring a YubiKey

MODPY_EGG_VERSION =	3.1.0

DISTNAME =	yubikey-manager-${MODPY_EGG_VERSION}
YK_PROJECT = 	yubikey-manager

CATEGORIES =	sysutils

FLAVORS =	python3
FLAVOR ?=

MODPY_SETUPTOOLS =	Yes
MODULES = 		lang/python

BUILD_DEPENDS =	devel/swig \
		security/yubico/yubikey-personalization
RUN_DEPENDS =	security/py-fido2 \
		security/py-openssl${MODPY_FLAVOR} \
		devel/py-click${MODPY_FLAVOR} \
		devel/pyusb${MODPY_FLAVOR} \
		devel/py-six${MODPY_FLAVOR} \
		security/py-cryptography${MODPY_FLAVOR} \
		security/pcsc-lite
TEST_DEPENDS =	devel/py-mock${MODPY_FLAVOR}

.include <bsd.port.mk>
