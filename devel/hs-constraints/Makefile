# $OpenBSD: Makefile,v 1.10 2018/01/22 22:01:01 kili Exp $

COMMENT =		constraint manipulation

DISTNAME=		constraints-0.10.1
CATEGORIES =		devel

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	8EXBrRXe4Fh2Bzz0X5WX3G

BUILD_DEPENDS =		${RUN_DEPENDS}
RUN_DEPENDS =		devel/hs-hashable>=1.2,<1.3 \
			devel/hs-transformers-compat>=0.4,<1

.include <bsd.port.mk>
