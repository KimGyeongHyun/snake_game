#pragma once

#define MAIN_MENU_NUMBER			3

extern char menuArray[MAIN_MENU_NUMBER][10];

enum Menu_Index
{
	MENU_START = 0,
	MENU_OPTION = 1,
	MENU_EXIT = 2,
};

enum Menu_Index getMenuIndex(void);
void changeMenuIndex(char inputChar);