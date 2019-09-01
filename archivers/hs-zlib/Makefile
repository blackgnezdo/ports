# $OpenBSD: Makefile,v 1.26 2019/07/12 20:43:28 sthen Exp $

COMMENT =		zlib bindings for Haskell

# Dependency of meta/haskell-platform.
# Please do *not* update without thinking.
PORTROACH =		ignore:1

DISTNAME =		zlib-0.6.2.1
CATEGORIES =		archivers devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	EiCuzWuUbh1FOATBAoeQ3G

.include <bsd.port.mk>
