# $NetBSD: Makefile,v 1.8 2018/05/13 11:56:22 markd Exp $

DISTNAME=	collection-luatex
PKGNAME=	texlive-${DISTNAME}-2018pre1
CATEGORIES=	meta-pkgs
MASTER_SITES=	# empty
TEXLIVE_REV=	47011

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	LuaTeX packages

DEPENDS+=	texlive-collection-basic-[0-9]*:../../meta-pkgs/texlive-collection-basic

# depend auto-pst-pdf-lua
# depend checkcites
# depend chickenize
# depend combofont
# depend cstypo
DEPENDS+=	tex-ctablestack-[0-9]*:../../print/tex-ctablestack
# depend enigma
# depend fontloader-luaotfload
# depend interpreter
# depend lua-visual-debug
# depend lua2dox
DEPENDS+=	tex-luacode-[0-9]*:../../print/tex-luacode
# depend luahyphenrules
# depend luaindex
# depend luainputenc
# depend luaintro
# depend lualatex-doc
# depend lualatex-math
DEPENDS+=	tex-lualibs-[0-9]*:../../devel/tex-lualibs
# depend luamplib
DEPENDS+=	tex-luaotfload-[0-9]*:../../fonts/tex-luaotfload
# depend luapackageloader
DEPENDS+=	tex-luatex85-[0-9]*:../../print/tex-luatex85
DEPENDS+=	tex-luatexbase-[0-9]*:../../devel/tex-luatexbase
# depend luatexko
# depend luatextra
# depend luaxml
# depend nodetree
# depend odsfile
# depend placeat
# depend plantuml
# depend selnolig
# depend spelling
# depend typewriter

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
