# Maintainer: Ariel Armijo <arielarmijo@yahoo.es>
pkgname=dwm
pkgver=6.3
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('x86_64')
license=('MIT')
depends=('libx11' 'libxinerama' 'libxft-bgra' 'dmenu')
provides=('dwm')
conflicts=('dwm')
source=(file://$pkgname-$pkgver.tar.gz
		dwm-patches.diff
		dwm.desktop
		config.h)
sha256sums=(badaa028529b1fba1fd7f9a84f3b64f31190466c858011b53e2f7b70c6a3078d
            SKIP
            925c0a8b2026f0dd6450517898db74e628dda7518b7908b9dbcab6714a8407d5
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
