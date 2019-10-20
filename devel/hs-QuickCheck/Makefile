# $OpenBSD: Makefile,v 1.31 2019/09/30 12:58:07 kili Exp $

COMMENT =		automatic testing of Haskell programs

DISTNAME =		QuickCheck-2.8.2
REVISION =		2
CATEGORIES =		devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	HnXF0X2VHAoBkZ6B5N45ie

RUN_DEPENDS =		devel/hs-random>=1.0.1.0,<1.2 \
			devel/hs-tf-random>=0.4

BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
