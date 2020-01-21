# $OpenBSD$

COMMENT =		Unix Domain Sockets in Java (AF_UNIX)

HOMEPAGE =		https://github.com/kohlschutter/junixsocket

GH_ACCOUNT =		kohlschutter
GH_PROJECT =		junixsocket
DISTFILES =		${GH_PROJECT}-parent-2.3.1.tar.gz

DISTNAME =		${GH_PROJECT}-2.3.1
WRKDIST =		${WRKDIR}/${GH_PROJECT}-${GH_PROJECT}-parent-2.3.1
CATEGORIES =		net

# GPLv3
PERMIT_PACKAGE =	Yes

MODULES=		java
MODJAVA_VER =		1.8+

SHARED_LIBS = 		junixsocket-native 0.0
NATIVE_C_LIB =		${WRKDIR}/libjunixsocket-native.so.${LIBjunixsocket-native_VERSION}

do-build:
	${CC} -I${JAVA_HOME}/include{,/openbsd} -D_UINT64_T \
		-o ${NATIVE_C_LIB} \
		-shared -fpic \
		${WRKSRC}/junixsocket-native/src/main/c/org_newsclub_net_unix_NativeUnixSocket.c

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/lib
	${INSTALL_PROGRAM} ${NATIVE_C_LIB} ${PREFIX}/lib

.include <bsd.port.mk>
