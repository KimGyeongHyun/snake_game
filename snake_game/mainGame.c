#include <stdlib.h>

#include "mainGame.h"
#include "mainMenuWindow.h"
#include "mainMenu.h"
#include "gameWindow.h"
#include "optionWindow.h"

enum Window_Index
{
	WINDOW_MAIN_MENU = 0,
	WINDOW_GAME = 1,
	WINDOW_OPTION = 2,
	WINDOW_EXIT = 3,
};

// menuIndex -> windowIndex mapping table
const int MENU_TO_WINDOW_MAPPING[][2] = {
	{MENU_START, WINDOW_GAME},
	{MENU_OPTION, WINDOW_OPTION},
	{MENU_EXIT, WINDOW_EXIT}
};

// Determine which window to open
static int windowIndex = 0;

// Mapping menuIndex -> windowIndex
void menuToWindowMapping()
{
	windowIndex = MENU_TO_WINDOW_MAPPING[getMenuIndex()][1];
}

// main game function
void startGame()
{
	// Set terminal size
	system("mode con: cols=100 lines=30");

	/******************************************************
	* Open window
	* 
	* window is determined by windowIndex
	* windowIndex is determined by other windows
	*******************************************************/
	for (;;)
	{
		// windowIndex is controlled by main menu & game over
		switch (windowIndex)
		{
		case WINDOW_MAIN_MENU:
			// Main menu window
			// Open first
			openMainMenuWindow();

			// MenuIndex -> windowIndex mapping
			menuToWindowMapping();

			break;
		case WINDOW_GAME:
			// Game window
			// Play game in this window
			openGameWindow();

			// Go to main menu when game over
			windowIndex = WINDOW_MAIN_MENU;

			break;
		case WINDOW_OPTION:
			// Option window
			openOptionWindow();
			break;

		case WINDOW_EXIT:
			// Exit when select exit in main menu window
			exit(2);
			break;
		}
	}
}