# $OpenBSD: Makefile,v 1.1.1.1 2018/01/12 21:36:14 kili Exp $

COMMENT =		Levenshtein edit distances

DISTNAME =		edit-distance-0.2.2.1
REVISION =		0
CATEGORIES =		devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	4bW3W2hnyAoDkdg1hZrDEh

BUILD_DEPENDS+=		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-random>=1.0

.include <bsd.port.mk>
