# $OpenBSD: Makefile,v 1.149 2019/09/30 11:25:03 kili Exp $

COMMENT-main=	PDF rendering library
COMMENT-qt5=	Qt5 interface to PDF rendering library
COMMENT-utils=	PDF conversion tools and utilities

V=		0.81.0
DISTNAME=	poppler-$V
CATEGORIES=	print
PKGNAME-main=	poppler-$V
PKGNAME-utils=	poppler-utils-$V
PKGNAME-qt5=	poppler-qt5-$V

EXTRACT_SUFX=	.tar.xz

SHARED_LIBS +=	poppler              56.0     # 91.0
SHARED_LIBS +=	poppler-glib         19.3     # 8.14
SHARED_LIBS +=	poppler-qt5          7.3      # 1.21
SHARED_LIBS +=	poppler-cpp          11.0     # 0.7

HOMEPAGE=	https://poppler.freedesktop.org/

MAINTAINER=	Matthias Kilian <kili@openbsd.org>

# GPLv2
PERMIT_PACKAGE=	Yes

MASTER_SITES=	${HOMEPAGE}

NOT_FOR_ARCHS-qt5 = arm

MULTI_PACKAGES=-main -qt5 -utils

.include <bsd.port.arch.mk>

# c++-11
COMPILER=	base-clang ports-gcc

cWANTLIB=	expat freetype fontconfig jpeg m pthread tiff z

MODULES=	devel/cmake

MODULES+=	x11/qt5

# devel/boost only as build+run dependency, poppler uses
# header-only classes (from boost/containers/small_vector.hpp)
# which are pulled in by installed headers, but does not use
# boost libraries.
BUILD_DEPENDS+= devel/boost \
		devel/gobject-introspection

RUN_DEPENDS-main= \
		print/poppler-data>=0.4.7 \
		devel/boost

LIB_DEPENDS-main=${MODGCC4_CPPLIBDEP} \
		converters/libiconv \
		devel/gettext,-runtime \
		devel/glib2 \
		graphics/cairo \
		graphics/lcms2 \
		graphics/openjp2 \
		graphics/png \
		graphics/tiff

LIB_DEPENDS-qt5=${MODQT5_LIB_DEPENDS} \
		${MODGCC4_CPPLIBDEP} \
		print/poppler

LIB_DEPENDS-utils=${MODGCC4_CPPLIBDEP} \
		print/poppler

WANTLIB-main=	${cWANTLIB} Xext ffi gio-2.0 glib-2.0 gmodule-2.0 \
		gobject-2.0 pixman-1 openjp2 X11 Xrender cairo pcre \
		png xcb xcb-render lcms2 xcb-shm \
		iconv intl ${COMPILER_LIBCXX}

WANTLIB-qt5=	${cWANTLIB} $(COMPILER_LIBCXX) \
		GL Qt5Core Qt5Gui Qt5Widgets Qt5Xml X11 X11-xcb \
		Xdamage Xext Xfixes Xxf86vm drm execinfo glapi \
		glib-2.0 graphite2 gthread-2.0 harfbuzz \
		iconv icudata icui18n icuuc intl lcms2 openjp2 pcre \
		pcre2-16 png poppler xcb xcb-dri2 xcb-glx

WANTLIB-utils=	X11 Xext Xrender c cairo fontconfig lcms2 m pixman-1 \
		png ${COMPILER_LIBCXX} xcb xcb-render xcb-shm openjp2 \
		poppler z ${cWANTLIB}

CONFIGURE_ARGS+=-DENABLE_UNSTABLE_API_ABI_HEADERS=True \
		-DBUILD_GTK_TESTS=False \
		-DENABLE_LIBCURL=False \
		-DCMAKE_DISABLE_FIND_PACKAGE_NSS3=True \
		-DOpenJPEG_DIR=${LOCALBASE}/lib/openjp2 \
		-DX11BASE=${X11BASE}

.include <bsd.port.mk>
