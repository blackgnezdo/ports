# $OpenBSD: Makefile,v 1.9 2019/07/12 20:48:45 sthen Exp $

# python3 flavour not needed for this port; the ipaddress module
# is available in core python 3.3+
COMMENT =		Python 3.3's ipaddress for Python 2.6 and 2.7#'

MODPY_EGG_VERSION =	1.0.18
DISTNAME =		ipaddress-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}
CATEGORIES =		net

HOMEPAGE =		https://github.com/phihag/ipaddress

# Python
PERMIT_PACKAGE =	Yes

MODULES =		lang/python

MODPY_PI =		Yes
MODPY_SETUPTOOLS =	Yes

TEST_DEPENDS =		devel/py-nose${MODPY_FLAVOR}

do-test:
	cd ${WRKSRC}; nosetests${MODPY_BIN_SUFFIX}

.include <bsd.port.mk>
