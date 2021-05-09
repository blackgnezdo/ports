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

MODCABAL_EXECUTABLES	= stack
MODCABAL_STEM		= stack
MODCABAL_VERSION	= 2.11.1
# cmdargs is added manually, https://github.com/phadej/cabal-extras/issues/85
MODCABAL_MANIFEST	= \
	cmdargs	0.10.21	0	\
	Cabal	3.10.1.0	0	\
	Cabal-syntax	3.10.1.0	0	\
	Glob	0.10.2	3	\
	HUnit	1.6.2.0	0	\
	OneTuple	0.4.1.1	0	\
	QuickCheck	2.14.3	0	\
	StateVar	1.2.2	0	\
	aeson	2.1.2.1	3	\
	annotated-wl-pprint	0.7.0	1	\
	ansi-terminal	1.0	0	\
	ansi-terminal-types	0.11.5	1	\
	ansi-wl-pprint	1.0.2	0	\
	appar	0.1.8	0	\
	asn1-encoding	0.9.6	2	\
	asn1-parse	0.9.5	0	\
	asn1-types	0.3.4	0	\
	assoc	1.1	0	\
	async	2.2.4	3	\
	attoparsec	0.14.4	3	\
	attoparsec-iso8601	1.1.0.0	1	\
	auto-update	0.1.6	0	\
	base-compat	0.13.0	0	\
	base-compat-batteries	0.13.0	0	\
	base-orphans	0.9.0	0	\
	base16-bytestring	1.0.2.0	0	\
	base64-bytestring	1.2.1.0	0	\
	basement	0.0.15	0	\
	bifunctors	5.6.1	0	\
	bitvec	1.1.4.0	0	\
	blaze-builder	0.4.2.2	1	\
	blaze-html	0.9.1.2	2	\
	blaze-markup	0.8.2.8	4	\
	byteorder	1.0.4	0	\
	call-stack	0.4.0	0	\
	casa-client	0.0.1	0	\
	casa-types	0.0.2	0	\
	case-insensitive	1.2.1.0	0	\
	cereal	0.5.8.3	0	\
	clock	0.8.3	0	\
	colour	2.3.6	0	\
	comonad	5.0.8	1	\
	conduit	1.3.5	0	\
	conduit-combinators	1.3.0	0	\
	conduit-extra	1.3.6	0	\
	connection	0.3.1	1	\
	contravariant	1.5.5	0	\
	cookie	0.4.6	0	\
	cryptohash-sha256	0.11.102.1	2	\
	cryptonite	0.30	0	\
	cryptonite-conduit	0.2.2	1	\
	data-array-byte	0.1.0.1	1	\
	data-default-class	0.1.2.0	0	\
	data-fix	0.3.2	4	\
	digest	0.0.1.7	0	\
	distributive	0.6.2.1	1	\
	dlist	1.0	0	\
	easy-file	0.2.5	0	\
	echo	0.1.4	0	\
	ed25519	0.0.5.0	7	\
	extra	1.7.13	0	\
	fast-logger	3.2.1	0	\
	file-embed	0.0.15.0	0	\
	filelock	0.1.1.6	0	\
	foldable1-classes-compat	0.1	2	\
	fsnotify	0.4.1.0	0	\
	generic-deriving	1.14.4	0	\
	generically	0.1.1	1	\
	githash	0.1.6.3	0	\
	hackage-security	0.6.2.3	3	\
	hashable	1.4.2.0	1	\
	haskell-lexer	1.1.1	0	\
	hi-file-parser	0.1.4.0	0	\
	hourglass	0.2.12	0	\
	hpack	0.35.2	1	\
	hsc2hs	0.68.9	0	\
	hspec	2.11.1	0	\
	hspec-core	2.11.1	0	\
	hspec-discover	2.11.1	0	\
	hspec-expectations	0.8.3	0	\
	http-api-data	0.5.1	0	\
	http-client	0.7.13.1	1	\
	http-client-tls	0.3.6.1	0	\
	http-conduit	2.3.8	0	\
	http-download	0.2.0.0	0	\
	http-types	0.12.3	0	\
	indexed-traversable	0.1.2.1	0	\
	indexed-traversable-instances	0.1.1.2	1	\
	infer-license	0.2.0	0	\
	integer-logarithms	1.0.3.1	4	\
	iproute	1.7.12	0	\
	libyaml	0.1.2	1	\
	lift-type	0.1.1.1	0	\
	lifted-base	0.2.3.12	0	\
	logict	0.8.1.0	0	\
	lukko	0.1.1.3	4	\
	megaparsec	9.3.1	0	\
	memory	0.18.0	0	\
	microlens	0.4.13.1	0	\
	microlens-mtl	0.2.0.3	0	\
	microlens-th	0.4.3.13	0	\
	mime-types	0.1.1.0	0	\
	mintty	0.1.4	0	\
	monad-control	1.0.3.1	0	\
	monad-logger	0.3.39	1	\
	monad-loops	0.4.3	0	\
	mono-traversable	1.0.15.3	0	\
	mtl-compat	0.2.2	0	\
	mustache	2.4.2	0	\
	neat-interpolation	0.5.1.3	0	\
	network	3.1.4.0	0	\
	network-uri	2.6.4.2	0	\
	old-locale	1.0.0.7	2	\
	old-time	1.1.0.3	2	\
	open-browser	0.2.1.0	0	\
	optparse-applicative	0.17.1.0	0	\
	optparse-simple	0.1.1.4	0	\
	pantry	0.8.2.2	0	\
	parser-combinators	1.3.0	0	\
	path	0.9.2	0	\
	path-io	1.8.1	0	\
	path-pieces	0.2.1	1	\
	pem	0.2.4	0	\
	persistent	2.14.5.0	0	\
	persistent-sqlite	2.13.1.1	0	\
	persistent-template	2.12.0.0	0	\
	prettyprinter	1.7.1	0	\
	prettyprinter-ansi-terminal	1.1.3	0	\
	prettyprinter-compat-ansi-wl-pprint	1.0.2	0	\
	primitive	0.8.0.0	0	\
	project-template	0.2.1.0	0	\
	quickcheck-io	0.2.0	0	\
	random	1.2.1.1	0	\
	raw-strings-qq	1.1	0	\
	resource-pool	0.4.0.0	0	\
	resourcet	1.3.0	0	\
	retry	0.9.3.1	0	\
	rio	0.1.22.0	0	\
	rio-orphans	0.1.2.0	0	\
	rio-prettyprint	0.1.4.0	0	\
	safe	0.3.19	0	\
	safe-exceptions	0.1.7.3	0	\
	scientific	0.3.7.0	5	\
	semialign	1.3	0	\
	semigroupoids	6.0.0.1	0	\
	semigroups	0.20	0	\
	silently	1.2.5.3	0	\
	smallcheck	1.2.1	1	\
	socks	0.6.1	0	\
	split	0.2.3.5	0	\
	splitmix	0.1.0.4	2	\
	stm-chans	3.0.0.9	0	\
	streaming-commons	0.2.2.6	0	\
	strict	0.5	0	\
	syb	0.7.2.3	0	\
	tagged	0.8.7	0	\
	tar	0.5.1.1	6	\
	tar-conduit	0.3.2	0	\
	temporary	1.3	0	\
	text-metrics	0.3.2	2	\
	text-short	0.1.5	2	\
	tf-random	0.5	0	\
	th-abstraction	0.5.0.0	0	\
	th-compat	0.1.4	2	\
	th-expand-syns	0.4.11.0	1	\
	th-lift	0.8.3	0	\
	th-lift-instances	0.1.20	0	\
	th-reify-many	0.1.10	0	\
	these	1.2	0	\
	time-compat	1.9.6.1	5	\
	tls	1.6.0	0	\
	transformers-base	0.4.6	0	\
	transformers-compat	0.7.2	0	\
	typed-process	0.2.11.0	0	\
	unicode-data	0.4.0.1	1	\
	unicode-transforms	0.4.0.1	3	\
	unix-compat	0.7	0	\
	unix-time	0.4.9	0	\
	unliftio	0.2.24.0	0	\
	unliftio-core	0.2.1.0	2	\
	unordered-containers	0.2.19.1	2	\
	uuid-types	1.0.5	4	\
	vault	0.3.1.5	3	\
	vector	0.13.0.0	3	\
	vector-algorithms	0.9.0.1	2	\
	vector-stream	0.1.0.0	2	\
	witherable	0.4.2	4	\
	x509	1.7.7	0	\
	x509-store	1.6.9	0	\
	x509-system	1.6.7	0	\
	x509-validation	1.6.12	0	\
	yaml	0.11.11.0	0	\
	zip-archive	0.4.3	0	\
	zlib	0.6.3.0	1	\

post-patch:
	cp ${FILESDIR}/stack.cabal ${WRKSRC}/

.include <bsd.port.mk>
