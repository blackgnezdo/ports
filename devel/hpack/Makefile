COMMENT =		modern format for Haskell packages

CATEGORIES =		devel

HOMEPAGE =		https://github.com/sol/hpack#readme

# MIT
PERMIT_PACKAGE =	Yes

WANTLIB =		c ffi gmp iconv m pthread

MODULES =		devel/cabal

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

MODCABAL_STEM		= hpack
MODCABAL_VERSION =	0.39.3

.include "cabal.inc"
.include <bsd.port.mk>
