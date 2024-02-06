#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

clear
source /usr/share/nvm/init-nvm.sh
source /usr/share/bash-completion/completions/git

#
# Run 'nvm use' automatically every time there's 
# a .nvmrc file in the directory. Also, revert to default 
# version when entering a directory without .nvmrc
enter_directory() {
	if [[ $PWD == $PREV_PWD ]]; then
		return
	fi
	PREV_PWD=$PWD
	if [[ -f ".nvmrc" ]]; then
		nvm use
		NVM_DIRTY=true
	elif [[ $NVM_DIRTY = true ]]; then
		nvm use default
		NVM_DIRTY=false
	fi
}

export PROMPT_COMMAND="$PROMPT_COMMAND; enter_directory"

export GPG_TTY=$(tty)
export EDITOR=/usr/bin/vim
export VISUAL=/usr/bin/leafpad
export HISTCONTROL=ignoreboth

# prompt colors
none="\[\e[0m\]"

red="\[\e[1;31m\]"
green="\[\e[1;32m\]"
yellow="\[\e[1;33m\]"
blue="\[\e[1;34m\]"
purple="\[\e[1;35m\]"
cyan="\[\e[1;36m\]"
white="\[\e[1;37m\]"

lred="\[\e[0;31m\]"
lgreen="\[\e[0;32m\]"
lyellow="\[\e[0;33m\]"
lblue="\[\e[0;34m\]"
lpurple="\[\e[0;35m\]"
lcyan="\[\e[0;36m\]"
lwhite="\[\e[0;37m\]"

usercolor=$green
hostcolor=$cyan
dircolor=$yellow
symcolor=$white
warncolor=$purple
branchcolor=$purple

sym="$"

if [ $EUID -eq 0 ]; then
	usercolor=$yellow
	sym="#"
fi

git_branch() {
	git branch 2> /dev/null | sed -e '/^[^*]/d' -e "s/* \(.*\)/(\1)/"
}

PS1="$usercolor\u$none@$hostcolor\h: $dircolor\w $branchcolor\$(git_branch) $symcolor$sym$none "

complete -cf sudo

alias sbg='feh --bg-scale ~/.wallpapers/current'
alias bt='bluetoothctl'
alias clean='sudo pacman -Rns --noconfirm $(pacman -Qtdq) 2>/dev/null || echo -e "\nNo hay paquetes huérfanos\n"; sudo pacman -Sc;journalctl --vacuum-time=4weeks ;aurman -Sc --aur'
alias grep='grep --color=auto'
alias ls='ls --color=auto --group-directories-first'
alias nf='neofetch'
alias rf='sudo reflector --protocol https --delay 1 --latest 100 --sort age --save /etc/pacman.d/mirrorlist'
alias usedPorts='lsof -i -P -n | grep LISTEN'

# prevent nested ranger instances
ranger() {
	if [ -z "$RANGER_LEVEL" ]; then
		/usr/bin/ranger "$@"
	else
		exit
	fi
}

vpn() {
	sudo openfortivpn -c "$HOME/.config/openfortivpn/$1-vpn.config"
}

vm() {
  xrandr --addmode VIRTUAL1 1024x576 &&
  xrandr --output VIRTUAL1 --mode 1024x576 --pos 896x1080 &&
  adb reverse tcp:1701 tcp:1701 &&
  adb reverse tcp:9001 tcp:9001 &&
  weylus --auto-start --no-gui &
}

print() {
  device=${PRINTER:-MTP_II}
  size=$(pdfinfo $1 | awk '$6 == "pts" { printf "Custom.%sx%s", $3, $5 }')
  lp -d $device -o media=$size $1
}

