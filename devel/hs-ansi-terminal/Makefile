# $OpenBSD: Makefile,v 1.11 2018/01/22 21:40:32 kili Exp $

COMMENT =		ANSI terminal package for Haskell

DISTNAME =		ansi-terminal-0.8.2
CATEGORIES =		devel

HOMEPAGE =		http://batterseapower.github.com/ansi-terminal/

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	LZ54B5ErqCiIlNwOVvnj65

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		graphics/hs-colour>=2.3.4,<2.4

.include <bsd.port.mk>
