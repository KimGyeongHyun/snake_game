#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdbool.h>

#include "mainMenuWindow.h"
#include "gameSystem.h"
#include "logoframe.h"
#include "mainMenuFrame.h"

void displayMainMenuWindowFrames(void)
{
	// Display empty window
	displayEmptyWindow();

	// Display logo frame
	displayLogoFrame();

	// Display main menu frame
	displayMainMenuFrame();
}

void openMainMenuWindow(void)
{
	// draw all main menu frames
	displayMainMenuWindowFrames();

	// Display main menu
	displayMainMenuInFrame();

	char keyChar;	// get input char from keyboard
	for (;;)
	{
		// Highlight active menu in terminal
		printSelectedMenuIcon();

		// When keyboard interrupt, get char data
		keyChar = _getch();					// Save char data to keyChar

		// if enter is pressed, exit main window
		if (keyChar == GETCH_CHAR_ENTER)
			break;
				
		// if arrow is pressed, change menuIndex (active menu)
		changeMenuIndexInFrame(keyChar);
	}
}
