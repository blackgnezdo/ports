# $OpenBSD: Makefile,v 1.14 2017/05/17 20:09:36 sthen Exp $

COMMENT =	C++ unit test framework

V=		1.8.0
GH_ACCOUNT=	google
GH_PROJECT=	googletest
GH_TAGNAME=	release-$V
PKGNAME =	gtest-$V
REVISION =	0

SHARED_LIBS +=	gmock		1.0   # .0.0
SHARED_LIBS +=	gmock_main	1.0   # .0.0
SHARED_LIBS +=	gtest		2.0   # .0.0
SHARED_LIBS +=	gtest_main	2.0   # .0.0
REVISION = 1

CATEGORIES =	devel

HOMEPAGE =	https://github.com/google/googletest

# New BSD
PERMIT_PACKAGE_CDROM =	Yes

SEPARATE_BUILD =	Yes

CONFIGURE_ENV =		CXXFLAGS=-g

WANTLIB =		m ${LIBCXX}

MODULES +=		devel/cmake
CONFIGURE_ARGS =	-DBUILD_SHARED_LIBS=ON \
			-Dgtest_build_tests=ON


MODULES +=		gcc4
MODGCC4_ARCHS =		*
MODGCC4_LANGS =		c++

.include <bsd.port.mk>
