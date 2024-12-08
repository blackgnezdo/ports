COMMENT=		parser generator for Haskell

MODCABAL_STEM =		happy
MODCABAL_VERSION =	2.1.3
MODCABAL_DATA_DIR =	${WRKBUILD}/happy-lib-${MODCABAL_VERSION}/data
MODCABAL_MANIFEST = \
	happy-lib	2.1.3	0

CATEGORIES=		devel

HOMEPAGE=		http://www.haskell.org/happy/

# BSD3
PERMIT_PACKAGE=	Yes

WANTLIB=		c ffi gmp iconv m pthread

MODULES=		devel/cabal

LIB_DEPENDS=		converters/libiconv \
			devel/gmp \
			devel/libffi

BUILD_DEPENDS+=		textproc/docbook-xsl

# Required for building the documentation and for the regression tests:
USE_GMAKE=		Yes

do-test:
	@cd ${WRKBUILD}/tests && exec ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} -j${MAKE_JOBS} HAPPY=${MODCABAL_BUILT_EXECUTABLE_happy} \
		TEST_HAPPY_OPTS="-t ${MODCABAL_DATA_DIR} --strict"

.include <bsd.port.mk>
