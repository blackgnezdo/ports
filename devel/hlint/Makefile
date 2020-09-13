# $OpenBSD$

COMMENT =	gives suggestions on how to improve Haskell source code

MODCABAL_STEM =		hlint
MODCABAL_VERSION =	3.1.6

CATEGORIES =	devel
HOMEPAGE =	https://github.com/ndmitchell/hlint#readme

# BSD3
PERMIT_PACKAGE =		Yes

WANTLIB =		c ffi gmp iconv m pthread util z

MODULES =		devel/cabal
MODCABAL_DATA_DIR =	data
MODCABAL_MANIFEST =	\
	aeson	1.5.4.0	0	\
	ansi-terminal	0.11	0	\
	assoc	1.0.2	0	\
	attoparsec	0.13.2.4	0	\
	base-compat	0.11.1	0	\
	base-compat-batteries	0.11.1	0	\
	base-orphans	0.8.2	0	\
	bifunctors	5.5.7	1	\
	cabal-doctest	1.0.8	2	\
	clock	0.8	0	\
	cmdargs	0.10.20	0	\
	colour	2.3.5	0	\
	comonad	5.0.6	1	\
	conduit	1.3.2.1	0	\
	cpphs	1.20.9.1	0	\
	data-default	0.7.1.1	0	\
	data-default-class	0.1.2.0	0	\
	data-default-instances-containers	0.0.1	0	\
	data-default-instances-dlist	0.0.1	0	\
	data-default-instances-old-locale	0.0.1	0	\
	data-fix	0.3.0	0	\
	distributive	0.6.2	2	\
	dlist	1.0	0	\
	extra	1.7.8	0	\
	file-embed	0.0.13.0	0	\
	filepattern	0.1.2	0	\
	ghc-lib-parser-ex	8.10.0.16	0	\
	hashable	1.3.0.0	1	\
	hscolour	1.24.4	0	\
	integer-logarithms	1.0.3	2	\
	libyaml	0.1.2	0	\
	mono-traversable	1.0.15.1	0	\
	old-locale	1.0.0.7	2	\
	polyparse	1.13	1	\
	primitive	0.7.1.0	0	\
	random	1.2.0	2	\
	refact	0.3.0.2	0	\
	resourcet	1.2.4.2	0	\
	scientific	0.3.6.2	0	\
	split	0.2.3.4	0	\
	splitmix	0.1.0.1	0	\
	strict	0.4	0	\
	syb	0.7.1	0	\
	tagged	0.8.6	2	\
	th-abstraction	0.3.2.0	0	\
	these	1.1.1.1	0	\
	time-compat	1.9.3	0	\
	transformers-compat	0.6.5	0	\
	uniplate	1.6.12	1	\
	unliftio-core	0.2.0.1	1	\
	unordered-containers	0.2.12.0	0	\
	utf8-string	1.0.1.1	3	\
	uuid-types	1.0.3	3	\
	vector	0.12.1.2	0	\
	vector-algorithms	0.8.0.3	0	\
	yaml	0.11.5.0	0	\

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

.include <bsd.port.mk>
