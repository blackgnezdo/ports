# $OpenBSD$

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

MODCABAL_STEM		= stack
MODCABAL_VERSION	= 2.7.3
MODCABAL_EXECUTABLES	= stack
# cmdargs is added manually, https://github.com/phadej/cabal-extras/issues/85
MODCABAL_MANIFEST	= \
	Glob	0.10.1	1	\
	StateVar	1.2.2	0	\
	aeson	1.5.6.0	1	\
	annotated-wl-pprint	0.7.0	1	\
	ansi-terminal	0.11	0	\
	ansi-wl-pprint	0.6.9	2	\
	appar	0.1.8	0	\
	asn1-encoding	0.9.6	2	\
	asn1-parse	0.9.5	0	\
	asn1-types	0.3.4	0	\
	assoc	1.0.2	1	\
	async	2.2.3	0	\
	attoparsec	0.14.1	0	\
	attoparsec-iso8601	1.0.2.0	1	\
	auto-update	0.1.6	0	\
	base-compat	0.11.2	0	\
	base-compat-batteries	0.11.2	0	\
	base-orphans	0.8.4	0	\
	base16-bytestring	1.0.1.0	0	\
	base64-bytestring	1.2.0.1	0	\
	basement	0.0.12	1	\
	bifunctors	5.5.11	1	\
	blaze-builder	0.4.2.1	0	\
	blaze-html	0.9.1.2	1	\
	blaze-markup	0.8.2.8	0	\
	byteorder	1.0.4	0	\
	casa-client	0.0.1	0	\
	casa-types	0.0.2	0	\
	case-insensitive	1.2.1.0	0	\
	cereal	0.5.8.1	0	\
	clock	0.8.2	0	\
	cmdargs	0.10.21	0	\
	colour	2.3.6	0	\
	comonad	5.0.8	1	\
	conduit	1.3.4.1	0	\
	conduit-combinators	1.3.0	0	\
	conduit-extra	1.3.5	0	\
	connection	0.3.1	1	\
	contravariant	1.5.5	0	\
	cookie	0.4.5	0	\
	cryptohash-sha256	0.11.102.0	1	\
	cryptonite	0.29	0	\
	cryptonite-conduit	0.2.2	1	\
	data-default-class	0.1.2.0	0	\
	data-fix	0.3.2	0	\
	digest	0.0.1.3	0	\
	distributive	0.6.2.1	1	\
	dlist	1.0	0	\
	easy-file	0.2.2	0	\
	echo	0.1.4	0	\
	ed25519	0.0.5.0	3	\
	either	5.0.1.1	1	\
	extra	1.7.9	0	\
	fast-logger	3.0.5	0	\
	file-embed	0.0.14.0	0	\
	filelock	0.1.1.5	0	\
	filtrable	0.1.6.0	0	\
	fsnotify	0.3.0.1	1	\
	generic-deriving	1.14	1	\
	githash	0.1.6.1	0	\
	hackage-security	0.6.0.1	8	\
	hashable	1.3.2.0	0	\
	hi-file-parser	0.1.2.0	0	\
	hourglass	0.2.12	0	\
	hpack	0.34.4	0	\
	hsc2hs	0.68.7	1	\
	http-api-data	0.4.3	2	\
	http-client	0.7.8	0	\
	http-client-tls	0.3.5.3	1	\
	http-conduit	2.3.8	0	\
	http-download	0.2.0.0	0	\
	http-types	0.12.3	0	\
	indexed-traversable	0.1.1	1	\
	infer-license	0.2.0	0	\
	integer-logarithms	1.0.3.1	0	\
	iproute	1.7.11	0	\
	libyaml	0.1.2	0	\
	lift-type	0.1.0.1	0	\
	lifted-base	0.2.3.12	0	\
	lukko	0.1.1.3	1	\
	megaparsec	9.1.0	1	\
	memory	0.16.0	0	\
	microlens	0.4.12.0	0	\
	microlens-mtl	0.2.0.1	0	\
	microlens-th	0.4.3.10	0	\
	mime-types	0.1.0.9	0	\
	mintty	0.1.2	0	\
	monad-control	1.0.3.1	0	\
	monad-logger	0.3.36	0	\
	monad-loops	0.4.3	0	\
	mono-traversable	1.0.15.1	1	\
	mustache	2.3.1	0	\
	neat-interpolation	0.5.1.2	0	\
	network	3.1.2.2	0	\
	network-uri	2.6.4.1	0	\
	old-locale	1.0.0.7	2	\
	old-time	1.1.0.3	2	\
	open-browser	0.2.1.0	0	\
	optparse-applicative	0.16.1.0	1	\
	optparse-simple	0.1.1.4	0	\
	pantry	0.5.2.3	0	\
	parser-combinators	1.3.0	0	\
	path	0.9.0	0	\
	path-io	1.6.3	3	\
	path-pieces	0.2.1	1	\
	pem	0.2.4	0	\
	persistent	2.13.1.1	0	\
	persistent-sqlite	2.13.0.3	0	\
	persistent-template	2.12.0.0	0	\
	primitive	0.7.2.0	0	\
	profunctors	5.6.2	1	\
	project-template	0.2.1.0	0	\
	random	1.2.0	6	\
	regex-applicative	0.3.4	0	\
	regex-applicative-text	0.1.0.1	5	\
	resource-pool	0.2.3.2	0	\
	resourcet	1.2.4.3	0	\
	retry	0.9.0.0	0	\
	rio	0.1.20.0	0	\
	rio-orphans	0.1.2.0	0	\
	rio-prettyprint	0.1.1.0	0	\
	safe	0.3.19	0	\
	safe-exceptions	0.1.7.2	0	\
	scientific	0.3.7.0	0	\
	semigroupoids	5.3.5	1	\
	semigroups	0.19.1	1	\
	silently	1.2.5.1	0	\
	socks	0.6.1	0	\
	split	0.2.3.4	1	\
	splitmix	0.1.0.3	0	\
	stm-chans	3.0.0.4	1	\
	streaming-commons	0.2.2.1	0	\
	strict	0.4.0.1	1	\
	syb	0.7.2.1	0	\
	tagged	0.8.6.1	2	\
	tar	0.5.1.1	3	\
	tar-conduit	0.3.2	0	\
	temporary	1.3	0	\
	text-metrics	0.3.0	4	\
	th-abstraction	0.4.2.0	1	\
	th-compat	0.1.2	0	\
	th-expand-syns	0.4.8.0	0	\
	th-lift	0.8.2	1	\
	th-lift-instances	0.1.18	0	\
	th-reify-many	0.1.9	0	\
	these	1.1.1.1	2	\
	time-compat	1.9.6	0	\
	tls	1.5.5	0	\
	transformers-base	0.4.6	0	\
	transformers-compat	0.7	0	\
	typed-process	0.2.6.0	0	\
	unicode-data	0.1.0.1	0	\
	unicode-transforms	0.3.8	0	\
	unix-compat	0.5.3	0	\
	unix-time	0.4.7	0	\
	unliftio	0.2.19	0	\
	unliftio-core	0.2.0.1	2	\
	unordered-containers	0.2.14.0	0	\
	uuid-types	1.0.5	0	\
	vector	0.12.3.0	0	\
	vector-algorithms	0.8.0.4	1	\
	x509	1.7.5	1	\
	x509-store	1.6.7	1	\
	x509-system	1.6.6	0	\
	x509-validation	1.6.11	0	\
	yaml	0.11.5.0	0	\
	zip-archive	0.4.1	1	\
	zlib	0.6.2.3	0	\

.include <bsd.port.mk>
