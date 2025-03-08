#include "mainMenu.h"
#include "gameSystem.h"
#include "mainGame.h"
#include "mainMenuFrame.h"

// Main menu
char menuArray[MAIN_MENU_NUMBER][10] = {
	{"Start     "}, {"option    "}, {"Exit      "}
};

// Active menu Index
static enum Menu_Index menuIndex = MENU_START;

enum Menu_Index getMenuIndex(void)
{
	return menuIndex;
}

// Change active menu
void changeMenuIndex(char inputChar)
{
	// If press prev, active prev menu
	if (inputChar == UP_ARROW_CHAR || inputChar == LEFT_ARROW_CHAR)
		menuIndex = (menuIndex - 1 + MAIN_MENU_NUMBER) % MAIN_MENU_NUMBER;

	// If press next, active next menu
	else if (inputChar == BELOW_ARROW_CHAR || inputChar == RIGHT_ARROW_CHAR)
		menuIndex = (menuIndex + 1) % MAIN_MENU_NUMBER;
}