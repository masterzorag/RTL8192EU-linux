### Get sources and move into linux-4.11 branch
```sh
git clone https://github.com/masterzorag/RTL8192EU-linux.git
git branch linux-4.11

make
make install
```

### Build out-of-tree
```sh
make KSRC=/Storage/linux-4.x.y
make KSRC=/Storage/linux-4.x.y install
```
