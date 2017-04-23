# $OpenBSD: Makefile,v 1.17 2017/05/17 20:23:45 sthen Exp $

#  env AUTOCONF_VERSION=2.69 AUTOMAKE_VERSION=1.15 ./autogen.sh

COMMENT =		c++ protocol buffers

V =			3.2.0
DISTNAME =		protobuf-$V

SHARED_LIBS +=		protobuf	1.0   # 7.0
SHARED_LIBS +=		protoc		1.0   # 7.0
SHARED_LIBS +=		protobuf-lite	1.0   # 7.0

CATEGORIES =		devel

HOMEPAGE =		https://github.com/google/protobuf/

# New BSD
PERMIT_PACKAGE_CDROM =	Yes

WANTLIB +=	c m pthread ${LIBCXX} z

MASTER_SITES =		https://github.com/google/protobuf/releases/download/v$V/

TEST_DEPENDS =	devel/gtest

SEPARATE_BUILD =	Yes
USE_GMAKE =		Yes
AUTOCONF = 		autoreconf
CONFIGURE_STYLE =	automake autoconf gnu
CONFIGURE_ARGS +=	--with-zlib 

.include <bsd.port.mk>
