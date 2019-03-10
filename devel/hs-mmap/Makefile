# $OpenBSD: Makefile,v 1.24 2019/07/12 20:44:12 sthen Exp $

COMMENT =		mmap API for Haskell

DISTNAME =		mmap-0.5.8
REVISION =		6
CATEGORIES =		devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	Jx72AS5eseTGDaU5udNQXb

RUN_DEPENDS =		devel/hs-HUnit
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
