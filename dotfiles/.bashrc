#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

export EDITOR=/usr/bin/vim
export VISUAL=/usr/bin/leafpad
export HISTCONTROL=ignoreboth

none="\[\e[0m\]"
user="\[\e[1;32m\]"
host="\[\e[1;36m\]"
dir="\[\e[1;33m\]"
white="\[\e[1;37m\]"

sym="$"

if [ $EUID -eq 0 ]; then
	user="\[\e[1;33m\]"
	sym="#"
fi

PS1="$user\u$white@$host\h: $dir\w $white\$sym$none "

complete -cf sudo

alias ls='ls --color=auto --group-directories-first'
alias grep='grep --color=auto'
alias bt='bluetoothctl'
alias nf='echo && neofetch'
alias bi='acpi -bi'
alias mirror='wget --mirror --convert-links --page-requisites --no-parent'
alias clean='sudo pacman -Rns --noconfirm $(pacman -Qtdq) 2>/dev/null || echo -e "\nNo hay paquetes huérfanos\n"; sudo pacman -Sc; aurman -Sc --aur'
alias rf='sudo reflector --verbose --connection-timeout 15 --protocol http,https --latest 50 --fastest 15 --sort rate --save /etc/pacman.d/mirrorlist'
