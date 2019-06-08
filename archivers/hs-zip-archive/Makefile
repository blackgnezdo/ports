# $OpenBSD: Makefile,v 1.4 2018/01/22 21:36:14 kili Exp $

COMMENT =		library dealing with zip archives

DISTNAME =		zip-archive-0.3.2.5
CATEGORIES =		archivers devel

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	K7dlxFxyZuAELXOeWBrx8D

BUILD_DEPENDS =	${RUN_DEPENDS}

RUN_DEPENDS =	archivers/hs-zlib \
		devel/hs-old-time \
		security/hs-digest>=0.0.0.1

.include <bsd.port.mk>
