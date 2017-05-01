# RTL8192EU-linux
Realtek 8192EU Linux Driver

[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)


Testing hardware dongle is [TP-Link TL-WN823N](http://www.tp-link.com/us/products/details/cat-5520_TL-WN823N.html)

* linux-4.4.65 is the longterm, no modifications needed  
[This commit](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/commit/?id=1d76250bd34af86c6498fc51e50cab3bfbbeceaa) introduces [cfg80211_scan_info](http://lxr.free-electrons.com/ident?v=4.8;i=cfg80211_scan_info) and breaks compilation with linux >=4.8.
* stable-linux-4.7.10 compiles fine, with little patching :syringe:
