# dwm
PKGBUILD with custom configuration and patches files for dwm-6.2.

![alt text](https://github.com/cochayuyo/dwm/blob/master/screenshot.png)


# Install
```
git clone https://github.com/cochayuyo/dwm.git
cd dwm
makepkg -sci
```
# Patches

- [actualfullscreen](https://dwm.suckless.org/patches/actualfullscreen/)
- [attachbelow](https://dwm.suckless.org/patches/attachbelow/)
- [center floating windows](https://github.com/ericpruitt/edge/blob/master/patches/dwm-10-center-floating-windows.diff)
- [cfacts](https://dwm.suckless.org/patches/cfacts/)
- [stacker](https://dwm.suckless.org/patches/stacker/)
- [pertag](https://dwm.suckless.org/patches/pertag/)
- [resizecornes](https://dwm.suckless.org/patches/resizecorners/)
- [save floats](https://dwm.suckless.org/patches/save_floats/)
- [scratchpad](https://dwm.suckless.org/patches/scratchpad/)
- [status2d](https://dwm.suckless.org/patches/status2d/)
- [statusallmons](https://dwm.suckless.org/patches/statusallmons/)
- [sticky](https://dwm.suckless.org/patches/sticky/)
- [systray](https://dwm.suckless.org/patches/systray/)
- [tagintostack](https://dwm.suckless.org/patches/tagintostack/)
- [titlecolor](https://dwm.suckless.org/patches/titlecolor/)
- [urgentborder](https://dwm.suckless.org/patches/urgentborder/)
- [urgent tag color](https://github.com/ericpruitt/mydwm/blob/master/patches/00-urgent-tag-color.diff)

# Autostart applications
Autostart applications are executed using [~/.xprofile](https://github.com/cochayuyo/dwm/blob/master/.xprofile)
file that is sourced by lxdm after user logs on.
# Scripts
Auxiliary script that control special keys like XK_Caps_Lock, XF86XK_ScreenSaver, XF86XK_MonBrightnessDown, and so on, can be found at the following link: https://github.com/cochayuyo/dwm/blob/master/scripts/key-bindings

The status bar script can be found in this link: https://github.com/cochayuyo/dwm/blob/master/scripts/statusbar
