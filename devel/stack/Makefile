COMMENT =	the haskell tool stack

CATEGORIES=		devel

HOMEPAGE=		https://docs.haskellstack.org

# BSD3
PERMIT_PACKAGE=	Yes

WANTLIB=		c ffi gmp iconv m pthread

MODULES=		devel/cabal

LIB_DEPENDS=		converters/libiconv \
			devel/gmp \
			devel/libffi

# Remove the pinning which doesn't help in the port.
post-patch:
	@rm ${WRKSRC}/cabal.project

MODCABAL_EXECUTABLES	= stack
MODCABAL_STEM		= stack
MODCABAL_VERSION =	3.9.3

.include "cabal.inc"

.include <bsd.port.mk>
