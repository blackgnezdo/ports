# $OpenBSD: Makefile,v 1.2 2018/01/22 21:48:45 kili Exp $

COMMENT =		Wadler/Leijen pretty printer for text values

# Version 1.1.1.0 requires an additional dependency 'base-compat'
# just for avoiding compiler pragmas for certain versions of ghc.
PORTROACH =		limit:^1\.1\.0\.

DISTNAME =		wl-pprint-text-1.1.0.4
REVISION =		0
CATEGORIES =		devel textproc

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	Fw8LgBKInFZ1l1QCzqOPuT

.include <bsd.port.mk>
