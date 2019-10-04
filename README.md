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

- [attachbelow](https://dwm.suckless.org/patches/attachbelow/dwm-attachbelow-toggleable-6.2.diff)
- [center](https://dwm.suckless.org/patches/center/dwm-center-6.1.diff)
- [movestack](https://dwm.suckless.org/patches/movestack/dwm-movestack-6.1.diff)
- [pertag](https://dwm.suckless.org/patches/pertag/dwm-pertag-20170513-ceac8c9.diff)
- [save floats](https://dwm.suckless.org/patches/save_floats/dwm-savefloats-20181212-b69c870.diff)
- [scratchpad](https://dwm.suckless.org/patches/scratchpad/dwm-scratchpad-6.2.diff)
- [status2d](https://dwm.suckless.org/patches/status2d/dwm-status2d-20161231-bb3bd6f.diff)
- [statusallmons](https://dwm.suckless.org/patches/statusallmons/dwm-statusallmons-20160731-56a31dc.diff)
- [titlecolor](https://dwm.suckless.org/patches/titlecolor/dwm-titlecolor-20190206-6.2.diff)
- [urgentborder](https://dwm.suckless.org/patches/urgentborder/dwm-6.1-min-border.diff)
- [urgent tag color](https://github.com/ericpruitt/mydwm/blob/master/patches/00-urgent-tag-color.diff)

# Autostart applications
Autostart applications are executed using [~/.xprofile](https://github.com/cochayuyo/dotfiles/blob/master/.xprofile)
file that is sourced by lxdm after user logs on.
# Scripts
Auxiliary script that control special keys like XK_Caps_Lock, XF86XK_ScreenSaver, XF86XK_MonBrightnessDown, and so on, can be found at the following link: https://github.com/cochayuyo/dotfiles/blob/master/.local/bin/key-bindings

The status bar script can be found in this link: https://github.com/cochayuyo/dotfiles/blob/master/.local/bin/statusbar
