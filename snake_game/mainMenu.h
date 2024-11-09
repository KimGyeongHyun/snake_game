#pragma once

#define MAIN_MENU_NUMBER			3

extern char menuArray[MAIN_MENU_NUMBER][10];
extern int menuIndex;

void changeMenuIndex(char inputChar);