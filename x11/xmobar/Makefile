# $OpenBSD: Makefile,v 1.47 2019/09/30 12:54:32 kili Exp $

COMMENT =		minimalistic text based status bar

DISTNAME =		xmobar-0.31
CATEGORIES =		x11
HOMEPAGE =		http://projects.haskell.org/xmobar

# BSD3
PERMIT_PACKAGE =	Yes

WANTLIB =		X11 Xext Xft Xinerama Xrandr Xrender \
			Xss c charset ffi gmp iconv \
			lib/inotify/inotify m pthread util xml2

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage nort
MODGHC_SETUP_CONF_ARGS = --flags="with_xft with_mpd with_mpris with_inotify"
MODGHC_SETUP_CONF_ARGS += --extra-lib-dirs=${LOCALBASE}/lib/inotify/


BUILD_DEPENDS = 	devel/hs-hinotify>=0.3 \
			devel/hs-regex-compat \
			net/hs-HTTP>=4000.2.4 \
			x11/hs-X11>=1.6.1 \
			x11/hs-X11-xft>=0.2,<0.4 \
			x11/hs-dbus>=0.10 \
			audio/hs-libmpd>=0.9,<0.10 \
			devel/hs-parsec-numbers>=0.1.0,<0.2

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi \
			devel/libinotify \
			textproc/libxml

EXAMPLEDIR =		${PREFIX}/share/examples/xmobar

NO_TEST =		Yes

SUBST_VARS +=		LOCALBASE

pre-configure:
	${SUBST_CMD} ${WRKDIST}/xmobar.cabal

post-patch:
	@cp ${FILESDIR}/Setup.lhs ${WRKBUILD}/
	@cp ${FILESDIR}/Batt.hs ${WRKBUILD}/src/Xmobar/Plugins/Monitors
	@cp ${FILESDIR}/Binding.hsc ${WRKBUILD}/src/Xmobar/Plugins/Monitors/Batt
	@cp ${FILESDIR}/apm.c ${WRKBUILD}/src/Xmobar/Plugins/Monitors/Batt
	@cp ${FILESDIR}/apm.h ${WRKBUILD}/src/Xmobar/Plugins/Monitors/Batt

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/xmobar.config ${EXAMPLEDIR}/xmobarrc

.include <bsd.port.mk>
