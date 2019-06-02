# $OpenBSD: Makefile,v 1.32 2019/04/24 16:26:55 sthen Exp $

COMMENT =		parser and writer for config files

DISTNAME =		ConfigFile-1.1.4
REVISION =		11
CATEGORIES =		devel sysutils
HOMEPAGE =		https://github.com/jgoerzen/configfile/wiki

# BSD3
PERMIT_PACKAGE_CDROM =	Yes

MODULES =		lang/ghc

MODGHC_BUILD =		cabal hackage haddock register

MODGHC_PACKAGE_KEY =	4FCziRbc8SK1ZZHU77VOGC

RUN_DEPENDS +=		devel/hs-MissingH>=1.0.0
BUILD_DEPENDS +=	${RUN_DEPENDS}

.include <bsd.port.mk>
