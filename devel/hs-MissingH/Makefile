# $OpenBSD: Makefile,v 1.36 2019/07/12 20:44:11 sthen Exp $

COMMENT =		large library of utility functions

DISTNAME =		MissingH-1.4.1.0
CATEGORIES =		devel
HOMEPAGE =		https://github.com/jgoerzen/missingh/wiki

# BSD3
PERMIT_PACKAGE =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	GWEgT0bB4e78lUz1oKC64W

RUN_DEPENDS +=		devel/hs-hslogger \
			devel/hs-HUnit \
			devel/hs-old-locale \
			devel/hs-old-time \
			devel/hs-random \
			devel/hs-regex-compat
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
