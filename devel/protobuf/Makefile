# $OpenBSD: Makefile,v 1.17 2017/05/17 20:23:45 sthen Exp $

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

CONFIGURE_STYLE =	gnu
CONFIGURE_ARGS +=	--with-zlib 
CONFIGURE_ENV =		CPPFLAGS="-D_POSIX_C_SOURCE=200809L"

AUTOCONF_VERSION=	2.69
AUTOMAKE_VERSION=	1.15
BUILD_DEPENDS +=	${MODGNU_AUTOCONF_DEPENDS} \
			${MODGNU_AUTOMAKE_DEPENDS} \
			devel/libtool
pre-configure:
	cd ${WRKSRC} && \
		libtoolize && \
		env AUTOMAKE_VERSION=${AUTOMAKE_VERSION} AUTOCONF_VERSION=${AUTOCONF_VERSION} \
		autoreconf -fi -Wall,no-obsolete

MODULES =		gcc4
MODGCC4_ARCHS =		*
MODGCC4_LANGS =		c++

.include <bsd.port.mk>
