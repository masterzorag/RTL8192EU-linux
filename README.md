# RTL8192EU-linux
Realtek 8192EU Linux Driver

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)
[![master](https://img.shields.io/badge/current-v4.4.1-aa11ff.svg)](https://github.com/masterzorag/RTL8192EU-linux/releases)

Testing hardware dongle is [TP-Link TL-WN823N](http://www.tp-link.com/us/products/details/cat-5520_TL-WN823N.html)
```sh
# lsusb -s 1:3
Bus 001 Device 003: ID 2357:0109
```
```sh
# modinfo 8192eu
filename:       /lib/modules/4.4.65/kernel/drivers/net/wireless/8192eu.ko
version:        v4.4.1_17696.20160509_BTCOEX20160412-0042
author:         Realtek Semiconductor Corp.
description:    Realtek Wireless Lan Driver
license:        GPL
srcversion:     16E573E327DA9985B40B933
alias:          usb:v2357p0109d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v2357p0108d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v2357p0107d*dc*dsc*dp*ic*isc*ip*in*
alias:          usb:v0BDAp818Cd*dc*dsc*dp*icFFiscFFipFFin*
alias:          usb:v0BDAp818Bd*dc*dsc*dp*icFFiscFFipFFin*
depends:        cfg80211
vermagic:       4.4.65 SMP mod_unload modversions
```
* [linux-4.4.y is the longterm supported](https://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable.git/log/?h=linux-4.4.y), no modifications needed
* stable-linux-4.7.10 compiles fine, with little [patching](https://github.com/masterzorag/RTL8192EU-linux/tree/linux-4.7) :syringe:  
[This commit](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=1d76250bd34af86c6498fc51e50cab3bfbbeceaa) introduces [cfg80211_scan_info](http://lxr.free-electrons.com/ident?v=4.8;i=cfg80211_scan_info) and breaks compilation with linux >=4.8  

* Monitor mode is [supported](https://github.com/masterzorag/RTL8192EU-linux/blob/linux-4.11/Makefile#L65) and [working](https://github.com/CGarces/RTL8192EU-linux/issues/1#issuecomment-300720336)
