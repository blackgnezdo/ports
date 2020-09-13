COMMENT =	A formatter for Haskell source code

CATEGORIES =	devel
HOMEPAGE =	https://github.com/tweag/ormolu

# BSD3
PERMIT_PACKAGE =	Yes

WANTLIB =		c ffi gmp iconv m pthread util z

MODULES =		devel/cabal

MODCABAL_DATA_DIR =	data

MODCABAL_STEM		= ormolu
MODCABAL_VERSION	= 0.7.0.0
MODCABAL_REVISION	= 1
MODCABAL_MANIFEST	= \
	Cabal-syntax	3.10.1.0	0	\
	Diff	0.4.1	0	\
	MemoTrie	0.6.10	0	\
	alex	3.3.0.0	0	\
	ansi-terminal	1.0	0	\
	ansi-terminal-types	0.11.5	1	\
	case-insensitive	1.2.1.0	0	\
	colour	2.3.6	0	\
	data-array-byte	0.1.0.1	1	\
	file-embed	0.0.15.0	0	\
	ghc-lib-parser	9.6.2.20230523	0	\
	happy	1.20.1.1	0	\
	hashable	1.4.2.0	1	\
	integer-logarithms	1.0.3.1	4	\
	megaparsec	9.3.1	0	\
	newtype-generics	0.6.2	2	\
	optparse-applicative	0.18.1.0	0	\
	parsec	3.1.16.1	0	\
	parser-combinators	1.3.0	0	\
	prettyprinter	1.7.1	0	\
	prettyprinter-ansi-terminal	1.1.3	0	\
	primitive	0.8.0.0	0	\
	scientific	0.3.7.0	5	\
	syb	0.7.2.3	0	\
	text	2.0.2	0	\
	th-compat	0.1.4	2	\
	th-env	0.1.1	0	\
	transformers-compat	0.7.2	0	\

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

.include <bsd.port.mk>
