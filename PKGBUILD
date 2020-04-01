pkgname=dwm
pkgver=6.2
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('x86_64')
license=('MIT')
depends=('libx11' 'libxinerama' 'libxft' 'freetype2' 'dmenu' 'rxvt-unicode')
provides=('dwm')
conflicts=('dwm')
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
		config.h
		dwm.desktop
		dwm-patches.diff)

sha256sums=(97902e2e007aaeaa3c6e3bed1f81785b817b7413947f1db1d3b62b8da4cd110e
			SKIP
			SKIP
			SKIP)

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
