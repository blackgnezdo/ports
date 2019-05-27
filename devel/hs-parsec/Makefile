# $OpenBSD: Makefile,v 1.26 2018/01/22 21:42:27 kili Exp $

COMMENT =		Monadic parser combinators

# Dependency of meta/haskell-platform.
# Please do *not* update without thinking.
PORTROACH =		ignore:1

DISTNAME =		parsec-3.1.9
REVISION =		5
CATEGORIES =		devel
HOMEPAGE =		https://github.com/aslatter/parsec

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	J37rm8540ksFDyw3j15L5p

BUILD_DEPENDS =		${RUN_DEPENDS}

.include <bsd.port.mk>
