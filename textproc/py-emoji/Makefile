# $OpenBSD: Makefile,v 1.4 2019/08/05 17:07:25 kmos Exp $

COMMENT =		emoji for Python

MODPY_EGG_VERSION =	0.5.3
DISTNAME =		emoji-${MODPY_EGG_VERSION}
PKGNAME =		py-${DISTNAME}

CATEGORIES =		textproc

HOMEPAGE =		https://github.com/carpedm20/emoji/

MAINTAINER =		Kurt Mosiejczuk <kmos@openbsd.org>

# BSD
PERMIT_PACKAGE =	Yes

MODULES =		lang/python
MODPY_SETUPTOOLS =	Yes
MODPY_PI =		Yes
MODPY_PYTEST =		Yes

FLAVORS =		python3
FLAVOR ?=

TEST_DEPENDS =		devel/py-nose${MODPY_FLAVOR}

.include <bsd.port.mk>
