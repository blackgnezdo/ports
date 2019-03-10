# $OpenBSD: Makefile,v 1.5 2019/07/12 20:43:28 sthen Exp $

COMMENT =		library dealing with zip archives

DISTNAME =		zip-archive-0.2.3.7
REVISION =		3
CATEGORIES =		archivers devel

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	6jdjvMXj8RmIbIFdQ7caD4

BUILD_DEPENDS =	${RUN_DEPENDS}

RUN_DEPENDS =	archivers/hs-zlib \
		devel/hs-old-time \
		security/hs-digest>=0.0.0.1

.include <bsd.port.mk>
