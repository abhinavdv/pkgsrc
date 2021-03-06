# $NetBSD: Makefile,v 1.4 2018/10/24 10:06:40 adam Exp $

DISTNAME=	repmgr-4.2.0
PKGNAME=	postgresql${PGSQL_VERSION}-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	https://repmgr.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://repmgr.org/
COMMENT=	Replication Manager for PostgreSQL clusters
LICENSE=	gnu-gpl-v3

DEPENDS+=	postgresql${PGSQL_VERSION}-server>=0:../../databases/postgresql${PGSQL_VERSION}-server

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKG_SYSCONFSUBDIR=	postgresql

BUILD_DEFS+=	PGUSER PGGROUP PGHOME
FILES_SUBST+=	PGUSER=${PGUSER} PGGROUP=${PGGROUP} PGHOME=${PGHOME}

DOCDIR=		share/doc/repmgr
EGDIR=		share/examples/repmgr
SMF_NAME=	postgresql-repmgr

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

CONF_FILES_PERMS+=	${EGDIR}/repmgr.conf.sample \
			${PKG_SYSCONFDIR}/repmgr.conf \
			${REAL_ROOT_USER} ${PGGROUP} 0640

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md \
	    ${DESTDIR}${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/repmgr.conf.sample \
	    ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
