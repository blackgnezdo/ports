# $OpenBSD: Makefile,v 1.2 2018/01/22 21:48:45 kili Exp $

COMMENT =		Wadler/Leijen pretty printer for text values

# Version 1.1.1.0 requires an additional dependency 'base-compat'
# just for avoiding compiler pragmas for certain versions of ghc.
PORTROACH =		limit:^1\.1\.0\.

DISTNAME =		wl-pprint-text-1.2.0.0
CATEGORIES =		devel textproc

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	FRXoAxOVtbG2qLNIZm1tTr

RUN_DEPENDS =		devel/hs-base-compat>=0.10
BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
