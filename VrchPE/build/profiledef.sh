#!/usr/bin/env bash
# shellcheck disable=SC2034

iso_name="vrch-linux"
iso_label="VRCH_$(date +%Y%m)"
iso_publisher="Vrch Linux>"
iso_application="Vrch Linux"
iso_version="$(date +%Y.%m.%d)"
install_dir="vrch"
bootmodes=('bios.syslinux.mbr' 'bios.syslinux.eltorito' 'uefi-x64.systemd-boot.esp' 'uefi-x64.systemd-boot.eltorito')
arch="x86_64"
pacman_conf="pacman.conf"
airootfs_image_type="squashfs"
airootfs_image_tool_options=('-comp' 'xz' '-Xbcj' 'x86' '-b' '1M' '-Xdict-size' '1M')
file_permissions=(
  ["/etc/shadow"]="0:0:400"
  ["/root/.config/polybar/launch.sh"]="0:0:755"
)
