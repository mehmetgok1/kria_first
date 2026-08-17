SUMMARY = "Recipe for  build an external udmabuf Linux kernel module"
SECTION = "PETALINUX/modules"
LICENSE = "CLOSED"


inherit module

INHIBIT_PACKAGE_STRIP = "1"

SRC_URI = "file://Makefile \
           file://u-dma-buf.c \
           file://u-dma-buf-ioctl.h \
          "

S = "${WORKDIR}"

# The inherit of module.bbclass will automatically name module packages with
# "kernel-module-" prefix as required by the oe-core build environment.
