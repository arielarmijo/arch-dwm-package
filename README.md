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
```
attachbelow
center
movestack
pertag
save floats
scratchpad
status2d
statusallmons
titlecolor
```
# Autostart applications
Autostart applications are executed using ~/.xprofile file that is sourced by lxdm after user logs on. This file and can be found in the following link: https://github.com/cochayuyo/dotfiles/blob/master/.xprofile

# Scripts
Auxiliary script that control special keys like XK_Caps_Lock, XF86XK_ScreenSaver, XF86XK_MonBrightnessDown, and so on, can be found at the following link: https://github.com/cochayuyo/dotfiles/blob/master/.local/bin/notebook-state

The status bar script can be found in this link: https://github.com/cochayuyo/dotfiles/blob/master/.local/bin/statusbar
