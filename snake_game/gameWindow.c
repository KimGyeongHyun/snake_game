#include <windows.h>

#include "gameSystem.h"
#include "gameWindow.h"
#include "gameFrame.h"
#include "gameScoreFrame.h"

// Scores
int currentScore = 0;
int highScore = 0;

void openGameWindow(void)
{
	displayFrame();

	openGameFrame();

	openGameScoreFrame();

	int testInt = 0;

	for (;;)
	{
		printChar(testInt, testInt, '@');
		testInt++;
		Sleep(1000);
	}
}