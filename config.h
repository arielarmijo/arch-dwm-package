/* See LICENSE file for copyright and license details. */


/* appearance */
static const unsigned int borderpx		 = 1;	/* border pixel of windows */
static const unsigned int snap			 = 8;   /* snap pixel */
static const unsigned int systraypinning = 1;	/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 1;	/* systray spacing */
static const int systraypinningfailfirst = 1;	/* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray			 = 1;	/* 0 means no systray */
static const int showbar				 = 1;   /* 0 means no bar */
static const int topbar					 = 1;	/* 0 means bottom bar */
static const char *fonts[]				 = { "DejaVuSansMono Nerd Font:size=10" };
static const char dmenufont[]			 = "DejaVuSansMono Nerd Font:size=10";
static const char col_gray1[]			 = "#222222";
static const char col_gray2[]			 = "#444444";
static const char col_gray3[]			 = "#bbbbbb";
static const char col_gray4[]			 = "#eeeeee";
static const char col_cyan[]			 = "#005577";
static const char col_red[]				 = "#ff0000";
static const char col_green[]			 = "#00ff00";
static const char col_yellow[]			 = "#ffff00";
static const char *colors[][3]			 = {
	/*                fg         bg         border   */
	[SchemeNorm]  = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]   = { col_gray4, col_cyan,  col_cyan  },
	[SchemeTitle] = { col_gray4, col_gray1, col_gray1 },
	[SchemeUrg]   = { col_gray1, col_red,   col_red   },
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class				instance		title				tags mask		isfloating   monitor */
//	{ "GLFW-Application",	NULL,			NULL,				0,				1,           -1 },
	{ "GoldenDict",			NULL,			NULL,				0,				1,           -1 },
	{ "Galculator",			NULL,			NULL,				0,				1,           -1 },
	{ "mpv",				NULL,			NULL,				0,				1,           -1 },
	{ "URxvt",			   "cmus",			NULL,				1 << 8,			0,           -1 },
	{ "Pavucontrol",		NULL,			NULL,				0,				1,           -1 },
	{ "Transmission-gtk",	NULL,			NULL,				1 << 8,			0,           -1 },
	{ "Xsane",				NULL,			NULL,				0,				1,           -1 },
};


/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }


/* custom functions declarations */
static void shiftview(const Arg *arg);


/* commands */
static char dmenumon[2]				= "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]		= { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]		= { "urxvtc", NULL };
static const char scratchpadname[]	= "scratchpad";
static const char *scratchpadcmd[]	= { "urxvtc", "-name", scratchpadname, "-g", "82x22+1094+19", NULL };

#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier             key					function        argument */
	{ MODKEY,				XK_o,						spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,		XK_o,						togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY|ShiftMask,		XK_Return,					spawn,          {.v = termcmd } },
	{ MODKEY,				XK_p,						spawn,			SHCMD("~/.local/bin/dmenu_display") },
	{ MODKEY|ShiftMask,		XK_p,						spawn,			SHCMD("~/.local/bin/key-bindings open pcmanfm") },
	{ MODKEY|ShiftMask,		XK_r,						spawn,			SHCMD("~/.local/bin/key-bindings open ranger") },
	{ MODKEY|ShiftMask,		XK_x,						spawn,			SHCMD("/usr/bin/xkill") },
	{ MODKEY|ShiftMask,		XK_c,						spawn,			SHCMD("~/.local/bin/key-bindings open chromium") },
	{ MODKEY,				XK_Print,					spawn,			SHCMD("~/.local/bin/key-bindings screen-shot") },
	{ MODKEY|ShiftMask,		XK_Print,					spawn,			SHCMD("~/.local/bin/key-bindings screen-shot-focused") },
	{ 0,					XK_Caps_Lock,				spawn,			SHCMD("~/.local/bin/key-bindings caps-lock") },
//	{ 0,					XK_Num_Lock,				spawn,			SHCMD("~/.local/bin/key-bindings num-lock") },
	{ 0,					XF86XK_AudioPlay,			spawn,			SHCMD("~/.local/bin/key-bindings player-play") },
	{ 0,					XF86XK_AudioPause,			spawn,			SHCMD("~/.local/bin/key-bindings player-play") },
	{ 0,					XF86XK_AudioPrev,			spawn,			SHCMD("~/.local/bin/key-bindings player-previous") },
	{ 0,					XF86XK_AudioNext,			spawn,			SHCMD("~/.local/bin/key-bindings player-next") },
	{ MODKEY,				XK_F1,						spawn,			SHCMD("~/.local/bin/key-bindings player-play") },
	{ MODKEY,				XK_F2,						spawn,			SHCMD("~/.local/bin/key-bindings player-previous") },
	{ MODKEY,				XK_F3,						spawn,			SHCMD("~/.local/bin/key-bindings player-next") },
	{ 0,					XF86XK_AudioMute,			spawn,			SHCMD("~/.local/bin/key-bindings volume-mute") },
	{ 0,					XF86XK_AudioLowerVolume,	spawn,			SHCMD("~/.local/bin/key-bindings volume-down") },
	{ 0,					XF86XK_AudioRaiseVolume,	spawn,			SHCMD("~/.local/bin/key-bindings volume-up") },
	{ 0,					XF86XK_MonBrightnessUp,		spawn,			SHCMD("~/.local/bin/key-bindings backlight-up") },
	{ 0,					XF86XK_MonBrightnessDown,	spawn,			SHCMD("~/.local/bin/key-bindings backlight-down") },
	{ MODKEY,				XK_F6,						spawn,			SHCMD("~/.local/bin/key-bindings toggle-autolock") },
	{ MODKEY|ShiftMask,		XK_F6,						spawn,			SHCMD("~/.local/bin/key-bindings screen-off") },
	{ MODKEY|ControlMask,	XK_F6,						spawn,			SHCMD("~/.local/bin/key-bindings screen-lock") },
	{ Mod1Mask,				XK_space,					spawn,			SHCMD("~/.local/bin/key-bindings keyboard-toogle") },
	{ 0,					XF86XK_TouchpadToggle,		spawn,			SHCMD("~/.local/bin/key-bindings toggle-touchpad") },
	{ MODKEY,				XK_b,						togglebar,      {0} },
	{ MODKEY,               XK_j,						focusstack,     {.i = +1 } },
	{ MODKEY,               XK_k,						focusstack,     {.i = -1 } },
	{ MODKEY,               XK_i,						incnmaster,     {.i = +1 } },
	{ MODKEY,               XK_d,						incnmaster,     {.i = -1 } },
	{ MODKEY,               XK_h,						setmfact,       {.f = -0.05} },
	{ MODKEY,               XK_l,						setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,     XK_j,						movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_k,						movestack,      {.i = -1 } },
	{ MODKEY,				XK_Up,						focusstack,		{.i = -1 } },
	{ MODKEY|ShiftMask,     XK_Up,						movestack,      {.i = -1 } },
	{ MODKEY,				XK_Down,					focusstack,		{.i = +1 } },
	{ MODKEY|ShiftMask,     XK_Down,					movestack,      {.i = +1 } },
	{ MODKEY,				XK_Left,					setmfact,		{.f = -0.05} },
	{ MODKEY,				XK_Right,					setmfact,		{.f = +0.05} },
	{ MODKEY,				XK_Page_Up,					shiftview,		{.i = +1 } },
	{ MODKEY,				XK_Page_Down,				shiftview,		{.i = -1 } },
	{ MODKEY,               XK_Return,					zoom,           {0} },
	{ MODKEY,               XK_Tab,						view,           {0} },
	{ MODKEY,				XK_q,						killclient,     {0} },
	{ MODKEY,               XK_t,						setlayout,      {.v = &layouts[0]} },
	{ MODKEY,               XK_f,						setlayout,      {.v = &layouts[1]} },
	{ MODKEY,               XK_m,						setlayout,      {.v = &layouts[2]} },
	{ MODKEY,               XK_space,					setlayout,      {0} },
	{ MODKEY|ShiftMask,     XK_space,					togglefloating, {0} },
	{ MODKEY,               XK_0,						view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,     XK_0,						tag,            {.ui = ~0 } },
	{ MODKEY,               XK_comma,					focusmon,       {.i = -1 } },
	{ MODKEY,               XK_period,					focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,     XK_comma,					tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,     XK_period,					tagmon,         {.i = +1 } },
	TAGKEYS(                XK_1,                      	0)
	TAGKEYS(                XK_2,                      	1)
	TAGKEYS(                XK_3,                     	2)
	TAGKEYS(                XK_4,                     	3)
	TAGKEYS(                XK_5,                      	4)
	TAGKEYS(                XK_6,                      	5)
	TAGKEYS(                XK_7,                      	6)
	TAGKEYS(                XK_8,                      	7)
	TAGKEYS(                XK_9,                      	8)
	{ MODKEY|ShiftMask,     XK_q,						quit,           {0} },
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("~/.local/bin/key-bindings open gsimplecal") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


/* custom functions */
/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */
void
shiftview(const Arg *arg) {
	Arg shifted;

	if(arg->i > 0) // left circular shift
		shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)
		   | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));

	else // right circular shift
		shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)
		   | selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);

	view(&shifted);
}
