# $OpenBSD: Makefile,v 1.37 2019/07/12 20:44:39 sthen Exp $

COMMENT=		send desktop notifications to a notification daemon

GNOME_VERSION=		0.7.8
GNOME_PROJECT=		libnotify

CATEGORIES=		devel

SHARED_LIBS +=  notify               4.0      # 4.0.0

HOMEPAGE=		http://www.galago-project.org/

# LGPLv2.1
PERMIT_PACKAGE=	Yes

WANTLIB += c gdk_pixbuf-2.0 gio-2.0 glib-2.0 gobject-2.0 intl

MODULES=		devel/meson \
			x11/gnome

BUILD_DEPENDS=		textproc/xmlto

# gtk+3 is needed to build the tests
BUILD_DEPENDS +=	x11/gtk+3

LIB_DEPENDS=		graphics/gdk-pixbuf2

MODGNOME_TOOLS=		gobject-introspection

CONFIGURE_ARGS=		-Dgtk_doc=false

.include <bsd.port.mk>
