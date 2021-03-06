# $OpenBSD: Makefile,v 1.21 2019/06/11 00:38:36 kurt Exp $

COMMENT-main =	KDE bindings for running interpreters
COMMENT-java =	KDE Java bindings
DISTNAME =	kross-interpreters-${MODKDE4_VERSION}
PKGNAME-main =	${PKGNAME}
PKGNAME-java =	${PKGNAME:C/interpreters/java/}
REVISION-java =	4
REVISION-main =	7

MULTI_PACKAGES =	-main -java

# XXX Can't use <bsd.port.arch.mk> due to mishandling of MODULES
# causing MODKDE4_VERSION to be undefined.
PSEUDO_FLAVORS =	no_java
FLAVOR ?=

WANTLIB =  m pthread
WANTLIB += ${COMPILER_LIBCXX}
WANTLIB += lib/qt4/QtDBus lib/qt4/QtScript lib/qt4/QtXml
WANTLIB += ${KDE4LIB}/krosscore

WANTLIB-main =  ${WANTLIB} ${MODPY_WANTLIB} ${MODRUBY_WANTLIB}
WANTLIB-main += lib/qt4/QtGui
WANTLIB-main += ${KDE4LIB}/kpty

MODKDE4_USE =		libs

# Unported
CONFIGURE_ARGS =	-DCMAKE_DISABLE_FIND_PACKAGE_FALCON:Bool=Yes

MODULES =		lang/python lang/ruby
CONFIGURE_ARGS +=	-DRUBY_EXECUTABLE=${RUBY}

.if ${FLAVOR:Mno_java}
CONFIGURE_ARGS +=	-DBUILD_java:Bool=No
.else
MODULES +=		java
MODJAVA_VER =		1.8+
.endif

LIB_DEPENDS-main =	${LIB_DEPENDS}

RUN_DEPENDS-main =	${MODPY_RUN_DEPENDS} \
			${MODRUBY_RUN_DEPENDS}

RUN_DEPENDS-java =	${MODJAVA_RUN_DEPENDS}

.include <bsd.port.mk>
