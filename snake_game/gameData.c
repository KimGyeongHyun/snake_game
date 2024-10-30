#include "gameData.h"

int gameWindowIndex = 0;
int mainMenuSelectIndex = 0;

int menuToWindow[WINDOW_COUNT][2] = {
	{MAIN_MENU_GAME, WINDOW_GAME},
	{MAIN_MENU_OPTION, WINDOW_OPTION},
	{MAIN_MENU_EXIT, WINDOW_EXIT},
	{0, 0}
};
