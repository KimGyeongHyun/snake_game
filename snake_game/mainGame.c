#include <stdlib.h>

#include "mainGame.h"
#include "gameData.h"
#include "mainWindow.h"
#include "gameWindow.h"
#include "optionWindow.h"

// Determine which window to open
static int windowIndex = 0;

// menuIndex -> windowIndex mapping table
const int MENU_TO_WINDOW_MAPPING[][2] = {
	{MENU_START, WINDOW_GAME},
	{MENU_OPTION, WINDOW_OPTION},
	{MENU_EXIT, WINDOW_EXIT}
};

// Mapping menuIndex -> windowIndex
void windowMapping()
{
	windowIndex = MENU_TO_WINDOW_MAPPING[menuIndex][1];
}

// main game function
void startGame()
{
	// Set terminal size
	system("mode con: cols=100 lines=30");

	// Open window
	for (;;)
	{
		// windowIndex is controlled by main menu & game over
		switch (windowIndex)
		{
		case WINDOW_MAIN_MENU:
			// main menu window
			// open first
			openMainMenuWindow();
			break;
		case WINDOW_GAME:
			// game window
			// play game in this window
			openGameWindow();
			break;
		case WINDOW_OPTION:
			// option window
			openOptionWindow();
			break;
		case WINDOW_EXIT:
			// exit when select exit in main menu window
			exit(2);
			break;
		}

		// menuIndex -> windowIndex mapping
		windowMapping();
	}
}