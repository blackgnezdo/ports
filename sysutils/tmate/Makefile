# $OpenBSD: Makefile,v 1.7 2019/07/12 20:49:53 sthen Exp $

COMMENT =	instant terminal sharing based on tmux

GH_ACCOUNT =	tmate-io
GH_PROJECT =	tmate
GH_TAGNAME =	2.2.1
REVISION =	2
CATEGORIES =	sysutils

MAINTAINER =	Wesley MOUEDINE ASSABY <milo974@gmail.com>

# BSD
PERMIT_PACKAGE =	Yes

WANTLIB += c event_core event_extra msgpackc curses ssh util

LIB_DEPENDS =	devel/libevent2 \
		devel/msgpack \
		security/libssh

CONFIGURE_STYLE =	autoreconf
CONFIGURE_ARGS +=	--disable-debug

AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=       1.15
AUTORECONF=		./autogen.sh

pre-configure:
# Fixup any stragglers that would pickup libevent1 from base
	sed -i 's,<event.h>,<event2/event.h>,' ${WRKSRC}/*.[ch]

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tmate ${PREFIX}/bin/

.include <bsd.port.mk>
