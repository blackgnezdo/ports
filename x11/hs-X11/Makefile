# $OpenBSD: Makefile,v 1.25 2019/09/10 13:51:30 kili Exp $

COMMENT =		bindings to the X11 graphics library for GHC

DISTNAME =		X11-1.8
REVISION =		0
CATEGORIES =		x11 devel

HOMEPAGE =		http://code.haskell.org/X11/

MAINTAINER =		Matthias Kilian <kili@openbsd.org>

# BSD3
PERMIT_PACKAGE =		Yes

MODULES =		lang/ghc
MODGHC_BUILD =		cabal hackage haddock register

# Works around https://github.com/xmonad/X11/issues/53
MODGHC_SETUP_CONF_ARGS += --extra-lib-dir=/usr/X11R6/lib

MODGHC_PACKAGE_KEY =	EmPX88VPoZtDZY5EQwj6Nb

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-data-default \
			devel/hs-syb

.include <bsd.port.mk>
