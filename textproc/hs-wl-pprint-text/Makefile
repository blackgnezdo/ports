# $OpenBSD: Makefile,v 1.4 2019/09/10 13:51:30 kili Exp $

COMMENT =		Wadler/Leijen pretty printer for text values

DISTNAME =		wl-pprint-text-1.2.0.0
CATEGORIES =		devel textproc

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	FRXoAxOVtbG2qLNIZm1tTr

RUN_DEPENDS =		devel/hs-base-compat>=0.10
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
