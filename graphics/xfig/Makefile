# $OpenBSD: Makefile,v 1.57 2019/07/12 20:47:12 sthen Exp $

COMMENT=	CAD drawing program for X11

# print/transfig usually needs to be in-sync
DISTNAME=	xfig-3.2.6
REVISION=	1
CATEGORIES=	graphics x11

HOMEPAGE=	http://mcj.sourceforge.net/

# MIT
PERMIT_PACKAGE=	Yes

WANTLIB += X11 Xaw3d Xpm Xt c jpeg m png

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mcj/}
EXTRACT_SUFX=	.tar.xz

LIB_DEPENDS=	graphics/jpeg \
		graphics/png \
		x11/Xaw3d>=1.6
RUN_DEPENDS=	print/transfig \
		textproc/xpdf \
		devel/desktop-file-utils

CONFIGURE_STYLE= gnu
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS+=	--with-applicationsdir=${PREFIX}/share/applications \
			--with-icondir=${PREFIX}/share/pixmaps \
			--docdir=${PREFIX}/share/doc/xfig \
			--with-appdefaultdir=${PREFIX}/lib/X11/app-defaults \
			--datarootdir=${PREFIX}/lib/X11

USE_GROFF=	Yes

.include <bsd.port.mk>
