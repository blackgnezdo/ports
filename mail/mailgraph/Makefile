# $OpenBSD: Makefile,v 1.13 2019/06/03 16:06:52 sthen Exp $

COMMENT=	RRDtool frontend for Postfix statistics

DISTNAME=	mailgraph-1.14
REVISION=	1
CATEGORIES=	net mail

MASTER_SITES=	${HOMEPAGE}/pub/ \
		${HOMEPAGE}/pub/old/

HOMEPAGE=	http://mailgraph.schweikert.ch

MAINTAINER=     Stuart Henderson <sthen@openbsd.org>

# GPL
PERMIT_PACKAGE=	Yes

RUN_DEPENDS=	net/rrdtool \
		devel/p5-File-Tail

NO_TEST=	Yes
NO_BUILD=	Yes

LIBDIR=		lib/mailgraph

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.pl ${PREFIX}/bin/mailgraph
	${INSTALL_DATA_DIR} ${PREFIX}/${LIBDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/mailgraph.cgi ${PREFIX}/lib/mailgraph
	${INSTALL_DATA} ${WRKSRC}/mailgraph.css ${PREFIX}/lib/mailgraph

.include <bsd.port.mk>
