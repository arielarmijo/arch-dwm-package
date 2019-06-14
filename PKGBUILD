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
source=(
		http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
		config.h
		dwm.desktop
		attachbelow.diff
		savefloats.diff
		pertag.diff
		systray.diff
		autostart.diff
		sticky.diff
)

sha256sums=(
			'97902e2e007aaeaa3c6e3bed1f81785b817b7413947f1db1d3b62b8da4cd110e'
			SKIP
			'28c8d5bcaca83b7e945d6f52e91d3941f6d67e489d8a8484cc20546a8149bbf4'
			'19f9f86a5edd19c627b9d5242002783c242648255b4b3aa7afaa55dbc1d1fc10'
			'88a08be82939fc57ab1c999a701a53e97644a02a8e7f269f986a507b8c62e340'
			'11738a343ce3e5092b7eacf08f6f5c638f14fba2b2f8fe82d9b8e1864c949e22'
			'2d1047ff0c5863f4188140ca1f405a558e94611e4eff2ff0fb5f70e32fddd44a'
			'dad8ddab41eb21a10cb9e667e124c29e911f147a2623c851b97a82e4e6f8330a'
			'4fb0a5aeba90532a26fb9d1f199434cebe288f41c78120022d38eccfcab2f736'
)

prepare() {
  cd "$srcdir/$pkgname-$pkgver"
  patch --strip=1 --input="${srcdir}/attachbelow.diff"
  patch --strip=1 --input="${srcdir}/savefloats.diff"
  patch --strip=1 --input="${srcdir}/pertag.diff"
  patch --strip=1 --input="${srcdir}/systray.diff"
  patch --strip=1 --input="${srcdir}/autostart.diff"
  patch --strip=1 --input="${srcdir}/sticky.diff"
  cp "$srcdir/config.h" config.h
}

build() {
  cd "$srcdir/$pkgname-$pkgver"
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11 FREETYPEINC=/usr/include/freetype2
}

package() {
  cd "$srcdir/$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
  install -m644 -D LICENSE "$pkgdir/usr/share/licenses/$pkgname/LICENSE"
  install -m644 -D README "$pkgdir/usr/share/doc/$pkgname/README"
  install -m644 -D "$srcdir/dwm.desktop" "$pkgdir/usr/share/xsessions/dwm.desktop"
}
