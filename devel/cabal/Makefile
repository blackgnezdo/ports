# $OpenBSD$

COMMENT =	command-line interface for Cabal and Hackage

CATEGORIES =	devel

MAINTAINER =	Greg Steuck <cabal@nest.cx>

V = 				3.4
PKGNAME =			cabal-${V}
# BSD3
PERMIT_PACKAGE =		Yes

GH_ACCOUNT = 			haskell
GH_PROJECT = 			cabal
GH_COMMIT = 			81fd8d935a25212d9b38c9b8b41fac2c22d42d58
DIST_SUBDIR =			hackage
EXTRACT_ONLY =			${MAIN_TGZ}
MAIN_TGZ =			${DISTNAME}-${GH_COMMIT:C/(........).*/\1/}${EXTRACT_SUFX}

MASTER_SITES0 = https://hackage.haskell.org/package/
MASTER_SITES = ${HOMEPAGE}/archive/
DISTNAME = cabal
DISTFILES = ${MAIN_TGZ}{${GH_COMMIT}${EXTRACT_SUFX}}
HOMEPAGE = https://github.com/haskell/cabal

# Produced by:
#   cabal v2-run -w /usr/local/bin/ghc exe:cabal-bundler -- \
#     --openbsd cabal -w /usr/local/bin/ghc -p cabal/dist-newstyle/cache/plan.json
_MANIFEST = \
	HTTP	4000.3.15	0	\
	async	2.2.2	1	\
	base16-bytestring	0.1.1.7	0	\
	base64-bytestring	1.2.0.0	0	\
	cryptohash-sha256	0.11.101.0	4	\
	echo	0.1.3	1	\
	ed25519	0.0.5.0	3	\
	edit-distance	0.2.2.1	1	\
	hackage-security	0.6.0.1	3	\
	hashable	1.3.0.0	1	\
	hsc2hs	0.68.7	0	\
	lukko	0.1.1.2	0	\
	network	3.1.2.0	1	\
	network-uri	2.6.3.0	0	\
	random	1.2.0	2	\
	regex-base	0.94.0.0	1	\
	regex-posix	0.96.0.0	1	\
	resolv	0.1.2.0	0	\
	splitmix	0.1.0.1	0	\
	tar	0.5.1.1	2	\
	zlib	0.6.2.2	0	\


.for package version revision in ${_MANIFEST}
DISTFILES += {${package}-${version}/}${package}-${version}.tar.gz:0
DISTFILES += ${package}-${version}_${revision}{${package}-${version}/revision/${revision}}.cabal:0
.endfor

WANTLIB =		c ffi gmp iconv m pthread util z

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi

BUILD_DEPENDS +=	lang/ghc

MODULES =		lang/python

MODPY_VERSION =		${MODPY_DEFAULT_VERSION_3}

post-extract:
	@mkdir -p ${WRKBUILD}/_build/tarballs
.for package version revision in ${_MANIFEST}
	@ln -s ${FULLDISTDIR}/${package}-${version}.tar.gz ${WRKBUILD}/_build/tarballs
	@ln -s ${FULLDISTDIR}/${package}-${version}_${revision}.cabal ${WRKBUILD}/_build/tarballs/${package}.cabal
.endfor

do-build:
	cd ${WRKBUILD} && ${MODPY_BIN} bootstrap/bootstrap.py -d ${FILESDIR}/openbsd-8.10.2.json

do-install:
	install -m755 ${WRKBUILD}/_build/bin/cabal ${PREFIX}/bin

.include <bsd.port.mk>
