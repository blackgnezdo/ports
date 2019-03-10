# $OpenBSD: Makefile,v 1.29 2018/01/22 21:40:32 kili Exp $

COMMENT =		library to convert between different types

DISTNAME =		convertible-1.1.1.0
REVISION =		7
CATEGORIES =		devel

MAINTAINER =		David Coppa <dcoppa@openbsd.org>

# LGPLv2.1
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	4JGGYsaDyuUDyUW9qH2fP2

RUN_DEPENDS +=		devel/hs-old-locale \
			devel/hs-old-time
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
