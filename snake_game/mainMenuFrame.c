#include "mainMenuFrame.h"
#include "gameSystem.h"
#include "gameData.h"

char menuArray[MAIN_MENU_NUMBER][10] = {
	{"Start     "}, {"option    "}, {"Exit      "}
};

// Print menu in terminal
void printMenuArray()
{
	for (int i = 0; i < MAIN_MENU_NUMBER; i++)
	{
		printString(MAIN_MENU_FRAME_X_START + 4, MAIN_MENU_FRAME_Y_START + 2 * (i + 1), menuArray[i], 10);
	}
}

// Print active menu in terminal
void printSelectedMenuIcon(int* input_menuIndex)
{
	for (int i = 0; i < MAIN_MENU_NUMBER; i++)
	{
		printChar(MAIN_MENU_FRAME_X_START + 2, MAIN_MENU_FRAME_Y_START + 2 * (i + 1), ' ');
	}
	printChar(MAIN_MENU_FRAME_X_START + 2, MAIN_MENU_FRAME_Y_START + 2 * (*input_menuIndex + 1), '@');
}

// Change active menu
void changeMenuIndex(char inputChar, int* input_menuIndex)
{
	if (inputChar == UP_ARROW_CHAR)
	{
		(*input_menuIndex)--;
		if (*input_menuIndex < 0)
			*input_menuIndex = MAIN_MENU_NUMBER - 1;
	}
	else if (inputChar == BELOW_ARROW_CHAR)
	{
		(*input_menuIndex)++;
		if (*input_menuIndex == MAIN_MENU_NUMBER)
			*input_menuIndex = 0;
	}
}

void openMainMenu()
{
	printSquare(MAIN_MENU_FRAME_X_START, MAIN_MENU_FRAME_Y_START, MAIN_MENU_FRAME_WIDTH, MAIN_MENU_FRAME_HEIGHT);

	printMenuArray();
}