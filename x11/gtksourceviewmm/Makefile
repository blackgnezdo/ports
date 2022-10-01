COMMENT=		C++ wrapper for gtksourceview

PKGNAME=		gtksourceviewmm-3.91.1
GNOME_PROJECT=		gtksourceviewmm
GNOME_VERSION=		3.91.1

CATEGORIES=		x11

HOMEPAGE=		https://gitlab.gnome.org/GNOME/gtksourceviewmm/

CONFIGURE_STYLE	=	autoconf
CONFIGURE_ARGS=	--disable-documentation
AUTOCONF_VERSION =	2.71

MODULES=		x11/gnome

SHARED_LIBS +=  gtksourceviewmm-4.0       0.0 # 0.0

WANTLIB += ${COMPILER_LIBCXX} X11 Xau Xcomposite Xcursor Xdamage
WANTLIB += Xdmcp Xext Xfixes Xi Xinerama Xrandr Xrender epoxy
WANTLIB += execinfo expat fontconfig freetype m pixman-1 xcb xcb-render
WANTLIB += xcb-shm z

MAINTAINER=		Andreas Mainik

# LGPLv2.1
PERMIT_PACKAGE=	Yes

# c++11
COMPILER=		base-clang ports-gcc

BUILD_DEPENDS=		x11/gtksourceview4 devel/glib2mm x11/gtk3mm

.include <bsd.port.mk>
