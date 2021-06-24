# $OpenBSD$

COMMENT =	explicitly typed configuration language

CATEGORIES =	lang

HOMEPAGE =	https://dhall-lang.org

# BSD
PERMIT_PACKAGE =	Yes

WANTLIB =		c curses ffi gmp iconv m pthread util z

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

# there are tests, but not hooked up
NO_TEST =		Yes

MODULES			= devel/cabal
MODCABAL_DATA_DIR	= dhall-lang
MODCABAL_STEM		= dhall
MODCABAL_VERSION	= 1.41.1
MODCABAL_REVISION	= 1
MODCABAL_MANIFEST	= \
	Diff	0.4.1	0	\
	OneTuple	0.3.1	2	\
	QuickCheck	2.14.2	0	\
	StateVar	1.2.2	0	\
	aeson	2.0.3.0	0	\
	aeson-pretty	0.8.9	1	\
	ansi-terminal	0.11.3	0	\
	ansi-wl-pprint	0.6.9	3	\
	appar	0.1.8	0	\
	asn1-encoding	0.9.6	2	\
	asn1-parse	0.9.5	0	\
	asn1-types	0.3.4	0	\
	assoc	1.0.2	2	\
	async	2.2.4	1	\
	atomic-write	0.2.0.7	0	\
	attoparsec	0.14.4	1	\
	base-compat	0.12.1	0	\
	base-compat-batteries	0.12.1	2	\
	base-orphans	0.8.6	0	\
	base16-bytestring	1.0.2.0	0	\
	base64-bytestring	1.2.1.0	0	\
	basement	0.0.14	0	\
	bifunctors	5.5.11	1	\
	blaze-builder	0.4.2.2	1	\
	byteorder	1.0.4	0	\
	cabal-doctest	1.0.9	0	\
	case-insensitive	1.2.1.0	0	\
	cborg	0.2.7.0	0	\
	cborg-json	0.2.4.0	0	\
	cereal	0.5.8.2	0	\
	charset	0.3.9	0	\
	colour	2.3.6	0	\
	comonad	5.0.8	1	\
	connection	0.3.1	1	\
	contravariant	1.5.5	0	\
	cookie	0.4.5	0	\
	cryptohash-sha256	0.11.102.1	0	\
	cryptonite	0.30	0	\
	data-default-class	0.1.2.0	0	\
	data-fix	0.3.2	2	\
	distributive	0.6.2.1	1	\
	dlist	1.0	0	\
	dotgen	0.4.3	0	\
	either	5.0.1.1	1	\
	half	0.3.1	0	\
	hashable	1.4.0.2	0	\
	hourglass	0.2.12	0	\
	hsc2hs	0.68.8	0	\
	http-client	0.7.11	1	\
	http-client-tls	0.3.6.1	0	\
	http-types	0.12.3	0	\
	indexed-traversable	0.1.2	1	\
	indexed-traversable-instances	0.1.1	0	\
	integer-logarithms	1.0.3.1	2	\
	iproute	1.7.12	0	\
	lens-family-core	2.1.0	0	\
	megaparsec	9.2.0	1	\
	memory	0.17.0	0	\
	mime-types	0.1.0.9	0	\
	mmorph	1.2.0	1	\
	network	3.1.2.7	0	\
	network-uri	2.6.4.1	0	\
	optparse-applicative	0.17.0.0	0	\
	parser-combinators	1.3.0	0	\
	parsers	0.12.10	2	\
	pem	0.2.4	0	\
	pretty-simple	4.1.0.0	0	\
	prettyprinter	1.7.1	0	\
	prettyprinter-ansi-terminal	1.1.3	0	\
	primitive	0.7.3.0	0	\
	profunctors	5.6.2	2	\
	random	1.2.1	0	\
	repline	0.4.0.0	0	\
	scientific	0.3.7.0	2	\
	semialign	1.2.0.1	1	\
	semigroupoids	5.3.7	0	\
	semigroups	0.20	0	\
	serialise	0.2.5.0	0	\
	socks	0.6.1	0	\
	splitmix	0.1.0.4	0	\
	streaming-commons	0.2.2.4	0	\
	strict	0.4.0.1	4	\
	tagged	0.8.6.1	2	\
	temporary	1.3	0	\
	text-manipulate	0.3.1.0	0	\
	text-short	0.1.5	0	\
	th-abstraction	0.4.3.0	0	\
	th-compat	0.1.3	0	\
	th-lift	0.8.2	1	\
	th-lift-instances	0.1.19	0	\
	these	1.1.1.1	5	\
	time-compat	1.9.6.1	3	\
	tls	1.5.7	0	\
	transformers-compat	0.7.1	1	\
	unix-compat	0.5.4	1	\
	unordered-containers	0.2.19.1	0	\
	uri-encode	1.5.0.7	2	\
	utf8-string	1.0.2	0	\
	uuid-types	1.0.5	2	\
	vector	0.12.3.1	1	\
	witherable	0.4.2	2	\
	x509	1.7.6	0	\
	x509-store	1.6.9	0	\
	x509-system	1.6.7	0	\
	x509-validation	1.6.12	0	\
	zlib	0.6.2.3	1	\

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/dhall.1 ${PREFIX}/man/man1

.include <bsd.port.mk>


