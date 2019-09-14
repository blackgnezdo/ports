# $OpenBSD: Makefile,v 1.18 2019/09/10 13:51:29 kili Exp $

COMMENT=		fast, pure, practical collection of crypto hashes

DISTNAME=		cryptohash-0.11.0
REVISION=		0
CATEGORIES=		security

# BSD3
PERMIT_PACKAGE =	Yes

MODULES=		lang/ghc

MODGHC_BUILD =          cabal hackage haddock register

MODGHC_PACKAGE_KEY =	KpUGDcCRqILELYIjtnASxH

MODGHC_SETUP_CONF_ARGS =        -f cryptoapi

RUN_DEPENDS =		devel/hs-byteable
BUILD_DEPENDS = 	${RUN_DEPENDS}

.include <bsd.port.mk>
