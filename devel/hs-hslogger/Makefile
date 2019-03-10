# $OpenBSD: Makefile,v 1.35 2019/09/10 13:51:24 kili Exp $

COMMENT =		versatile logging framework

DISTNAME =		hslogger-1.2.10
REVISION =		4
CATEGORIES =		devel sysutils
HOMEPAGE =		https://github.com/jgoerzen/hslogger/wiki

# LGPLv2.1
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	AeBcxdsqOAhG5ylU0fE0Kf

RUN_DEPENDS +=		devel/hs-network \
			devel/hs-old-locale
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
