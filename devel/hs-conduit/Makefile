# $OpenBSD: Makefile,v 1.13 2019/09/30 12:02:00 kili Exp $

COMMENT =		streaming data processing library

DISTNAME =		conduit-1.3.1.1
CATEGORIES =		devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	cnYXgMJYlr69D7uE92SrV

BUILD_DEPENDS =		${RUN_DEPENDS}

RUN_DEPENDS =		devel/hs-exceptions \
			devel/hs-mono-traversable>=1.0.7 \
			devel/hs-primitive \
			devel/hs-resourcet>=1.2,<1.3 \
			devel/hs-unliftio-core \
			devel/hs-vector

.include <bsd.port.mk>
