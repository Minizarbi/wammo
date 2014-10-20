/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int snap = 32;       /* snap pixel */
static const char histfile[]        = "/home/grimy/logs/dmenu";

/* tagging */
static const char *tags[] = {
	"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
	"n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z" };

static const Rule rules[] = {
	/* class       instance    title       tags mask     isfloating   monitor */
	{ "Gimp",      NULL,       NULL,       0,            True,         1 },
	{ "feh",       NULL,       NULL,       0,            True,         1 },
	{ "Gmrun",     NULL,       NULL,       ~0,           True,         1 },
	{ "Viewnior",  NULL,       NULL,       0,            True,        -1 },
};

/* layout(s) */
static const float mfact      = 0.55;  /* factor of master area size [0.05..0.95] */
static const Bool resizehints = True; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "[M]",      monocle }, /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* commands */
static const char *runcmd[] = { "dmenu_run", "-hist", histfile, NULL };

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,             KEY,      comboview,      {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask, KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,   KEY,      combotag,       {.ui = 1 << TAG} }

static Key keys[] = {
	/* modifier                     key           function        argument */
	{ MODKEY,                       XK_Return,    spawn,          {.v = runcmd } },

	{ MODKEY,                       XK_Tab,       focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_Tab,       focusstack,     {.i = -1 } },

	{ MODKEY,                       XK_less,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_less,      setmfact,       {.f = +0.05} },

	{ MODKEY,                       XK_asterisk,  zoom,           {0} },
	{ MODKEY,                       XK_Escape,    killclient,     {0} },
	{ MODKEY,                       XK_space,     setlayout,      {0} },
	{ MODKEY,                       XK_BackSpace, quit,           {0} },

	// Multi-screen stuff
	{ MODKEY,                       XK_comma,     focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,    focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,     tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,    tagmon,         {.i = +1 } },

	// Tags
	{ MODKEY,                       XK_exclam,    view,           {.ui = ~0 } },
	TAGKEYS(                        XK_a,                         0),
	TAGKEYS(                        XK_b,                         1),
	TAGKEYS(                        XK_c,                         2),
	TAGKEYS(                        XK_d,                         3),
	TAGKEYS(                        XK_e,                         4),
	TAGKEYS(                        XK_f,                         5),
	TAGKEYS(                        XK_g,                         6),
	TAGKEYS(                        XK_h,                         7),
	TAGKEYS(                        XK_i,                         8),
	TAGKEYS(                        XK_j,                         9),
	TAGKEYS(                        XK_k,                         10),
	TAGKEYS(                        XK_l,                         11),
	TAGKEYS(                        XK_m,                         12),
	TAGKEYS(                        XK_n,                         13),
	TAGKEYS(                        XK_o,                         14),
	TAGKEYS(                        XK_p,                         15),
	TAGKEYS(                        XK_q,                         16),
	TAGKEYS(                        XK_r,                         17),
	TAGKEYS(                        XK_s,                         18),
	TAGKEYS(                        XK_t,                         19),
	TAGKEYS(                        XK_u,                         20),
	TAGKEYS(                        XK_v,                         21),
	TAGKEYS(                        XK_w,                         22),
	TAGKEYS(                        XK_x,                         23),
	TAGKEYS(                        XK_y,                         24),
	TAGKEYS(                        XK_z,                         25),
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

// os.execute("feh -z --bg-max /home/grimy/" .. (mode and "p0" or "Pictures"))
// os.execute("cut -d' ' -f6 /home/grimy/.fehbg >> /home/grimy/logs/feh")
// else
// os.execute("tail -n " .. index .. " /home/grimy/logs/feh | head -n 1 | xargs feh --bg-max")

