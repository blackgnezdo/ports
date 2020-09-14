# $OpenBSD$

# Module for building Haskell programs with cabal-install.
# Inspired by FreeBSD cabal.mk by Gleb Popov.

# Available input variables:
#
#  MODCABAL_MANIFEST - hackage dependencies required by this package, tripples
#    of space separate <package> <version> <revision>. Typically generated
#    with cabal-bundler program from cabal-extras. The patch pending review
#    https://github.com/phadej/cabal-extras/pull/32
#  MODCABAL_DATA_DIR - data-dir from .cabal file (if the port needs the data)
#    https://cabal.readthedocs.io/en/latest/cabal-package.html#pkg-field-data-dir
#  MODCABAL_REVISION - Numeric revision of .cabal file on hackage if one is
#    needed on top of .cabal file contained in the .tar.gz file.
#  MODCABAL_BUILD_ARGS - passed to cabal v2-build, e.g. make MODCABAL_BUILD_ARGS=-v
#    is a nice debugging aid.
#  MODCABAL_FLAGS - passed to --flags= of cabal v2-build. Seemingly superflous given
#    MODCABAL_BUILD_ARGS, but it is useful to keep this value separate as it
#    is used to generate the build plan and will be available without parsing.
#  MODCABAL_EXECUTABLES - Executable target in .cabal file, by default uses
#    the hackage package name.
#    https://cabal.readthedocs.io/en/latest/cabal-package.html#executables
#
# Available output variables:
#
#  MODCABAL_BUILT_EXECUTABLE_${_exe} is built for each of MODCABAL_EXECUTABLES.
#    These are available for `make test` after `make build` phase.

ONLY_FOR_ARCHS =	i386 amd64

BUILD_DEPENDS +=	devel/cabal \
			lang/ghc

MASTER_SITES0 =		https://hackage.haskell.org/package/

DIST_SUBDIR ?= 		hackage

# The .cabal files are explicitly copied over the ones extracted from
# archives by the normal extraction rules.
EXTRACT_CASES += *.cabal) ;;

MODCABAL_HACKAGE_NAME =		${DISTNAME:C,-[0-9.]*$,,}
MODCABAL_HACKAGE_VERSION =	${DISTNAME:C,.*-([0-9.]*)$,\1,}
HOMEPAGE ?=			${MASTER_SITES0}${MODCABAL_HACKAGE_NAME}
MASTER_SITES =			${MASTER_SITES0}${DISTNAME}/
DISTFILES ?=			${DISTNAME}.tar.gz
SUBST_VARS +=			DISTNAME MODCABAL_HACKAGE_NAME \
				MODCABAL_HACKAGE_VERSION PKGNAME

# Oftentime our port name and the executable name coincide.
MODCABAL_EXECUTABLES ?=		${MODCABAL_HACKAGE_NAME}

MODCABAL_post-extract = \
	mkdir -p ${WRKDIR}/.cabal \
	&& touch ${WRKDIR}/.cabal/config

.if defined(MODCABAL_REVISION)
DISTFILES += ${DISTNAME}_${MODCABAL_REVISION}{revision/${MODCABAL_REVISION}}.cabal
MODCABAL_post-extract += \
	&& cp ${FULLDISTDIR}/${DISTNAME}_${MODCABAL_REVISION}.cabal \
		${WRKSRC}/${MODCABAL_HACKAGE_NAME}.cabal
.endif

.if defined(MODCABAL_MANIFEST)

.for _package _version _revision in ${MODCABAL_MANIFEST}

DISTFILES += {${_package}-${_version}/}${_package}-${_version}.tar.gz:0

.if ${_revision} > 0
DISTFILES += ${_package}-${_version}_${_revision}{${_package}-${_version}/revision/${_revision}}.cabal:0
MODCABAL_post-extract += \
	&& cp ${FULLDISTDIR}/${_package}-${_version}_${_revision}.cabal \
		${WRKDIR}/${_package}-${_version}/${_package}.cabal
.endif

# References all the locally available dependencies.  Ideally these
# should be command line options, tracking issue:
# https://github.com/haskell/cabal/issues/3585
MODCABAL_post-extract += \
	&& echo "packages: ${WRKDIR}/${_package}-${_version}/${_package}.cabal" >> ${WRKSRC}/cabal.project.local
.endfor

.endif  # defined(MODCABAL_MANIFEST)

# Automatically copies the cabal.project file if any.  TODO(gnezdo):
# should this do any make variable substitution (like LOCALBASE)?
# If not, maybe use --project_file and skip cp?
MODCABAL_post-extract += \
	&& (test -f ${FILESDIR}/cabal.project \
	    && cp -v ${FILESDIR}/cabal.project ${WRKSRC}; true)

MODCABAL_CABAL = ${SETENV} ${MAKE_ENV} HOME=${WRKDIR} ${LOCALBASE}/bin/cabal

MODCABAL_BUILD_TARGET =	\
	cd ${WRKBUILD} \
	&& ${MODCABAL_CABAL} v2-build --offline --disable-benchmarks --disable-tests \
		-j${MAKE_JOBS} \
		--flags="${MODCABAL_FLAGS}" ${MODCABAL_BUILD_ARGS} \
		${MODCABAL_EXECUTABLES:C/^/exe:&/}

_MODCABAL_INSTALL_TARGET = true

.if defined(MODCABAL_DATA_DIR)
_MODCABAL_LIBEXEC = libexec/cabal
_MODCABAL_INSTALL_TARGET += \
	&& mkdir -p ${PREFIX}/${_MODCABAL_LIBEXEC}

_MODCABAL_INSTALL_TARGET +=  \
	&& ${INSTALL_DATA_DIR} ${WRKSRC}/${MODCABAL_DATA_DIR} ${PREFIX}/share/${DISTNAME} \
	&& cd ${WRKSRC}/${MODCABAL_DATA_DIR} && umask 022 && pax -rw . ${PREFIX}/share/${DISTNAME}
.endif

.for _exe in ${MODCABAL_EXECUTABLES}

# Exports the paths to executables for testing.
MODCABAL_BUILT_EXECUTABLE_${_exe} = $$(find ${WRKSRC}/dist-newstyle -name ${_exe} -type f -perm -a+x)

.if defined(MODCABAL_DATA_DIR)

_MODCABAL_EXPORTS += \
	&& echo 'export ${_exe}_datadir=${LOCALBASE}/share/${DISTNAME}' >> ${PREFIX}/bin/${_exe}

_MODCABAL_INSTALL_TARGET += \
	&& ${INSTALL_PROGRAM} \
		${MODCABAL_BUILT_EXECUTABLE_${_exe}} \
		${PREFIX}/${_MODCABAL_LIBEXEC}/${_exe} \
	&& echo '\#!/bin/sh' > ${PREFIX}/bin/${_exe} \
	${_MODCABAL_EXPORTS} \
	&& echo 'exec ${LOCALBASE}/${_MODCABAL_LIBEXEC}/${_exe} "$$@"' >> ${PREFIX}/bin/${_exe} \
	&& chmod +x ${STAGEDIR}${PREFIX}/bin/${_exe}
.else
# Skips the launcher script indirection when MODCABAL_DATA_DIR is empty.
# TODO(gnezdo): evaluate if this case is common enough to be warranted.
_MODCABAL_INSTALL_TARGET += \
	&& ${INSTALL_PROGRAM} ${MODCABAL_BUILT_EXECUTABLE_${_exe}} ${PREFIX}/bin
.endif

.endfor

.if !target(do-build)
do-build:
	@${MODCABAL_BUILD_TARGET}
.endif

.if !target(do-install)
do-install:
	@${_MODCABAL_INSTALL_TARGET}
.endif
