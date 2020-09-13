COMMENT =	A formatter for Haskell source code

CATEGORIES =	devel
HOMEPAGE =	https://github.com/tweag/ormolu

# BSD3
PERMIT_PACKAGE =	Yes

WANTLIB =		c ffi gmp iconv m pthread util z

MODULES =		devel/cabal

MODCABAL_DATA_DIR =	data
MODCABAL_STEM =		ormolu
MODCABAL_VERSION =	0.4.0.0
MODCABAL_REVISION =	2
MODCABAL_MANIFEST = \
	Diff	0.4.1	0	\
	alex	3.2.7.1	0	\
	ansi-terminal	0.11.3	0	\
	ansi-wl-pprint	0.6.9	3	\
	base-compat	0.12.1	0	\
	colour	2.3.6	0	\
	dlist	1.0	0	\
	ghc-lib-parser	9.2.2.20220307	0	\
	gitrev	1.3.1	0	\
	happy	1.20.0	0	\
	optparse-applicative	0.17.0.0	0	\
	syb	0.7.2.1	0	\
	transformers-compat	0.7.1	1	\

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

.include <bsd.port.mk>
