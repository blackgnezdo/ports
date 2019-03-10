# $OpenBSD: Makefile,v 1.5 2019/09/10 13:51:27 kili Exp $

COMMENT =		consistent filesystem interaction

DISTNAME =		system-fileio-0.3.16.3
REVISION =		2
CATEGORIES =		devel

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc
MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	52q9KsfNWugCD4ytA2tLWy

BUILD_DEPENDS =		${RUN_DEPENDS}

RUN_DEPENDS =		devel/hs-system-filepath>=0.3.1,<0.5

.include <bsd.port.mk>
