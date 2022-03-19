#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

export EDITOR=/usr/bin/vim
export VISUAL=/usr/bin/leafpad
export HISTCONTROL=ignoreboth

# ROS environment setup
source /opt/ros/noetic/setup.bash
if [ $EUID -ne 0 ]; then
	source ~/Proyectos/rplidar/catkin_ws/devel/setup.bash
fi

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

alias bg='feh --bg-scale ~/.wallpapers/wallpaper'
alias bi='acpi -bi'
alias bl='cat /sys/class/power_supply/BAT0/charge_control_end_threshold'
alias bt='bluetoothctl'
alias clean='sudo pacman -Rns --noconfirm $(pacman -Qtdq) 2>/dev/null || echo -e "\nNo hay paquetes huérfanos\n"; sudo pacman -Sc; aurman -Sc --aur'
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

