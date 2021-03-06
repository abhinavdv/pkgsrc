# $NetBSD: Makefile,v 1.9 2018/05/23 14:12:13 triaxx Exp $

DISTNAME=	libexecinfo-1.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_FREEBSD}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freshports.org/devel/libexecinfo
COMMENT=	BSD Licensed clone of backtrace facility found in GNU libc
LICENSE=	2-clause-bsd

CFLAGS.Linux+=	-D_GNU_SOURCE # Dl_info internals
CFLAGS.Linux+=	-Wno-unused-result # write(2) is declared specially
LIBS+=		-lm
LIBS.Linux+=	-ldl

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	include lib

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile --tag=CC ${CC} ${CFLAGS} -c execinfo.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile --tag=CC ${CC} ${CFLAGS} -c stacktraverse.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link --tag=CC ${CC} ${LDFLAGS} ${LIBS}	\
		-o libexecinfo.la execinfo.lo stacktraverse.lo				\
		-version-info 1:0:0 -rpath ${PREFIX}/lib

do-install:
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB}	\
		-c libexecinfo.la ${DESTDIR}${PREFIX}/lib/libexecinfo.la
	cd ${WRKSRC} && ${INSTALL_DATA} execinfo.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
