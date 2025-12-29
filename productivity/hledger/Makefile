COMMENT =		command-line interface for the hledger accounting system

CATEGORIES =		productivity

HOMEPAGE =		https://hledger.org

# GPLv3
PERMIT_PACKAGE =	Yes

WANTLIB =		c curses ffi gmp iconv m pthread util

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

MODULES =		devel/cabal
MODCABAL_STEM =		hledger
MODCABAL_VERSION =	1.51.1

post-install:
	@${INSTALL_MAN} ${WRKSRC}/embeddedfiles/hledger.1 ${PREFIX}/man/man1

.include "cabal.inc"

.include <bsd.port.mk>
