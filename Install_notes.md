### Get sources and move into linux-4.11 branch
```sh
git clone https://github.com/masterzorag/RTL8192EU-linux.git
git checkout linux-4.11

make
make install
```

### Get kernel source, test building out-of-tree
```sh
* unpack kernel sources
# cd /Storage
# tar xf linux-4.x
# cd linux-4.x

* import running config
# zcat /proc/config.gz > .config
# make silentoldconfig
* do not build: just prepare
# make modules_prepare

* build Realtek driver, out-of-tree
# make KSRC=/Storage/linux-4.x
```
