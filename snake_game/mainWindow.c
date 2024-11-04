#include "mainWindow.h"

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "gameData.h"
#include "gameSystem.h"
#include "logoframe.h"
#include "mainMenuFrame.h"

/******************************************************************
* Parameters
******************************************************************/

enum ResCode res_code;

// Determine active menu
// when enter is pressed, select active menu & open window
int menuIndex = 0;

// Initialize window parameters
void initDisplayParameters(void)
{
	;
}

enum ResCode checkCharValidation(char c)
{
	// TODO - Add char validation
	return OK;
}

// Check enter
enum ResCode checkCharEnter(char c)
{
	if (c == GETCH_CHAR_ENTHER)
		return OK;
	else
		return NO;
}

void openMainMenuWindow(void)
{
	// Initialize window parameters
	initDisplayParameters();

	// Display empty Frame
	displayFrame();					

	// Display logo
	openLogo();

	// Display main menu
	openMainMenu();

	char keyChar;	// get input char from keyboard
	for (;;)
	{
		// Highlight active menu in terminal
		printSelectedMenuIcon(&menuIndex);

		// When keyboard interrupt, get char data
		keyChar = _getch();					// Save char data to keyChar

		res_code = Default;
		res_code = checkCharValidation(keyChar);
		// TODO - Validation
		// maybe no use
		if (res_code)	continue;

		res_code = Default;
		res_code = checkCharEnter(keyChar);
		if (res_code == OK)
		{
			break;
		}
		
		// if up OR down arrow is pressed, change menuIndex
		changeMenuIndex(keyChar, &menuIndex);
	}
}
