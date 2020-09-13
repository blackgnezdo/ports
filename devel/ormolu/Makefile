# $OpenBSD$

COMMENT =	A formatter for Haskell source code

MODCABAL_STEM =		ormolu
MODCABAL_VERSION =	0.1.4.1
MODCABAL_DATA_DIR =	data
CATEGORIES =	devel
HOMEPAGE =	https://github.com/tweag/ormolu

# BSD3
PERMIT_PACKAGE =		Yes

WANTLIB =		c ffi gmp iconv m pthread util z

MODULES =		devel/cabal

MODCABAL_REVISION =	1
MODCABAL_MANIFEST = \
        Diff    0.4.0   0       \
        alex    3.2.6   0       \
        ansi-terminal   0.11    0       \
        ansi-wl-pprint  0.6.9   2       \
        base-compat     0.11.2  0       \
        colour  2.3.5   0       \
        dlist   1.0     0       \
        ghc-lib-parser  8.10.4.20210206 0       \
        gitrev  1.3.1   0       \
        happy   1.20.0  0       \
        optparse-applicative    0.16.1.0        0       \
        syb     0.7.2.1 0       \
        transformers-compat     0.6.6   0       \

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

.include <bsd.port.mk>
