# $OpenBSD: Makefile,v 1.1.1.1 2019/05/09 11:49:00 semarie Exp $

MODPY_EGG_VERSION =	5.2.0
TRYTON_MODULE =		stock_supply

TRYTON_DEPENDS +=	account \
			party \
			product \
			purchase \
			purchase_request \
			stock

RUN_DEPENDS +=		databases/py-sql${MODPY_FLAVOR}

.include <bsd.port.mk>
