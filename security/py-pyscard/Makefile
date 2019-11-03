# $OpenBSD: Makefile.template,v 1.85 2019/09/09 19:19:05 kmos Exp $

COMMENT =	smartcard package for Python

MODPY_EGG_VERSION =	1.9.9
DISTNAME =	pyscard-${MODPY_EGG_VERSION}
PKGNAME =	py-${DISTNAME}

CATEGORIES =	security

HOMEPAGE =	https://github.com/LudovicRousseau/pyscard

# LGPL v2.1
PERMIT_PACKAGE =	Yes

MODULES =		lang/python
MODPY_VERSION =	${MODPY_DEFAULT_VERSION_3}

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

BUILD_DEPENDS =	devel/swig \
		security/pcsc-lite
RUN_DEPENDS =	security/pcsc-lite

.include <bsd.port.mk>
