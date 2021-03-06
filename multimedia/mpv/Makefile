# $OpenBSD: Makefile,v 1.50 2019/08/19 06:04:22 ajacoutot Exp $

COMMENT =		movie player based on MPlayer/mplayer2

GH_ACCOUNT =		mpv-player
GH_PROJECT =		mpv
GH_TAGNAME =		v0.29.1

REVISION =		2

SHARED_LIBS +=	mpv                       0.0 # 1.101

CATEGORIES =		multimedia x11

HOMEPAGE =		https://mpv.io/

WAF =			${WRKSRC}/waf-2.0.14
MASTER_SITES0 =		https://waf.io/
DISTFILES =		${DISTNAME}{${GH_TAGNAME}}${EXTRACT_SUFX} ${WAF:T}:0
EXTRACT_ONLY =		${DISTNAME}${EXTRACT_SUFX}

# GPLv2+
PERMIT_PACKAGE =	Yes

WANTLIB += EGL GL SDL2 X11 X11-xcb Xau Xdamage Xdmcp Xext Xfixes
WANTLIB += Xinerama Xrandr Xrender Xss Xv Xxf86vm ass avcodec
WANTLIB += avdevice avfilter avformat avresample avutil bluray
WANTLIB += c cdio cdio_cdda cdio_paranoia drm dvdnav dvdread expat
WANTLIB += fontconfig freetype fribidi gbm iconv jpeg lcms2 m
WANTLIB += postproc pthread sndio swresample swscale v4l2
WANTLIB += v4lconvert xcb xcb-dri2 xcb-glx z ${MODLUA_WANTLIB}

MODULES =		lang/lua \
			lang/python

COMPILER =		base-clang ports-gcc
COMPILER_LANGS =	c

BUILD_DEPENDS =		audio/ladspa \
			textproc/py-docutils

LIB_DEPENDS =		audio/libcdio \
			audio/libcdio-paranoia \
			converters/libiconv \
			devel/libdvdread \
			devel/sdl2 \
			graphics/ffmpeg>=4.1.1 \
			graphics/jpeg \
			graphics/lcms2 \
			multimedia/libass \
			multimedia/libbluray \
			multimedia/libdvdnav \
			multimedia/libv4l

MODPY_RUNDEP =		No
RUN_DEPENDS =		devel/desktop-file-utils \
			x11/gtk+3,-guic

SEPARATE_BUILD =	Yes
CONFIGURE_ARGS =	--confloaddir=${SYSCONFDIR}/mpv \
			--confdir=${LOCALBASE}/share/examples/mpv \
			--mandir=${LOCALBASE}/man \
			--docdir=${LOCALBASE}/share/examples/mpv \
			--zshdir=${LOCALBASE}/share/zsh/vendor-completions \
			--enable-cdda \
			--enable-dvdnav \
			--enable-dvdread \
			--enable-libmpv-shared \
			--enable-sndio \
			--enable-sdl2 \
			--enable-tv \
			--enable-zsh-comp \
			--disable-alsa \
			--disable-caca \
			--disable-cuda-hwaccel \
			--disable-egl-drm \
			--disable-gl-wayland \
			--disable-jack \
			--disable-libarchive \
			--disable-rubberband \
			--disable-oss-audio \
			--disable-openal \
			--disable-optimize \
			--disable-pulse \
			--disable-rsound \
			--disable-libsmbclient \
			--disable-uchardet \
			--disable-vaapi \
			--disable-vaapi-drm \
			--disable-vaapi-glx \
			--disable-vaapi-x-egl \
			--disable-vaapi-x11 \
			--disable-vaapi-wayland \
			--disable-vapoursynth \
			--disable-vapoursynth-lazy \
			--disable-vdpau \
			--disable-vdpau-gl-x11 \
			--disable-videotoolbox-gl \
			--disable-vulkan \
			--disable-wayland

MAKE_ENV +=		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
MAKE_ENV +=		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"
MAKE_FLAGS =		-o "${WRKBUILD}" -t "${WRKSRC}" --destdir="${DESTDIR}"

NO_TEST =		Yes

.if ${MACHINE_ARCH} == "i386"
CFLAGS +=		-march=i586
.endif

DO_WAF =		cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MODPY_BIN} \
				${WAF} ${MAKE_FLAGS}

post-patch:
	cp ${DISTDIR}/${WAF:T} ${WAF}

do-configure:
	sed -i -e "s,LMAJ,${LIBmpv_VERSION:R},g" \
		-e "s,LMIN,${LIBmpv_VERSION:E},g" \
			${WRKSRC}/libmpv/client.h
	${DO_WAF} configure ${CONFIGURE_ARGS}

do-build:
	${DO_WAF} build -v

do-install:
	${DO_WAF} install
	${INSTALL_DATA} ${WRKDIST}/TOOLS/mpv_identify.sh \
		${WRKDIST}/TOOLS/umpv ${PREFIX}/share/examples/mpv
	${MODPY_BIN_ADJ} ${PREFIX}/share/examples/mpv/umpv
	sed -Ei 's,(/dev/dvd|/dev/cdrom),/dev/rcd0c,g' ${PREFIX}/man/man1/mpv.1

.include <bsd.port.mk>
