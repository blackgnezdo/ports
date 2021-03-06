# $OpenBSD: Makefile,v 1.12 2019/09/26 13:00:21 kurt Exp $

# see patch-js_src_old-configure_in
USE_WXNEEDED =		Yes

# from spidermonkey38 (may need to be revisited):
# jsapi-tests crashes in js::MarkRangeConservatively() on hppa (SIGSEGV in js/src/jsgc.cpp:1142)
# jsapi-tests crashes in js::Bindings::switchToScriptStorage() on alpha (SIGBUS in jsutil.h:235)
# jsapi-tests crashes in js::Bindings::switchToScriptStorage() on sparc64 & mips64 (SIGBUS in jsutil.h:33)
# but let's keep them to build more packages;
# sync with net/wireshark, x11/gtk+3 and x11/gtk+4
ONLY_FOR_ARCHS =	aarch64 alpha amd64 i386 hppa mips64el mips64 powerpc sparc64

COMMENT =		C/C++ Mozilla's JavaScript engine implementation #'

MOZILLA_VERSION =	60
SUBST_VARS =		MOZILLA_VERSION

V =			${MOZILLA_VERSION}.8.0
DISTNAME =		firefox-${V}esr.source
EXTRACT_SUFX =		.tar.bz2
PKGNAME =		spidermonkey-${MOZILLA_VERSION}.8.0
PKGSPEC =		spidermonkey->=60.0v1,<68.0v1
REVISION =		0
EPOCH =			1

SHARED_LIBS =		mozjs-60 0.0

CATEGORIES =		devel

MAINTAINER =		Jasper Lievisse Adriaanse <jasper@openbsd.org>

HOMEPAGE =		https://developer.mozilla.org/en-US/docs/Mozilla/Projects/SpiderMonkey
MASTER_SITES =          https://ftp.mozilla.org/pub/firefox/releases/${V}esr/source/
EXTRACT_SUFX =		.tar.xz

# MPLv2
PERMIT_PACKAGE=	Yes

WANTLIB += c curses icudata icui18n icuuc m nspr4 plc4 plds4 z
WANTLIB += ${COMPILER_LIBCXX}

MODULES =		lang/python

MODPY_RUNDEP =		No

# C++11
# sync with SHARED_LIBS consumers: x11/gnome/gjs
COMPILER =		base-clang ports-gcc

USE_GMAKE =		yes

LIB_DEPENDS =		devel/nspr \
			textproc/icu4c

AUTOCONF_VERSION=	2.13
BUILD_DEPENDS +=	devel/autoconf/${AUTOCONF_VERSION}

WRKDIST =		${WRKDIR}/firefox-${V}
WRKSRC =		${WRKDIST}/js/src

CONFIGURE_STYLE =	simple
CONFIGURE_ARGS = 	--disable-debug \
			--disable-debug-symbols \
			--disable-jemalloc \
			--disable-strip \
			--disable-optimize \
			--enable-ctypes \
			--enable-readline \
			--enable-release \
			--enable-shared-js \
			--disable-tests \
			--with-intl-api \
			--with-system-zlib \
			--with-system-icu \
			--with-system-nspr

# /usr/bin/ld.lld: error: undefined symbol: std::__1::basic_ostream<char, std::__1::char_traits<char> >::operator<<(unsigned long long)
CONFIGURE_ARGS +=	--disable-js-shell

SO_VERSION =		${LIBmozjs-${MOZILLA_VERSION}_VERSION}
SUBST_VARS +=		SO_VERSION

CONFIGURE_ENV =		LIBS=-lncurses \
			SHELL=/bin/sh \
			SO_VERSION=${SO_VERSION}

MAKE_ENV =		SHELL=/bin/sh \
			SO_VERSION=${SO_VERSION}

NO_TEST =		Yes

pre-configure:
	cd ${WRKSRC} && env -i AUTOCONF_VERSION=${AUTOCONF_VERSION} autoconf
	${SUBST_CMD} ${WRKSRC}/build/moz.build

post-install:
	rm ${PREFIX}/lib/libjs_static.ajs

.include <bsd.port.mk>
