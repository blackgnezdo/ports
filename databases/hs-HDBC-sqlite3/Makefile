# $OpenBSD: Makefile,v 1.29 2019/04/24 16:26:54 sthen Exp $

COMMENT =		sqlite3 driver for HDBC

DISTNAME =		HDBC-sqlite3-2.3.3.1
REVISION =		8
CATEGORIES =		databases

# LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	28PjG9NHSLb9snL4BShYwf

RUN_DEPENDS +=		databases/hs-HDBC>=2.3.0.0
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
