# $OpenBSD: Makefile,v 1.69 2019/09/26 21:59:30 sthen Exp $

MULTI_PACKAGES=	-utils -main -perl -php -python

COMMENT-main=	GIS CGI server
COMMENT-utils=	mapserver utilities
COMMENT-php=	PHP Mapscript extension
COMMENT-perl=	Perl Mapscript binding
COMMENT-python=	Python Mapscript binding

V =		7.4.2
DISTNAME=	mapserver-${V}
PKGNAME-main=	${DISTNAME}
PKGNAME-utils=	mapserver-utils-${V}
PKGNAME-php=	php-mapscript-${V}
PKGNAME-perl=	p5-mapscript-${V}
PKGNAME-python=	py3-mapscript-${V}

REVISION-php=	0

SHARED_LIBS +=	mapserver 4.0

CATEGORIES=	geo www

HOMEPAGE=	http://www.mapserver.org/

# MIT
PERMIT_PACKAGE=	Yes

MAINTAINER=	Landry Breuil <landry@openbsd.org>

MASTER_SITES=	http://download.osgeo.org/mapserver/

COMPILER =		base-clang ports-gcc base-gcc

MODULES=	lang/php lang/python devel/cmake
MODPHP_RUNDEP=	No
MODPY_SETUPTOOLS=	Yes
MODPY_EGG_VERSION=	${V}
MODPY_VERSION=	${MODPY_DEFAULT_VERSION_3}
CONFIGURE_STYLE=cmake

NO_TEST =	Yes

RUN_DEPENDS-main =	www/spawn-fcgi
RUN_DEPENDS-perl =	# empty
RUN_DEPENDS-php =	${MODPHP_RUN_DEPENDS}
RUN_DEPENDS-python =	${MODPY_RUN_DEPENDS}
RUN_DEPENDS-utils =	# empty

BUILD_DEPENDS +=	devel/swig databases/postgresql,-server

LIB_DEPENDS=	devel/proj \
		devel/fribidi \
		devel/harfbuzz \
		devel/protobuf-c \
		graphics/cairo \
		geo/gdal \
		geo/geos \
		graphics/giflib
LIB_DEPENDS-main=	${LIB_DEPENDS} \
		www/fcgi

WANTLIB += curl freetype jpeg m png pq xml2 z proj
WANTLIB += gdal geos_c cairo fribidi gif harfbuzz protobuf-c

WANTLIB-main =	${WANTLIB} c fcgi pthread ${COMPILER_LIBCXX}
WANTLIB-utils =	${WANTLIB} c
WANTLIB-php =	${WANTLIB}
WANTLIB-perl =	${WANTLIB} c perl
WANTLIB-python =	${WANTLIB} ${MODPY_WANTLIB}

CONFIGURE_ARGS +=	-DPYTHON_EXECUTABLE=${MODPY_BIN} \
			-DWITH_CLIENT_WFS=1 \
			-DWITH_CLIENT_WMS=1 \
			-DWITH_CURL=1 \
			-DWITH_KML=1 \
			-DWITH_SOS=1 \
			-DWITH_PYTHON=1 \
			-DWITH_PERL=1

# https://github.com/mapserver/mapserver/issues/5766
# mapserver builds cpp and c files so both are needed..
CFLAGS+=-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1
CXXFLAGS+=-DACCEPT_USE_OF_DEPRECATED_PROJ_API_H=1

CONFIGURE_ARGS += -DPHP_CONFIG_EXECUTABLE=${LOCALBASE}/bin/php-config-${MODPHP_VERSION} \
			-DWITH_PHPNG=1
PREFIX-main=	${VARBASE}/www

SUBST_VARS+=	PREFIX-main VARBASE

post-extract:
	rm -f ${WRKSRC}/cmake/Find{Freetype,PostgreSQL,ICONV}.cmake

post-install:
	${INSTALL_DATA_DIR} ${WRKINST}/${PREFIX-main}/cgi-bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/php-${MODPHP_VERSION}

	${INSTALL_PROGRAM} ${PREFIX}/bin/mapserv ${WRKINST}/${PREFIX-main}/cgi-bin

	echo "; Enable Mapscript extension module\nextension=php_mapscriptng.so" \
		> ${PREFIX}/share/examples/php-${MODPHP_VERSION}/mapscriptng.ini

.for l in perl
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mapserver/${l}
	${INSTALL_DATA}	${WRKSRC}/mapscript/${l}/examples/* \
		${PREFIX}/share/examples/mapserver/${l}
.endfor

.include <bsd.port.mk>
