# $OpenBSD: Makefile,v 1.3 2019/06/12 14:58:15 sthen Exp $

# XXX intersection of GO_ARCHS and LP64_ARCHS
# providers/octodns/octoyaml/read.go:265:17: constant 4294967295 overflows int
ONLY_FOR_ARCHS = amd64

COMMENT =		manage DNS configuration across any number of DNS hosts

GH_ACCOUNT =		StackExchange
GH_PROJECT =		dnscontrol
GH_TAGNAME =		v2.9

CATEGORIES =		net

HOMEPAGE =		https://stackexchange.github.io/dnscontrol/

# MIT
PERMIT_PACKAGE =	Yes

WANTLIB =		c pthread

MODULES =		lang/go

MODGO_FLAGS +=		-tags nosystemd
MODGO_TEST_FLAGS +=	-provider BIND

do-build:
	cd ${WRKSRC} && ${MODGO_CMD} generate
	cd ${WRKSRC} && ${MODGO_CMD} build
	cd ${WRKSRC}/cmd/convertzone && ${MODGO_CMD} build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnscontrol ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/cmd/convertzone/convertzone ${PREFIX}/bin/

do-test:
	cd ${WRKSRC}/integrationTest && ${MODGO_TEST_CMD}

.include <bsd.port.mk>
