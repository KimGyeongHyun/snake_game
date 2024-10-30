#pragma once

#define MAIN_MENU_GAME		0
#define MAIN_MENU_OPTION	1
#define MAIN_MENU_EXIT		2

#define WINDOW_MAIN_MENU	0
#define WINDOW_GAME			1
#define WINDOW_OPTION		2
#define WINDOW_EXIT			3

#define WINDOW_COUNT		4

// determine which window to show
extern int gameWindowIndex;

// determine which main menu to active
extern int mainMenuSelectIndex;

// TODO - need to convert form to const
extern int menuToWindow[WINDOW_COUNT][2];