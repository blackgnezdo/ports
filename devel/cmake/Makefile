# $OpenBSD: Makefile,v 1.177 2019/09/20 14:37:24 rsadowski Exp $

DPB_PROPERTIES =	parallel

COMMENT =	portable build system

VER =		3.15.3
EPOCH =		0
DISTNAME =	cmake-${VER}
CATEGORIES =	devel

HOMEPAGE =	https://www.cmake.org/

MASTER_SITES =	https://www.cmake.org/files/v${VER:R}/

# BSD
PERMIT_PACKAGE =	Yes

WANTLIB += ${COMPILER_LIBCXX} archive c curl curses expat form
WANTLIB += jsoncpp m rhash uv z

COMPILER =		base-clang ports-gcc

BUILD_DEPENDS +=	textproc/py-sphinx>=1.4

LIB_DEPENDS =		archivers/libarchive \
			devel/libuv \
			devel/jsoncpp \
			net/curl \
			security/rhash

CONFIGURE_STYLE =	simple

CONFIGURE_ARGS =	--datadir=share/cmake \
			--docdir=share/doc/cmake \
			--mandir=man \
			--no-qt-gui \
			--parallel=${MAKE_JOBS} \
			--prefix=${PREFIX} \
			--sphinx-build=${LOCALBASE}/bin/sphinx-build \
			--sphinx-html \
			--sphinx-man \
			--system-libs \
			--verbose

CONFIGURE_ENV +=	MAKE=${MAKE_PROGRAM}

MAKE_FLAGS +=		VERBOSE=1

PORTHOME =		${WRKDIR}

SEPARATE_BUILD =	Yes

TEST_TARGET =		test

TEST_DEPENDS +=		devel/git

SUBST_FILES =	${WRKSRC}/Source/cmLocalGenerator.cxx \
		${WRKSRC}/Source/CPack/cmCPackGenerator.cxx \
		${WRKSRC}/bootstrap

post-patch:
	(find ${WRKSRC}/Modules -name "*.cmake" -print0; \
	find ${WRKSRC}/Tests -name "CMakeLists.txt" -print0) | \
	xargs -0 perl -e 's,/usr/local,${LOCALBASE},g; \
	s,/usr/X11R6,${LOCALBASE},g'
	perl -e 's,/usr/local,${LOCALBASE},g' \
		${SUBST_FILES}
	perl -e 's,/usr/include,${LOCALBASE}/include,' \
		${WRKSRC}/Modules/FindDCMTK.cmake \

pre-configure:
	cp ${FILESDIR}/*.cmake ${WRKSRC}/Modules/
	(find ${WRKSRC}/Modules -name "*.cmake" -print0; \
	find ${WRKSRC}/Tests -name "CMakeLists.txt" -print0) | \
	xargs -0 ${SUBST_CMD}
	${SUBST_CMD} ${SUBST_FILES}

post-install:
	@find ${WRKINST}${LOCALBASE} \( -name "*.bak" -o -name "*.orig" -o -name "*.beforesubst" \) -exec rm {} \;

.include <bsd.port.mk>
