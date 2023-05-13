/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int systraypinning = 1;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;		/* 0 means no systray */
static const unsigned int borderpx	= 1;		/* border pixel of windows */
static const unsigned int snap			= 8;		/* snap pixel */
static const int showbar            = 1;    /* 0 means no bar */
static const int topbar             = 1;    /* 0 means bottom bar */
static const int statmonval					= 0;		/* staticstatus */
static const char *fonts[]					= { "DejaVuSansMono Nerd Font:size=10", "Noto Color Emoji:size=10" };
static const char dmenufont[]				= "DejaVuSansMono Nerd Font:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_red[]					= "#ff0000";
static const char *colors[][3]      = {
	/* scheme			fg			bg			border   */
	[SchemeNorm]	= { col_gray3,	col_gray1,	col_gray1 },
	[SchemeSel]		= { col_gray4,	col_cyan,		col_cyan  },
	[SchemeTitle]	= { col_gray4,	col_gray1,	col_gray1 },
	[SchemeUrg]		= { col_red,		col_gray1,	col_red   },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

/* rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title	 */
	/* class				instance			title		tags mask		isfloating	monitor */
	{ NULL,		 			"spterm",			NULL,		SPTAG(0),		1,			-1 },
	{ NULL,		 			"spleafpad",		NULL,		SPTAG(1),		1,			-1 },
	{ NULL,		 			"spcalc",			NULL,		SPTAG(2),		1,			-1 },
	{ "Blueman-manager",	"blueman-manager",	NULL,		0,				1,          -1 },
	{ "GoldenDict",			"goldendict",		NULL,		0,				1,          -1 },
	{ "Galculator",			"galculator",		NULL,		0,				1,          -1 },
	{ "Java",				"java",				NULL,		0,				1,          -1 },
	{ "mpv",				"gl",				NULL,		0,				1,          -1 },
	{ "Pavucontrol",		"pavucontrol",		NULL,		0,				1,          -1 },
	{ "transmission-gtk",	"transmission-gtk",	NULL,		1 << 8,			0,          -1 },
	{ NULL,					"cmus",				NULL,		1 << 8,			0,          -1 },
	{ "Xsane",				NULL,				NULL,		0,				1,          -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */

static const Layout layouts[] = {
	/* symbol     function */
	{ "[]=",      tile },
	{ "><>",      NULL },
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ NULL,       NULL },
};

/* key definitions
*	Alt -> Mod1Mask
* Win -> Mod4Mask */
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
static char dmenumon[2]			= "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]	= { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]	= { "urxvtc", NULL };
static const char *xkillcmd[]	= { "xkill", NULL };

/* scratchpads */
typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"/home//aarmijo/.local/bin/spterm", NULL };
const char *spcmd2[] = {"/home/aarmijo/.local/bin/spleafpad", NULL };
const char *spcmd3[] = {"/home/aarmijo/.local/bin/spcalc", NULL };
static Sp scratchpads[] = {
	/* name         cmd  */
	{"spterm",      spcmd1},
	{"spleafpad",   spcmd2},
	{"spcalc",			spcmd3},
};

/* shortcuts */
#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key			   function        argument */
	{ MODKEY,                       XK_b,			togglebar,      {0} },
	{ MODKEY|ShiftMask,    					XK_b,	   	spawn,					SHCMD("~/.local/bin/key-bindings open blueman-applet") },
	{ MODKEY,                       XK_c,     setlayout,      {.v = &layouts[6]} },
	{ MODKEY|ShiftMask,							XK_c,			spawn,					SHCMD("~/.local/bin/key-bindings open chromium") },
	{ MODKEY,                       XK_d,     incnmaster,     {.i = -1 } },
	{ MODKEY,												XK_e,			spawn,					SHCMD("~/.local/bin/dmenu_exit") },
	{ MODKEY,                       XK_f,     setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,							XK_g,			togglescratch,	{.ui = 2} },
	{ MODKEY,                       XK_h,			setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_h,			setcfact,       {.f = -0.25} },
	{ MODKEY,                       XK_i,			incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,   					XK_i,  	  togglescratch,  {.ui = 1 } },
	{ MODKEY,												XK_j,			focusstack,     {.i = INC(+1)} },
	{ MODKEY|ShiftMask,    					XK_j,			pushstack,      {.i = INC(+1)} },
	{ MODKEY,              					XK_k,			focusstack,     {.i = INC(-1)} },
	{ MODKEY|ShiftMask,    					XK_k,			pushstack,      {.i = INC(-1)} },
	{ MODKEY,                       XK_l,			setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,			setcfact,       {.f = +0.25} },
	{ MODKEY,                       XK_m,     setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_n,     setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_o,     spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,   					XK_o,  	  togglescratch,  {.ui = 0 } },
	{ MODKEY|ControlMask,           XK_o,     setcfact,       {.f =  0.00} },
	{ MODKEY,												XK_p,			spawn,					SHCMD("~/.local/bin/dmenu_display") },
	{ MODKEY|ShiftMask,							XK_p,			spawn,					SHCMD("~/.local/bin/key-bindings open pcmanfm") },
	{ MODKEY,												XK_q,     killclient,     {0} },
	{ MODKEY,                       XK_r,     setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,    					XK_r,	   	spawn,					SHCMD("~/.local/bin/key-bindings open ranger") },
	{ MODKEY,                       XK_t,     setlayout,      {.v = &layouts[0]} },
	{ MODKEY,												XK_u,			spawn,					SHCMD("~/.local/bin/dmenu_mount") },
	{ MODKEY|ShiftMask,							XK_u,			spawn,					SHCMD("~/.local/bin/dmenu_unmount") },
	{ MODKEY|ShiftMask,							XK_w,			spawn,					SHCMD("~/.fehbg") },
	{ MODKEY,                       XK_y,     setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,							XK_x,			spawn,					{.v = xkillcmd} },

	{ MODKEY,                       XK_comma,			focusmon,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_comma,  		tagmon,         {.i = -1 } },
	{ MODKEY|ControlMask,						XK_comma,			cyclelayout,    {.i = -1 } },
	{ MODKEY,                       XK_period, 		focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_period, 		tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,           XK_period,		cyclelayout,    {.i = +1 } },
	{ MODKEY,												XK_space,			spawn,					SHCMD("~/.local/bin/key-bindings keyboard-toggle") },
	{ MODKEY|ShiftMask,             XK_space,  		togglefloating, {0} },
	{ MODKEY,                       XK_Return, 		zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_Return, 		spawn,          {.v = termcmd } },
	{ Mod1Mask|ControlMask,         XK_BackSpace,	quit,						{0} },
	{ MODKEY,                       XK_Tab,				view,           {0} },

	{ MODKEY,              					XK_Up,			focusstack,     {.i = INC(-1)} },
	{ MODKEY|ShiftMask,    					XK_Up,			pushstack,      {.i = INC(-1)} },
	{ MODKEY,												XK_Down,		focusstack,     {.i = INC(+1)} },
	{ MODKEY|ShiftMask,    					XK_Down,		pushstack,      {.i = INC(+1)} },

	{ MODKEY,                       XK_0,   	   	view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,   	   	tag,            {.ui = ~0 } },
	TAGKEYS(                        XK_1,			0)
	TAGKEYS(                        XK_2,			1)
	TAGKEYS(                        XK_3,			2)
	TAGKEYS(                        XK_4,			3)
	TAGKEYS(                        XK_5,			4)
	TAGKEYS(                        XK_6,			5)
	TAGKEYS(                        XK_7,			6)
	TAGKEYS(                        XK_8,			7)
	TAGKEYS(                        XK_9,			8)

	{ 0,					XK_Print,									spawn,			SHCMD("~/.local/bin/key-bindings screen-shot") },
	{ ShiftMask,	XK_Print,									spawn,			SHCMD("~/.local/bin/key-bindings screen-shot-focused") },
	{ 0,					XK_Caps_Lock,							spawn,			SHCMD("~/.local/bin/key-bindings caps-lock") },
	{ 0,					XK_Num_Lock,							spawn,			SHCMD("~/.local/bin/key-bindings num-lock") },
	{ 0,					XF86XK_AudioPlay,					spawn,			SHCMD("~/.local/bin/key-bindings player-play") },
	{ 0,					XF86XK_AudioPause,				spawn,			SHCMD("~/.local/bin/key-bindings player-play") },
	{ 0,					XF86XK_AudioPrev,					spawn,			SHCMD("~/.local/bin/key-bindings player-previous") },
	{ 0,					XF86XK_AudioNext,					spawn,			SHCMD("~/.local/bin/key-bindings player-next") },
	{ 0,					XF86XK_TouchpadToggle,		spawn,			SHCMD("~/.local/bin/key-bindings toggle-touchpad") },
	{ 0,					XF86XK_AudioMute,					spawn,			SHCMD("~/.local/bin/key-bindings volume-mute") },
	{ ShiftMask,	XF86XK_AudioMute,					spawn,			SHCMD("~/.local/bin/key-bindings restart-volumeicon") },
	{ 0,					XF86XK_AudioLowerVolume,	spawn,			SHCMD("~/.local/bin/key-bindings volume-down") },
	{ 0,					XF86XK_AudioRaiseVolume,	spawn,			SHCMD("~/.local/bin/key-bindings volume-up") },
	{ 0,					XF86XK_MonBrightnessUp,		spawn,			SHCMD("~/.local/bin/key-bindings backlight-up") },
	{ 0,					XF86XK_MonBrightnessDown,	spawn,			SHCMD("~/.local/bin/key-bindings backlight-down") },
	{ 0,					XF86XK_Calculator,				spawn,			SHCMD("~/.local/bin/key-bindings open galculator") },

	{ MODKEY,							XK_F1,						spawn,			SHCMD("~/.local/bin/key-bindings player-play") },
	{ MODKEY,							XK_F2,						spawn,			SHCMD("~/.local/bin/key-bindings player-previous") },
	{ MODKEY,							XK_F3,						spawn,			SHCMD("~/.local/bin/key-bindings player-next") },
	{ MODKEY,							XK_F6,						spawn,			SHCMD("~/.local/bin/key-bindings toggle-autolock") },
	{ MODKEY|ShiftMask,		XK_F6,						spawn,			SHCMD("~/.local/bin/key-bindings screen-lock") },
	{ MODKEY|ControlMask,	XK_F6,						spawn,			SHCMD("~/.local/bin/key-bindings screen-off") },
};


/* button definitions
 * click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin
 */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },

	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkWinTitle,          0,				Button4,        focusstack,		{.i = INC(-1)} },
	{ ClkWinTitle,          MODKEY,			Button4,        pushstack,		{.i = INC(-1)} },
	{ ClkWinTitle,          0,				Button5,        focusstack,		{.i = INC(+1)} },
	{ ClkWinTitle,         	MODKEY,			Button5,        pushstack,		{.i = INC(+1)} },

	{ ClkStatusText,        0,              Button3,        spawn,          SHCMD("~/.local/bin/key-bindings open gsimplecal") },

	{ ClkClientWin,         MODKEY,			Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,			Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,			Button3,        resizemouse,	{0} },

	{ ClkRootWin,           0,              Button2,        spawn,          { .v = termcmd } },

	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            MODKEY,			Button1,        tag,            {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button4,        shiftview,		{.i = +1} },
	{ ClkTagBar,            0,              Button5,        shiftview,      {.i = -1} },
};


/* custom functions */

/** Function to shift the current view to the left/right
 *
 * @param: "arg->i" stores the number of tags to shift right (positive value)
 *          or left (negative value)
 */
void shiftview(const Arg *arg) {
	Arg shifted;
	if(arg->i > 0) // left circular shift
		shifted.ui = (selmon->tagset[selmon->seltags] << arg->i)
		   | (selmon->tagset[selmon->seltags] >> (LENGTH(tags) - arg->i));
	else // right circular shift
		shifted.ui = selmon->tagset[selmon->seltags] >> (- arg->i)
		   | selmon->tagset[selmon->seltags] << (LENGTH(tags) + arg->i);
	view(&shifted);
}
