# Maintainer: Ariel Armijo <arielarmijo@yahoo.es>
pkgname=dwm
pkgver=6.4
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('x86_64')
license=('MIT')
depends=('libx11' 'libxinerama' 'libxft' 'dmenu' 'rxvt-unicode')
provides=('dwm')
conflicts=('dwm')
source=()

prepare() {
  cp ../patched-dwm/* .
  cp ../config.h config.h
}

build() {
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  make PREFIX=/usr DESTDIR="$pkgdir" install
  install -m644 -D LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -m644 -D README "$pkgdir/usr/share/doc/$pkgname/README"
  install -m644 -D ../dwm.desktop "$pkgdir/usr/share/xsessions/dwm.desktop"
}
