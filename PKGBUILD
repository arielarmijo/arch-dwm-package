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
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
		config.h
		dwm.desktop
		attachbelow.diff
		autostart.diff
		center.diff
		pertag.diff
		savefloats.diff
#		systray.diff
		statuscolors-systray.diff
		sticky.diff
		wtitlebg.diff
)

sha256sums=('97902e2e007aaeaa3c6e3bed1f81785b817b7413947f1db1d3b62b8da4cd110e'
			SKIP
			'28c8d5bcaca83b7e945d6f52e91d3941f6d67e489d8a8484cc20546a8149bbf4'
			'acd334a6108cb329e91d7fee93d798cd2bba9feb079a912ec84234980c8ef2dd'
			'1e13ddcc243c749c4b5fe31afd41b57ecef217206e695e7aad0a5b805b21d669'
			'203061d727168196dae6af9b4c347868eef538100bfa83d77bbd32b85befbe2f'
			'11738a343ce3e5092b7eacf08f6f5c638f14fba2b2f8fe82d9b8e1864c949e22'
			'88a08be82939fc57ab1c999a701a53e97644a02a8e7f269f986a507b8c62e340'
#			'2d1047ff0c5863f4188140ca1f405a558e94611e4eff2ff0fb5f70e32fddd44a'
			'9d3557b9963ab41262704f7d76f87f2f6e5b9616893ad906a79c8fd6c6316dc4'
			'4fb0a5aeba90532a26fb9d1f199434cebe288f41c78120022d38eccfcab2f736'
			'1a5ddf322a82e41605db294ba91dc51f680dca5cd7a4cae203d8aaa4da5e5c6b'
)

prepare() {
  cd "$srcdir/$pkgname-$pkgver"
# patch --strip=1 --input="${srcdir}/systray.diff"
  patch --strip=1 --input="${srcdir}/statuscolors-systray.diff"
  patch --strip=1 --input="${srcdir}/pertag.diff"
  patch --strip=1 --input="${srcdir}/sticky.diff"
  patch --strip=1 --input="${srcdir}/attachbelow.diff"
  patch --strip=1 --input="${srcdir}/savefloats.diff"
  patch --strip=1 --input="${srcdir}/center.diff"
  patch --strip=1 --input="${srcdir}/autostart.diff"
  patch --strip=1 --input="${srcdir}/wtitlebg.diff"
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
