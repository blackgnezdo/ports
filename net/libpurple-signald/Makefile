# $OpenBSD$

COMMENT =	libpurple/Pidgin plugin for signald (Signal)

GH_ACCOUNT =	hoehermann
GH_PROJECT =	libpurple-signald
GH_TAGNAME =	v0.2.0

CATEGORIES =	net

# GPLv3
PERMIT_PACKAGE =	Yes

LIB_DEPENDS =	net/pidgin,-libpurple \
		devel/json-glib


WANTLIB += 	purple glib-2.0 json-glib-1.0 ffi gio-2.0 gmodule-2.0
WANTLIB += 	gobject-2.0 intl pcre pthread z

USE_GMAKE =	Yes

.include <bsd.port.mk>
