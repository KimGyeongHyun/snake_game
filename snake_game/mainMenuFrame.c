#include "mainMenuFrame.h"
#include "frameSystem.h"
#include "gameData.h"

char menuArray[MAIN_MENU_NUMBER][10] = {
	{"Start     "}, {"option    "}, {"Exit      "}
};

void printMenuArray()
{
	for (int i = 0; i < MAIN_MENU_NUMBER; i++)
	{
		printString(MAIN_MENU_FRAME_X_START + 4, MAIN_MENU_FRAME_Y_START + 2 * (i + 1), menuArray[i], 10);
	}
}

void printSelectedMenuIcon()
{
	for (int i = 0; i < MAIN_MENU_NUMBER; i++)
	{
		printChar(MAIN_MENU_FRAME_X_START + 2, MAIN_MENU_FRAME_Y_START + 2 * (i + 1), ' ');
	}
	printChar(MAIN_MENU_FRAME_X_START + 2, MAIN_MENU_FRAME_Y_START + 2 * (mainMenuSelectIndex + 1), '@');
}

void changeMenuIndex(char inputChar)
{
	if (inputChar == UP_ARROW_CHAR)
	{
		mainMenuSelectIndex--;
		if (mainMenuSelectIndex < 0)
			mainMenuSelectIndex = MAIN_MENU_NUMBER - 1;
	}
	else if (inputChar == BELOW_ARROW_CHAR)
	{
		mainMenuSelectIndex++;
		if (mainMenuSelectIndex == MAIN_MENU_NUMBER)
			mainMenuSelectIndex = 0;
	}
}

void openMainMenu()
{
	printSquare(MAIN_MENU_FRAME_X_START, MAIN_MENU_FRAME_Y_START, MAIN_MENU_FRAME_WIDTH, MAIN_MENU_FRAME_HEIGHT);

	printMenuArray();
}