# $OpenBSD: Makefile,v 1.24 2019/07/12 20:51:13 sthen Exp $

COMMENT =		bindings to the X11 graphics library for GHC

DISTNAME =		X11-1.8
REVISITION = 		0
CATEGORIES =		x11 devel

HOMEPAGE =		http://code.haskell.org/X11/

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE =		Yes

MODULES =		lang/ghc
MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	EmPX88VPoZtDZY5EQwj6Nb

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-data-default \
			devel/hs-syb

.include <bsd.port.mk>
