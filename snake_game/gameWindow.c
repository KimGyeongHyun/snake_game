#include <windows.h>

#include "gameSystem.h"
#include "gameWindow.h"
#include "gameFrame.h"

void openGameWindow(void)
{
	displayFrame();

	openGameFrame();

	int testInt = 0;

	for (;;)
	{
		printChar(testInt, testInt, '@');
		testInt++;
		Sleep(1000);
	}
}