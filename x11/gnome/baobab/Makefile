# $OpenBSD: Makefile,v 1.53 2019/07/07 11:20:50 ajacoutot Exp $

COMMENT=		directory tree analyzer for GNOME

GNOME_PROJECT=		baobab
GNOME_VERSION=		3.32.0

# GPLv2 - GFDLv1.1
PERMIT_PACKAGE=		Yes

WANTLIB += atk-1.0 c cairo cairo-gobject gdk-3 gdk_pixbuf-2.0
WANTLIB += gio-2.0 glib-2.0 gobject-2.0 gtk-3 intl m pango-1.0
WANTLIB += pangocairo-1.0

LIB_DEPENDS=		x11/gtk+3

MODULES=		devel/dconf \
			devel/meson \
			x11/gnome

MODGNOME_TOOLS += desktop-file-utils gobject-introspection yelp
MODGNOME_TOOLS += gtk-update-icon-cache vala

.include <bsd.port.mk>
