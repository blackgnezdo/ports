# $OpenBSD: Makefile,v 1.9 2019/07/12 20:46:15 sthen Exp $

COMMENT=	clone of the Mastermind game

DISTNAME=	braincurses-0.5b
REVISION =	3
CATEGORIES=	games
HOMEPAGE=	http://sourceforge.net/projects/braincurses/

MAINTAINER=	Christian Weisgerber <naddy@openbsd.org>

# GPLv2
PERMIT_PACKAGE=	Yes

MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=braincurses/}

WANTLIB=	c m curses ${COMPILER_LIBCXX}

COMPILER =		base-clang ports-gcc base-gcc

do-build:
	cd ${WRKBUILD} && ${CXX} ${CXXFLAGS} -o braincurses \
	    curses/windows.cpp braincurses.cpp -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/braincurses ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/braincurses
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/braincurses

NO_TEST=	Yes

.include <bsd.port.mk>
