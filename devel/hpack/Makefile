# $OpenBSD$

COMMENT=		modern format for Haskell packages

CATEGORIES=		devel

HOMEPAGE=		https://github.com/sol/hpack#readme

# MIT
PERMIT_PACKAGE=	Yes

WANTLIB=		c ffi gmp iconv m pthread

MODULES=		devel/cabal

LIB_DEPENDS=		converters/libiconv \
			devel/gmp \
			devel/libffi

MODCABAL_STEM=		hpack
MODCABAL_VERSION=	0.34.4
MODCABAL_MANIFEST       = \
        Glob    0.10.1  0       \
        aeson   1.5.6.0 1       \
        appar   0.1.8   0       \
        asn1-encoding   0.9.6   2       \
        asn1-parse      0.9.5   0       \
        asn1-types      0.3.4   0       \
        assoc   1.0.2   1       \
        async   2.2.3   0       \
        attoparsec      0.14.1  0       \
        base-compat     0.11.2  0       \
        base-compat-batteries   0.11.2  0       \
        base-orphans    0.8.4   0       \
        base64-bytestring       1.2.0.1 0       \
        basement        0.0.11  3       \
        bifunctors      5.5.10  0       \
        blaze-builder   0.4.2.1 0       \
        byteorder       1.0.4   0       \
        case-insensitive        1.2.1.0 0       \
        cereal  0.5.8.1 0       \
        comonad 5.0.8   0       \
        conduit 1.3.4.1 0       \
        connection      0.3.1   1       \
        cookie  0.4.5   0       \
        cryptonite      0.28    0       \
        data-default-class      0.1.2.0 0       \
        data-fix        0.3.1   0       \
        distributive    0.6.2.1 0       \
        dlist   1.0     0       \
        hashable        1.3.1.0 0       \
        hourglass       0.2.12  0       \
        hsc2hs  0.68.7  1       \
        http-client     0.7.8   0       \
        http-client-tls 0.3.5.3 1       \
        http-types      0.12.3  0       \
        indexed-traversable     0.1.1   0       \
        infer-license   0.2.0   0       \
        integer-logarithms      1.0.3.1 0       \
        iproute 1.7.11  0       \
        libyaml 0.1.2   0       \
        memory  0.15.0  1       \
        mime-types      0.1.0.9 0       \
        mono-traversable        1.0.15.1        0       \
        network 3.1.2.1 1       \
        network-uri     2.6.4.1 0       \
        pem     0.2.4   0       \
        primitive       0.7.1.0 2       \
        random  1.2.0   5       \
        resourcet       1.2.4.2 0       \
        scientific      0.3.6.2 0       \
        socks   0.6.1   0       \
        split   0.2.3.4 1       \
        splitmix        0.1.0.3 0       \
        streaming-commons       0.2.2.1 0       \
        strict  0.4.0.1 0       \
        tagged  0.8.6.1 1       \
        text-metrics    0.3.0   4       \
        th-abstraction  0.4.2.0 0       \
        th-compat       0.1.2   0       \
        these   1.1.1.1 1       \
        time-compat     1.9.5   1       \
        tls     1.5.5   0       \
        transformers-compat     0.6.6   0       \
        unliftio-core   0.2.0.1 1       \
        unordered-containers    0.2.13.0        0       \
        uuid-types      1.0.4   0       \
        vector  0.12.3.0        0       \
        vector-algorithms       0.8.0.4 1       \
        x509    1.7.5   1       \
        x509-store      1.6.7   1       \
        x509-system     1.6.6   0       \
        x509-validation 1.6.11  0       \
        yaml    0.11.5.0        0       \
        zlib    0.6.2.3 0       \

.include <bsd.port.mk>
