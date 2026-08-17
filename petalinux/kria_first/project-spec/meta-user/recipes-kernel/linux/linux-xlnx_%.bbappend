FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI:append = " file://bsp.cfg"
KERNEL_FEATURES:append = " bsp.cfg"
SRC_URI += "file://user_2026-08-14-21-46-00.cfg \
            file://user_2026-08-15-01-43-00.cfg \
            "

