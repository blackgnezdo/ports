# $OpenBSD: Makefile,v 1.4 2018/01/22 21:43:45 kili Exp $

COMMENT =		shell-like programming in Haskell

DISTNAME =		shelly-1.8.0
CATEGORIES =		devel

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc
MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	KRHSpmdfX8GIwLuiAf800a

BUILD_DEPENDS =		${RUN_DEPENDS}

RUN_DEPENDS =		devel/hs-async \
			devel/hs-enclosed-exceptions \
			devel/hs-exceptions>=0.6,<0.11 \
			devel/hs-lifted-async \
			devel/hs-monad-control>=0.3.2,<1.1 \
			devel/hs-system-fileio<0.4 \
			devel/hs-system-filepath>=0.4.7,<0.5 \
			devel/hs-transformers-base \
			devel/hs-unix-compat<0.5

.include <bsd.port.mk>
