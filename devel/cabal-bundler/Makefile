# $OpenBSD$

COMMENT =	use cabal solver to build standalone installation

# https://github.com/phadej/cabal-extras/issues/37
V =		0.1
GH_ACCOUNT = 	phadej
GH_COMMIT =	91865489805b1ef282306c71d606923cc117ae42
GH_PROJECT =	cabal-extras

# Overrides cabal.port.mk which would otherwise preempt bsd.port.mk
DISTNAME =	${GH_PROJECT}-${V}
DISTFILES =	${DISTNAME}-${GH_COMMIT:C/(........).*/\1/}${EXTRACT_SUFX}{${GH_COMMIT}${EXTRACT_SUFX}}
PKGNAME =	${MODCABAL_EXECUTABLES}-${V}
MASTER_SITES =	${MASTER_SITES_GITHUB}

CATEGORIES =	devel
HOMEPAGE =	https://github.com/phadej/cabal-extras

# GPLv3
PERMIT_PACKAGE = Yes

LIB_DEPENDS =	converters/libiconv \
		devel/gmp \
		devel/libffi

RUN_DEPENDS =	devel/cabal

WANTLIB = 	c m pthread util ffi gmp iconv

MODULES =		devel/cabal
MODCABAL_STEM =		${GH_PROJECT}
MODCABAL_VERSION =	${V}
MODCABAL_EXECUTABLES = cabal-bundler

MODCABAL_MANIFEST =	\
	Glob	0.10.1	0	\
	aeson	1.5.4.1	0	\
	ansi-terminal	0.11	0	\
	ansi-wl-pprint	0.6.9	2	\
	assoc	1.0.2	0	\
	async	2.2.2	1	\
	attoparsec	0.13.2.4	1	\
	base-compat	0.11.2	0	\
	base-compat-batteries	0.11.2	0	\
	base-orphans	0.8.3	0	\
	base16-bytestring	1.0.0.0	2	\
	bifunctors	5.5.8	0	\
	binary-instances	1.0.0.1	1	\
	binary-orphans	1.0.1	4	\
	cabal-doctest	1.0.8	2	\
	cabal-install-parsers	0.4	0	\
	cabal-plan	0.7.2.0	0	\
	case-insensitive	1.2.1.0	0	\
	cborg	0.2.4.0	0	\
	clock	0.8	0	\
	colour	2.3.5	0	\
	comonad	5.0.6	1	\
	concurrent-output	1.10.12	0	\
	cryptohash-sha256	0.11.101.0	4	\
	data-fix	0.3.0	0	\
	distributive	0.6.2	2	\
	dlist	1.0	0	\
	half	0.3	0	\
	hashable	1.3.0.0	1	\
	hsc2hs	0.68.7	0	\
	indexed-profunctors	0.1	0	\
	integer-logarithms	1.0.3	2	\
	lukko	0.1.1.2	0	\
	network-uri	2.6.3.0	0	\
	optics-core	0.3.0.1	0	\
	optics-extra	0.3	0	\
	optparse-applicative	0.16.0.0	0	\
	paths	0.2.0.0	3	\
	primitive	0.7.1.0	0	\
	random	1.2.0	2	\
	scientific	0.3.6.2	0	\
	serialise	0.2.3.0	1	\
	splitmix	0.1.0.1	0	\
	strict	0.4	0	\
	tagged	0.8.6	3	\
	tar	0.5.1.1	2	\
	temporary	1.3	0	\
	terminal-size	0.3.2.1	0	\
	text-binary	0.2.1.1	0	\
	th-abstraction	0.4.0.0	0	\
	these	1.1.1.1	0	\
	time-compat	1.9.3	0	\
	topograph	1.0.0.1	0	\
	transformers-compat	0.6.6	0	\
	universe-base	1.1.1	2	\
	unliftio-core	0.2.0.1	1	\
	unordered-containers	0.2.13.0	0	\
	uuid-types	1.0.3	3	\
	vector	0.12.1.2	0	\
	vector-binary-instances	0.2.5.1	2	\
	zinza	0.2	1	\

.include <bsd.port.mk>
