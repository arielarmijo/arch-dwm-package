#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

source /usr/share/nvm/init-nvm.sh

#
# Run 'nvm use' automatically every time there's 
# a .nvmrc file in the directory. Also, revert to default 
# version when entering a directory without .nvmrc
#
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

alias bg='feh --bg-scale ~/.wallpapers/wallpaper'
alias bi='acpi -bi'
alias bl='cat /sys/class/power_supply/BAT0/charge_control_end_threshold'
alias bt='bluetoothctl'
alias clean='sudo pacman -Rns --noconfirm $(pacman -Qtdq) 2>/dev/null || echo -e "\nNo hay paquetes huérfanos\n"; sudo pacman -Sc;journalctl --vacuum-time=4weeks ;aurman -Sc --aur'
alias cm='cmatrix'
alias grep='grep --color=auto'
alias gt='gittify'
alias ls='ls --color=auto --group-directories-first'
alias nf='echo && neofetch'
alias rf='sudo reflector --protocol https --delay 1 --latest 100 --sort age --save /etc/pacman.d/mirrorlist'

# prevent nested ranger instances
ranger() {
	if [ -z "$RANGER_LEVEL" ]; then
		env TERMCMD=termite /usr/bin/ranger "$@"
	else
		exit
	fi
}

