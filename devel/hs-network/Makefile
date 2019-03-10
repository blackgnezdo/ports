# $OpenBSD: Makefile,v 1.32 2019/07/12 20:44:13 sthen Exp $

COMMENT =		Haskell networking library

# Dependency of meta/haskell-platform.
# Please do *not* update without thinking.
PORTROACH =		ignore:1

DISTNAME =		network-2.6.2.1
REVISION =		4
CATEGORIES =		devel net

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	Lfd6hU8QSOtC72PepFdIPJ

.include <bsd.port.mk>
