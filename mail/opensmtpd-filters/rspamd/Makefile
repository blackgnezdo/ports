# $OpenBSD: Makefile,v 1.3 2019/09/29 09:52:06 gilles Exp $

COMMENT =	rspamd integration to the OpenSMTPD daemon

V =		0.1.3
FILTER_NAME =	rspamd
DISTNAME =	filter-rspamd-${V}

CATEGORIES =	mail
HOMEPAGE =	https://github.com/poolpOrg/filter-rspamd/

MAINTAINER =	Gilles Chehade <gilles@poolp.org>

MASTER_SITES =	https://github.com/poolpOrg/filter-rspamd/releases/download/${V}/

# ISC
PERMIT_PACKAGE =	Yes

WANTLIB =	c pthread
MODULES =	lang/go
NO_TEST =	Yes

ALL_TARGET =	filter-rspamd

.include <bsd.port.mk>
