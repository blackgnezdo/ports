# $OpenBSD: Makefile,v 1.14 2018/06/29 22:16:32 espie Exp $

COMMENT =	KDE interactive physics simulator
DISTNAME =	step-${MODKDE4_VERSION}
REVISION =	6

WANTLIB =  c m pthread
WANTLIB += ${COMPILER_LIBCXX}
WANTLIB += lib/qt4/QtDBus lib/qt4/QtGui lib/qt4/QtNetwork
WANTLIB += lib/qt4/QtOpenGL lib/qt4/QtSvg lib/qt4/QtXml
WANTLIB += ${KDE4LIB}/kdeui ${KDE4LIB}/khtml ${KDE4LIB}/kio ${KDE4LIB}/kjs
WANTLIB += ${KDE4LIB}/knewstuff3 ${KDE4LIB}/kparts ${KDE4LIB}/nepomuk
WANTLIB += ${KDE4LIB}/nepomukutils
WANTLIB += cln glib-2.0 gsl gslcblas iconv intl qalculate soprano xml2

MODULES =	multimedia/phonon

BUILD_DEPENDS =	math/eigen2

RUN_DEPENDS =	devel/desktop-file-utils \
		x11/gtk+3,-guic

LIB_DEPENDS = 	devel/gsl \
		math/libqalculate

#CONFIGURE_ARGS =	-DSTEPCORE_TESTS:Bool=True

.include <bsd.port.mk>
