# $OpenBSD: Makefile,v 1.22 2017/09/15 15:37:17 naddy Exp $

COMMENT=	GkrellM2 plugin that shows Internet time

V=		1.0.1
DISTNAME=	gkrellmitime-${V}
REVISION=	18
CATEGORIES=	net

EXTRA_WANTLIB=	gthread-2.0

ALL_TARGET=	gkrellm_itime.so
PLUGIN=		${WRKSRC}/gkrellm_itime.so

.include <bsd.port.mk>
