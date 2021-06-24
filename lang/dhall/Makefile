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
MODCABAL_VERSION	= 1.42.1
MODCABAL_MANIFEST	= \
	Diff	0.4.1	0	\
	OneTuple	0.4.1.1	1	\
	QuickCheck	2.14.3	0	\
	StateVar	1.2.2	0	\
	aeson	2.2.1.0	1	\
	aeson-pretty	0.8.10	0	\
	ansi-terminal	1.0	0	\
	ansi-terminal-types	0.11.5	1	\
	appar	0.1.8	0	\
	asn1-encoding	0.9.6	2	\
	asn1-parse	0.9.5	0	\
	asn1-types	0.3.4	0	\
	assoc	1.1	1	\
	async	2.2.4	4	\
	atomic-write	0.2.0.7	0	\
	attoparsec	0.14.4	5	\
	base-compat	0.13.1	0	\
	base-orphans	0.9.1	0	\
	base16-bytestring	1.0.2.0	1	\
	base64-bytestring	1.2.1.0	1	\
	basement	0.0.16	0	\
	bifunctors	5.6.1	2	\
	blaze-builder	0.4.2.3	0	\
	byteorder	1.0.4	0	\
	cabal-doctest	1.0.9	3	\
	case-insensitive	1.2.1.0	0	\
	cborg	0.2.9.0	0	\
	cborg-json	0.2.5.0	2	\
	cereal	0.5.8.3	0	\
	charset	0.3.10	1	\
	colour	2.3.6	0	\
	comonad	5.0.8	2	\
	contravariant	1.5.5	0	\
	cookie	0.4.6	0	\
	cryptohash-sha256	0.11.102.1	3	\
	crypton	0.34	0	\
	crypton-connection	0.3.1	0	\
	crypton-x509	1.7.6	1	\
	crypton-x509-store	1.6.9	0	\
	crypton-x509-system	1.6.7	0	\
	crypton-x509-validation	1.6.12	0	\
	data-default-class	0.1.2.0	0	\
	data-fix	0.3.2	5	\
	distributive	0.6.2.1	1	\
	dlist	1.0	1	\
	dotgen	0.4.3	0	\
	either	5.0.2	1	\
	generically	0.1.1	2	\
	half	0.3.1	0	\
	hashable	1.4.3.0	1	\
	hourglass	0.2.12	0	\
	hsc2hs	0.68.10	1	\
	http-client	0.7.15	0	\
	http-client-tls	0.3.6.3	0	\
	http-types	0.12.3	0	\
	indexed-traversable	0.1.3	0	\
	indexed-traversable-instances	0.1.1.2	2	\
	integer-conversion	0.1.0.1	1	\
	integer-logarithms	1.0.3.1	5	\
	iproute	1.7.12	0	\
	lens-family-core	2.1.2	0	\
	megaparsec	9.6.1	0	\
	memory	0.18.0	0	\
	mime-types	0.1.2.0	0	\
	mmorph	1.2.0	3	\
	network	3.1.4.0	1	\
	network-uri	2.6.4.2	1	\
	old-locale	1.0.0.7	2	\
	old-time	1.1.0.3	2	\
	optparse-applicative	0.18.1.0	0	\
	parser-combinators	1.3.0	1	\
	parsers	0.12.11	2	\
	pem	0.2.4	0	\
	pretty-simple	4.1.2.0	0	\
	prettyprinter	1.7.1	0	\
	prettyprinter-ansi-terminal	1.1.3	0	\
	primitive	0.8.0.0	1	\
	profunctors	5.6.2	3	\
	random	1.2.1.1	1	\
	repline	0.4.2.0	0	\
	scientific	0.3.7.0	7	\
	semialign	1.3	1	\
	semigroupoids	6.0.0.1	1	\
	serialise	0.2.6.0	3	\
	socks	0.6.1	0	\
	splitmix	0.1.0.5	0	\
	streaming-commons	0.2.2.6	1	\
	strict	0.5	1	\
	tagged	0.8.8	0	\
	temporary	1.3	0	\
	text-iso8601	0.1	1	\
	text-manipulate	0.3.1.0	0	\
	text-short	0.1.5	3	\
	th-abstraction	0.6.0.0	1	\
	th-compat	0.1.4	3	\
	th-lift	0.8.4	0	\
	th-lift-instances	0.1.20	0	\
	these	1.2	1	\
	time-compat	1.9.6.1	6	\
	tls	1.9.0	0	\
	transformers-compat	0.7.2	0	\
	unix-compat	0.7	0	\
	unix-time	0.4.11	0	\
	unordered-containers	0.2.19.1	3	\
	uuid-types	1.0.5.1	0	\
	vector	0.13.1.0	0	\
	vector-stream	0.1.0.0	3	\
	witherable	0.4.2	4	\
	zlib	0.6.3.0	4	\

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/dhall.1 ${PREFIX}/man/man1

.include <bsd.port.mk>


