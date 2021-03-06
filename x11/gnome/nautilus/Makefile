# $OpenBSD: Makefile,v 1.193 2019/08/07 08:02:57 ajacoutot Exp $

COMMENT=		GNOME file manager

GNOME_PROJECT=		nautilus
GNOME_VERSION=		3.32.3

SHARED_LIBS += nautilus-extension        3.0 # 1.5.0

CATEGORIES=		x11

# GPLv2 - LGPLv2 - GFPLv1.1
PERMIT_PACKAGE=		Yes

WANTLIB += atk-1.0 c cairo cairo-gobject gdk-3 gdk_pixbuf-2.0
WANTLIB += gexiv2 gio-2.0 glib-2.0 gmodule-2.0 gnome-autoar-0
WANTLIB += gobject-2.0 gstpbutils-1.0 gstreamer-1.0 gtk-3 intl
WANTLIB += m pango-1.0 pangocairo-1.0 tracker-sparql-2.0

COMPILER=		base-clang ports-gcc
COMPILER_LANGS=		c

MODULES=		devel/dconf \
			devel/meson \
			x11/gnome

BUILD_DEPENDS=		devel/gsettings-desktop-schemas

RUN_DEPENDS=		x11/gnome/gvfs \
			devel/gsettings-desktop-schemas

LIB_DEPENDS=		graphics/libgexiv2 \
			multimedia/gstreamer1/plugins-base \
			x11/gnome/autoar \
			x11/gnome/tracker

MODGNOME_TOOLS=		desktop-file-utils gobject-introspection \
			gtk-update-icon-cache
MODGNOME_CPPFLAGS=	-I${X11BASE}/include
MODGNOME_LDFLAGS=	-L${X11BASE}/lib

CONFIGURE_ARGS=		-Denable-selinux=false

# needs 'org.gnome.nautilus.preferences'
TEST_DEPENDS=		${BASE_PKGPATH}
TEST_IS_INTERACTIVE=	x11

.include <bsd.port.mk>
