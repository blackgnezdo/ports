# $OpenBSD: Makefile,v 1.56 2019/07/12 20:48:24 sthen Exp $

COMMENT=	CVS repository synchronization utility

PKGNAME=	cvsync-0.25.0pre0
DISTNAME=	cvsync-0.24.19
REVISION=	4
CATEGORIES=	net
HOMEPAGE=	http://www.cvsync.org/

# BSD
PERMIT_PACKAGE=	Yes

WANTLIB=	c pthread z

MASTER_SITES=	http://www.cvsync.org/dist/ \
		ftp://ftp.allbsd.org/pub/cvsync/

USE_GMAKE=	Yes
MAKE_ENV=	CVSYNC_DEFAULT_CONFIG="${SYSCONFDIR}/cvsync.conf" \
		CVSYNCD_DEFAULT_CONFIG="${SYSCONFDIR}/cvsyncd.conf" \
		INSTALL_MAN_OPTS="-o ${MANOWN} -g ${MANGRP} -m ${MANMODE}" \
		INSTALL_BIN_OPTS="-o ${BINOWN} -g ${BINGRP} -m ${BINMODE} ${INSTALL_STRIP}" \
		INSTALL=install

NO_TEST=	Yes
EXAMPLESDIR=	${PREFIX}/share/examples/cvsync

post-install:
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${FILESDIR}/*.conf ${EXAMPLESDIR}

.include <bsd.port.mk>
