#include "mainWindow.h"

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "gameData.h"
#include "frameSystem.h"
#include "logoframe.h"
#include "mainMenuFrame.h"

/******************************************************************
* Parameters
******************************************************************/

enum ResCode res_code;

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
		printSelectedMenuIcon();

		// When keyboard interrupt, get char data
		keyChar = _getch();					// Save char data to keyChar

		res_code = Default;
		res_code = checkCharValidation(keyChar);
		// TODO - Validation
		if (res_code)	continue;

		res_code = Default;
		res_code = checkCharEnter(keyChar);
		if (res_code == OK)
		{
			break;
		}
		
		changeMenuIndex(keyChar);
	}

	gameWindowIndex = menuToWindow[gameWindowIndex][1];
}
