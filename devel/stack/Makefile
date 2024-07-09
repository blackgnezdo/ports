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
MODCABAL_VERSION	= 2.15.7
# cmdargs is added manually, https://github.com/phadej/cabal-extras/issues/85
MODCABAL_MANIFEST	= \
	cmdargs	0.10.21	0	\
	Glob	0.10.2	3	\
	OneTuple	0.4.2	0	\
	QuickCheck	2.15.0.1	0	\
	StateVar	1.2.2	0	\
	aeson	2.2.3.0	0	\
	aeson-warning-parser	0.1.1	0	\
	annotated-wl-pprint	0.7.0	1	\
	ansi-terminal	1.1.1	0	\
	ansi-terminal-types	1.1	0	\
	appar	0.1.8	0	\
	asn1-encoding	0.9.6	2	\
	asn1-parse	0.9.5	0	\
	asn1-types	0.3.4	0	\
	assoc	1.1.1	0	\
	async	2.2.5	1	\
	attoparsec	0.14.4	5	\
	attoparsec-aeson	2.2.2.0	0	\
	auto-update	0.2.1	0	\
	base-orphans	0.9.2	0	\
	base16-bytestring	1.0.2.0	1	\
	base64-bytestring	1.2.1.0	1	\
	basement	0.0.16	0	\
	bifunctors	5.6.2	0	\
	bitvec	1.1.5.0	1	\
	blaze-builder	0.4.2.3	0	\
	blaze-html	0.9.2.0	1	\
	blaze-markup	0.8.3.0	2	\
	byteorder	1.0.4	0	\
	casa-client	0.0.2	0	\
	casa-types	0.0.2	0	\
	case-insensitive	1.2.1.0	0	\
	cborg	0.2.10.0	1	\
	cereal	0.5.8.3	0	\
	character-ps	0.1	0	\
	clock	0.8.4	0	\
	colour	2.3.6	0	\
	comonad	5.0.8	2	\
	companion	0.1.0	0	\
	conduit	1.3.5	0	\
	conduit-combinators	1.3.0	0	\
	conduit-extra	1.3.6	0	\
	contravariant	1.5.5	0	\
	cookie	0.5.0	0	\
	cryptohash-sha256	0.11.102.1	5	\
	crypton	1.0.0	0	\
	crypton-conduit	0.2.3	0	\
	crypton-connection	0.4.1	0	\
	crypton-x509	1.7.7	0	\
	crypton-x509-store	1.6.9	0	\
	crypton-x509-system	1.6.7	0	\
	crypton-x509-validation	1.6.12	0	\
	data-default-class	0.1.2.0	0	\
	data-fix	0.3.4	0	\
	digest	0.0.2.1	0	\
	distributive	0.6.2.1	1	\
	dlist	1.0	2	\
	easy-file	0.2.5	0	\
	echo	0.1.4	0	\
	ed25519	0.0.5.0	8	\
	extra	1.7.16	0	\
	fast-logger	3.2.3	0	\
	file-embed	0.0.16.0	0	\
	filelock	0.1.1.7	0	\
	fsnotify	0.4.1.0	0	\
	generic-deriving	1.14.5	3	\
	generically	0.1.1	3	\
	githash	0.1.7.0	0	\
	hackage-security	0.6.2.6	3	\
	half	0.3.1	2	\
	hashable	1.4.7.0	0	\
	hi-file-parser	0.1.6.0	0	\
	hourglass	0.2.12	1	\
	hpack	0.37.0	0	\
	hsc2hs	0.68.10	2	\
	http-api-data	0.6.1	0	\
	http-client	0.7.17	0	\
	http-client-tls	0.3.6.3	0	\
	http-conduit	2.3.8.3	0	\
	http-download	0.2.1.0	0	\
	http-types	0.12.4	0	\
	indexed-traversable	0.1.4	0	\
	indexed-traversable-instances	0.1.2	0	\
	infer-license	0.2.0	0	\
	integer-conversion	0.1.1	0	\
	integer-logarithms	1.0.3.1	6	\
	iproute	1.7.12	0	\
	libyaml	0.1.4	0	\
	libyaml-clib	0.2.5	0	\
	lift-type	0.1.1.1	0	\
	lifted-base	0.2.3.12	0	\
	lukko	0.1.2	0	\
	megaparsec	9.6.1	0	\
	memory	0.18.0	0	\
	microlens	0.4.13.1	1	\
	microlens-mtl	0.2.0.3	1	\
	microlens-th	0.4.3.15	0	\
	mime-types	0.1.2.0	0	\
	monad-control	1.0.3.1	0	\
	monad-logger	0.3.40	0	\
	monad-loops	0.4.3	0	\
	mono-traversable	1.0.17.0	0	\
	mtl-compat	0.2.2	0	\
	mustache	2.4.2	0	\
	neat-interpolation	0.5.1.4	0	\
	network	3.2.1.0	0	\
	network-uri	2.6.4.2	1	\
	old-locale	1.0.0.7	2	\
	old-time	1.1.0.4	0	\
	open-browser	0.2.1.0	0	\
	optparse-applicative	0.18.1.0	0	\
	optparse-simple	0.1.1.4	0	\
	os-string	2.0.6	0	\
	pantry	0.9.3.2	0	\
	parser-combinators	1.3.0	1	\
	path	0.9.5	0	\
	path-io	1.8.2	0	\
	path-pieces	0.2.1	1	\
	pem	0.2.4	0	\
	persistent	2.14.6.1	0	\
	persistent-sqlite	2.13.3.0	0	\
	persistent-template	2.12.0.0	0	\
	prettyprinter	1.7.1	0	\
	prettyprinter-ansi-terminal	1.1.3	0	\
	primitive	0.9.0.0	1	\
	project-template	0.2.1.0	0	\
	random	1.2.1.2	0	\
	resource-pool	0.4.0.0	0	\
	resourcet	1.3.0	0	\
	retry	0.9.3.1	0	\
	rio	0.1.22.0	0	\
	rio-orphans	0.1.2.0	0	\
	rio-prettyprint	0.1.8.0	0	\
	safe-exceptions	0.1.7.4	1	\
	scientific	0.3.8.0	1	\
	semialign	1.3.1	0	\
	semigroupoids	6.0.1	1	\
	serialise	0.2.6.1	3	\
	silently	1.2.5.3	0	\
	socks	0.6.1	0	\
	split	0.2.5	0	\
	splitmix	0.1.0.5	1	\
	static-bytes	0.1.0	0	\
	stm-chans	3.0.0.9	0	\
	streaming-commons	0.2.2.6	1	\
	strict	0.5.1	0	\
	tagged	0.8.8	1	\
	tar	0.5.1.1	10	\
	tar-conduit	0.4.1	0	\
	temporary	1.3	0	\
	text-iso8601	0.1.1	0	\
	text-metrics	0.3.2	4	\
	text-short	0.1.6	2	\
	th-abstraction	0.7.0.0	0	\
	th-compat	0.1.5	2	\
	th-lift	0.8.4	2	\
	th-lift-instances	0.1.20	0	\
	these	1.2.1	0	\
	time-compat	1.9.7	2	\
	tls	2.1.0	0	\
	transformers-base	0.4.6	0	\
	transformers-compat	0.7.2	0	\
	typed-process	0.2.11.1	0	\
	unix-compat	0.7.2	0	\
	unix-time	0.4.15	0	\
	unliftio	0.2.25.0	0	\
	unliftio-core	0.2.1.0	4	\
	unordered-containers	0.2.20	2	\
	uuid-types	1.0.6	1	\
	vault	0.3.1.5	7	\
	vector	0.13.1.0	1	\
	vector-algorithms	0.9.0.2	1	\
	vector-stream	0.1.0.1	1	\
	witherable	0.5	0	\
	yaml	0.11.11.2	2	\
	zip-archive	0.4.3.2	1	\
	zlib	0.7.1.0	1	\

.include <bsd.port.mk>
