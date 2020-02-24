# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Dag Odenhall <dag.odenhall@gmail.com>
# Contributor: Grigorios Bouzakis <grbzks@gmail.com>

pkgname=dwm
pkgver=6.2
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama' 'libxft' 'freetype2' 'dmenu' 'rxvt-unicode')
source=(config.h
		http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
		dwm.desktop
		dwm-patches.diff
)

sha256sums=(SKIP
			97902e2e007aaeaa3c6e3bed1f81785b817b7413947f1db1d3b62b8da4cd110e
			28c8d5bcaca83b7e945d6f52e91d3941f6d67e489d8a8484cc20546a8149bbf4
			SKIP
)

prepare() {
  cd "$srcdir/$pkgname-$pkgver"
  patch --strip=1 --input="${srcdir}/dwm-patches.diff"
  cp "$srcdir/config.h" config.h
}

build() {
  cd "$srcdir/$pkgname-$pkgver"
  make
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
  install -m644 -D LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -m644 -D README "$pkgdir/usr/share/doc/$pkgname/README"
  install -m644 -D "$srcdir/dwm.desktop" "$pkgdir/usr/share/xsessions/dwm.desktop"
}
