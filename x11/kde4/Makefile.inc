# $OpenBSD: Makefile.inc,v 1.21 2019/07/12 20:51:14 sthen Exp $

CATEGORIES ?=		x11
MODULES +=		x11/kde4

MASTER_SITES ?=		${MASTER_SITE_KDE:=stable/${MODKDE4_VERSION}/src/}
DIST_SUBDIR =		kde
MAINTAINER ?=		KDE porting team <openbsd-kde@googlegroups.com>

.if defined(MODKDE4_USE) && ${MODKDE4_USE:Mgames}
HOMEPAGE ?=		http://games.kde.org/game.php?game=${DISTNAME:C/-[0-9].*//}
.else
HOMEPAGE ?=		https://projects.kde.org/${DISTNAME:C/-[0-9].*//}
.endif

# KDE SC is mostly GPL, or LGPL/BSDL for the central libraries
PERMIT_PACKAGE =		Yes

# Do not rely on devel/cmake here: additional modules that are
# set up in ports may have, say, lang/python before devel/cmake,
# thus making lang/python evaluating first. And when lang/python
# sees empty CONFIGURE_STYLE, it forces that this is Python
# module port, and breaks build.
CONFIGURE_STYLE =	cmake

MODKDE4_LIB_LINKS =	Yes

MIN_AKONADI_VERSION =	1.13.0
MIN_SOPRANO_VERSION =	2.9.4
MIN_ACTIVITIES_VERSION =4.13.3
MIN_WORKSPACE_VERSION =	4.11.13

# Only needed for l10n
MODKDE4_FIX_GETTEXT ?=  No
