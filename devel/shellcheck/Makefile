COMMENT =		shell script analysis tool

MODCABAL_STEM =		ShellCheck
MODCABAL_VERSION =	0.10.0
MODCABAL_EXECUTABLES =	shellcheck
PKGNAME =		${DISTNAME:L}
CATEGORIES =		devel
HOMEPAGE =		https://www.shellcheck.net/

MAINTAINER =		Caspar Schutijser <caspar@schutijser.com>

# GPLv3
PERMIT_PACKAGE =	Yes

WANTLIB =		c ffi gmp iconv m pthread util

# cabal-bundler --openbsd ShellCheck-0.10.0 --executable shellcheck
MODULES =		devel/cabal
.include "cabal-manifest.inc"

LIB_DEPENDS =		converters/libiconv \
			devel/gmp \
			devel/libffi
RUN_DEPENDS-main =

NO_TEST =		Yes

# pkg_add pandoc; cd ${WRKSRC}; ./manpage; cp shellcheck.1 ${FILESDIR}/
# (and update md5)
post-patch:
	@[ `md5 < ${WRKSRC}/shellcheck.1.md` == b28cc3fbcd8c4978a8f0253955252fa5 ] || \
	    (echo "*** manpage changed; regenerate ${FILESDIR}/shellcheck.1"; sleep 3)

post-install:
	${INSTALL_DATA} ${FILESDIR}/shellcheck.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
