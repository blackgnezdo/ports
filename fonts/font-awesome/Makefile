# $OpenBSD: Makefile,v 1.16 2019/09/20 14:54:12 rsadowski Exp $

COMMENT=	full suite pictographic icons

VERSION =	5.11.1
PKGNAME =	font-awesome-${VERSION}
DISTNAME =	fontawesome-free-${VERSION}-desktop

CATEGORIES=	fonts

HOMEPAGE =	https://fontawesome.com

MAINTAINER =	Rafael Sadowski <rsadowski@openbsd.org>

MASTER_SITES =	https://github.com/FortAwesome/Font-Awesome/releases/download/${VERSION}/
EXTRACT_SUFX =	.zip

# SIL OFL 1.1
PERMIT_PACKAGE=	Yes

MODULES =	font
FONTTYPES =	otf

NO_BUILD =	Yes
NO_TEST =	Yes

FONTS_DIR=	${PREFIX}/share/fonts/font-awesome
DOCDIR =	${PREFIX}/share/doc/font-awesome

do-install:
	${INSTALL_DATA_DIR} ${FONTS_DIR}
	${INSTALL_DATA} ${WRKSRC}/otfs/*.otf ${FONTS_DIR}
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKDIST}/*.txt ${DOCDIR}

.include <bsd.port.mk>
