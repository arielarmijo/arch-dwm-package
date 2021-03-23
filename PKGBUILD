# Maintainer: Ariel Armijo <arielarmijo@yahoo.es>
pkgname=dwm
pkgver=6.2
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('x86_64')
license=('MIT')
depends=('libx11' 'libxinerama' 'libxft' 'dmenu' 'rxvt-unicode')
provides=('dwm')
conflicts=('dwm')
source=(file://$pkgname-$pkgver.tar.gz
		dwm-patches.diff
		dwm.desktop
		config.h)

sha256sums=(6d2b6315f606d171b0ee437b163682a964133b43bab2446afb405f08f655f5b3
			20ccee2b60dff5be9b1f80b30796d6116e43df0a339647c71efbdab87054ba04
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
