# $OpenBSD: Makefile,v 1.25 2019/06/03 16:06:53 sthen Exp $

V=		4.2.2
COMMENT=	motion detection software for video

GH_ACCOUNT=	Motion-Project
GH_PROJECT=	motion
GH_TAGNAME=	release-$V
PORTROACH=	skipv:release-$V
DISTNAME=	motion-$V

CATEGORIES=	multimedia

HOMEPAGE=	https://motion-project.github.io/

MAINTAINER=	Stuart Henderson <sthen@openbsd.org>

# GPL (according to source files, v2 only. website says v2+).
PERMIT_PACKAGE=	Yes

WANTLIB += avcodec avdevice avformat avutil c intl jpeg m microhttpd
WANTLIB += pthread sqlite3 swscale webp webpmux

FLAVOR?=
FLAVORS=		mysql pgsql

FLAVOR_COMMA=		${FLAVOR_EXT:S/-/,/g}
SUBST_VARS=		FLAVOR_COMMA

LIB_DEPENDS=		databases/sqlite3 \
			graphics/jpeg \
			graphics/ffmpeg \
			graphics/libwebp \
			www/libmicrohttpd

FAKE_FLAGS=		docdir=${PREFIX}/share/doc/motion \
			examplesdir=${PREFIX}/share/examples/motion \
			sysconfdir=${PREFIX}/share/examples

USE_GMAKE=		Yes
CONFIGURE_STYLE=	autoreconf
AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=	1.15
CONFIGURE_ARGS=		--without-optimizecpu \
			LDFLAGS="-L${LOCALBASE}/lib" \
			CPPFLAGS="-I${LOCALBASE}/include"

.if ${FLAVOR:L:Mmysql}
LIB_DEPENDS+=		databases/mariadb
WANTLIB+=		lib/mysql/mysqlclient z
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

.if ${FLAVOR:L:Mpgsql}
LIB_DEPENDS+=		databases/postgresql
WANTLIB+=		pq
CONFIGURE_ARGS+=	--with-pgsql-lib=${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-pgsql
.endif

NO_TEST=		Yes

pre-configure:
	perl -pi -e s,/usr/local/etc,${SYSCONFDIR},g \
		${WRKSRC}/motion-dist.conf.in

post-install:
	cd ${PREFIX}/share/examples/motion; \
	    rm -f motion.init-{Fedora,Debian,FreeBSD.sh} motion.service

.include <bsd.port.arch.mk>

.if ${ARCH:Mamd64}
CFLAGS+=	-mfpmath=sse -msse3
.endif

.include <bsd.port.mk>
