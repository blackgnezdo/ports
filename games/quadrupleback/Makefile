# $OpenBSD: Makefile,v 1.10 2019/07/12 20:46:23 sthen Exp $

COMMENT =		clone of Doubleback, an intruder circling game

DISTNAME =		quadrupleback-0.1.0
REVISION =		3

CATEGORIES =		games

HOMEPAGE =		http://sarrazip.com/dev/quadrupleback.html

# GPLv2+
PERMIT_PACKAGE =	Yes

WANTLIB += FLAC SDL SDL_gfx SDL_image SDL_mixer c flatzebra-0.1 iconv
WANTLIB += jpeg m mikmod ogg png pthread smpeg sndio ${COMPILER_LIBCXX} tiff
WANTLIB += usbhid vorbis vorbisfile webp z

COMPILER =		base-clang ports-gcc base-gcc

MASTER_SITES =		http://sarrazip.com/dev/

RUN_DEPENDS =		devel/desktop-file-utils
LIB_DEPENDS =		converters/libiconv \
			devel/flatzebra \
			devel/sdl-gfx

FAKE_FLAGS =		docdir=${PREFIX}/share/doc/quadrupleback

CONFIGURE_STYLE =	gnu
CONFIGURE_ENV =		CPPFLAGS="-I${LOCALBASE}/include"

.include <bsd.port.mk>
