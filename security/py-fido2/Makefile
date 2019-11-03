# $OpenBSD: Makefile.template,v 1.85 2019/09/09 19:19:05 kmos Exp $

COMMENT =	Provides library functionality for FIDO 2.0

MODPY_EGG_VERSION =	0.7.3

DISTNAME =	fido2-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	security devel

HOMEPAGE =	https://github.com/Yubico/python-fido2

# BSD, APL 2.0, MPL 2.0
PERMIT_PACKAGE =	Yes

MODULES =	lang/python
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

BUILD_DEPENDS =	security/py-cryptography${MODPY_FLAVOR} \
		devel/py-six${MODPY_FLAVOR} \
		security/py-pyscard

.include <bsd.port.mk>
