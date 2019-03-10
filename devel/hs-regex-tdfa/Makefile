# $OpenBSD: Makefile,v 1.6 2019/09/10 13:51:26 kili Exp $

COMMENT =		tagged DFA regex engine

DISTNAME =		regex-tdfa-1.2.3.2
CATEGORIES =		devel

# BSD
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	24BpKmE04Wg88SsVhgqjyZ

BUILD_DEPENDS =		${RUN_DEPENDS}

RUN_DEPENDS =		devel/hs-regex-base>=0.93.1

.include <bsd.port.mk>
