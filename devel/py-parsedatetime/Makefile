# $OpenBSD: Makefile,v 1.11 2019/06/03 16:06:51 sthen Exp $

COMMENT=		parse human-readable date/time text

MODPY_EGG_VERSION =	2.4
DISTNAME=		parsedatetime-${MODPY_EGG_VERSION}
PKGNAME=		py-${DISTNAME}
REVISION=		0

CATEGORIES=		devel

MAINTAINER=		Stuart Henderson <sthen@openbsd.org>

# Apache 2.0
PERMIT_PACKAGE=	Yes

FLAVORS=		python3
FLAVOR?=

MODULES=		lang/python
MODPY_PI=		Yes
MODPY_SETUPTOOLS=	Yes

BUILD_DEPENDS=		devel/py-test-runner${MODPY_FLAVOR}
TEST_DEPENDS=		textproc/py-ICU${MODPY_FLAVOR}

.include <bsd.port.mk>
