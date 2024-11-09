#include "mainMenuFrame.h"
#include "gameSystem.h"
#include "mainMenu.h"

// Print menu list in terminal
void displayMainMenuInFrame()
{
	for (int i = 0; i < MAIN_MENU_NUMBER; i++)
	{
		printString(MAIN_MENU_FRAME_X_START + 4, MAIN_MENU_FRAME_Y_START + 2 * (i + 1), menuArray[i], 10);
	}
}

// Print active menu in terminal
void printSelectedMenuIcon()
{
	for (int i = 0; i < MAIN_MENU_NUMBER; i++)
	{
		printChar(MAIN_MENU_FRAME_X_START + 2, MAIN_MENU_FRAME_Y_START + 2 * (i + 1), ' ');
	}
	printChar(MAIN_MENU_FRAME_X_START + 2, MAIN_MENU_FRAME_Y_START + 2 * (menuIndex + 1), '@');
}

void displayMainMenuFrame()
{
	printSquare(MAIN_MENU_FRAME_X_START, MAIN_MENU_FRAME_Y_START, MAIN_MENU_FRAME_WIDTH, MAIN_MENU_FRAME_HEIGHT);
}

void changeMenuIndexInFrame(char inputChar)
{
	changeMenuIndex(inputChar);
}