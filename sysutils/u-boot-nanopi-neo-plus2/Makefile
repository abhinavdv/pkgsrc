# $NetBSD: Makefile,v 1.6 2018/12/31 15:06:46 jmcneill Exp $

UBOOT_TARGET=		nanopi-neo-plus2
UBOOT_CONFIG=		nanopi_neo_plus2_defconfig
UBOOT_BIN=		u-boot-sunxi-with-spl.bin

PKGREVISION=		1

# Switch to EL1 before booting kernel (required for 32-bit support)
#PKG_DEFAULT_OPTIONS+=	el1

post-extract:
	${CP} ${PREFIX}/share/arm-trusted-firmware/sun50iw1p1/bl31.bin ${WRKSRC}

post-build:
	${CAT} ${WRKSRC}/spl/sunxi-spl.bin ${WRKSRC}/u-boot.itb > ${WRKSRC}/u-boot-sunxi-with-spl.bin

.include "../../sysutils/arm-trusted-firmware-sun50iw1p1/buildlink3.mk"
.include "../../sysutils/u-boot/u-boot-arm64.mk"
