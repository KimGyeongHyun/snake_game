#include <stdlib.h>

#include "mainGame.h"
#include "gameData.h"
#include "mainWindow.h"
#include "gameWindow.h"
#include "optionWindow.h"

void startGame()
{
	// Set terminal size
	system("mode con: cols=100 lines=30");

	for (;;)
	{
		switch (gameWindowIndex)
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
	}
}