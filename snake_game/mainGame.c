#include <stdlib.h>

#include "mainGame.h"
#include "gameData.h"
#include "mainWindow.h"
#include "gameWindow.h"
#include "optionWindow.h"

static int windowIndex = 0;

const int MENU_TO_WINDOW_MAPPING[][2] = {
	{MENU_START, WINDOW_GAME},
	{MENU_OPTION, WINDOW_OPTION},
	{MENU_EXIT, WINDOW_EXIT}
};

void windowMapping()
{
	windowIndex = MENU_TO_WINDOW_MAPPING[menuIndex][1];
}

void startGame()
{
	// Set terminal size
	system("mode con: cols=100 lines=30");

	for (;;)
	{
		switch (windowIndex)
		{
		case WINDOW_MAIN_MENU:
			openMainMenuWindow();
			break;
		case WINDOW_GAME:
			openGameWindow();
			break;
		case WINDOW_OPTION:
			openOptionWindow();
			break;
		case WINDOW_EXIT:
			exit(2);
			break;
		}

		windowMapping();
	}
}