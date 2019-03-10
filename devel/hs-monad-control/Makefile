# $OpenBSD: Makefile,v 1.10 2018/01/22 21:42:27 kili Exp $

COMMENT =		lift control operations through monad transformers

DISTNAME =		monad-control-1.0.0.4
REVISION =		3
CATEGORIES =		devel

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	8psNUKhrooy9pTjJn3dYgT

BUILD_DEPENDS =		${RUN_DEPENDS}

RUN_DEPENDS =		devel/hs-transformers-base>=0.4.4,<0.5 \
			devel/hs-transformers-compat>=0.3,<0.6

.include <bsd.port.mk>
