# $OpenBSD$

COMMENT =	command-line interface for Cabal and Hackage

DISTNAME =	cabal-3.3.0.0
CATEGORIES =	devel

HOMEPAGE =	http://www.haskell.org/cabal/

MAINTAINER =	Greg Steuck <cabal@nest.cx>

# BSD3
PERMIT_PACKAGE =		Yes

# This will eventually be a part of cabal-install 3.4 once this PR
# lands: https://github.com/haskell/cabal/pull/6719
MASTER_SITES =	https://github.com/blackgnezdo/cabal/archive/
DISTFILES = cabal-install-{}3.3.0.0.tar.gz

MASTER_SITES0 = https://hackage.haskell.org/package/

# Applied these three JSONPath queries to bootstrap-deps-ghc-8.10.1.json
# and transposed manualy:
# $.dependencies[?(@.source=="hackage")].package
# $.dependencies[?(@.source=="hackage")].version
# $.dependencies[?(@.source=="hackage")].revision
_MANIFEST = \
	HTTP		  4000.3.14  1 \
	async		  2.2.2      1 \
	base16-bytestring 0.1.1.6    0 \
	base64-bytestring 1.0.0.3    0 \
	cryptohash-sha256 0.11.101.0 4 \
	echo		  0.1.3      1 \
	ed25519		  0.0.2.0    0 \
	edit-distance	  0.2.2.1    1 \
	hackage-security  0.6.0.1    0 \
	hashable          1.3.0.0    1 \
	lukko		  0.1.1.2    0 \
	network           3.1.1.1    0 \
	network-uri	  2.6.3.0    0 \
	random		  1.1        1 \
	resolv		  0.1.2.0    0 \
	tar		  0.5.1.1    2 \
	zlib		  0.6.2.1    1 \

.for package version revision in ${_MANIFEST}
SUPDISTFILES += {${package}-${version}/}${package}-${version}.tar.gz:0
SUPDISTFILES += ${package}{${package}-${version}/revision/${revision}}.cabal:0
.endfor

WANTLIB =		c ffi gmp iconv m pthread util z

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

BUILD_DEPENDS +=	lang/ghc

MODULES =		lang/python

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}

post-extract:
	mkdir ${WRKBUILD}/packages
.for package version revision in ${_MANIFEST}
	ln -s ${FULLDISTDIR}/${package}-${version}.tar.gz ${WRKBUILD}/packages
	ln -s ${FULLDISTDIR}/${package}.cabal ${WRKBUILD}/packages
.endfor

do-build:
	cd ${WRKBUILD} && ${MODPY_BIN} cabal-install/bootstrap.py -d bootstrap-deps-ghc-8.10.1.json

do-install:
	install -m755 ${WRKBUILD}/packages/tmp/bin/cabal ${PREFIX}/bin

.include <bsd.port.mk>
