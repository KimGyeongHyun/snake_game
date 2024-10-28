#include "mainWindow.h"

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#include "frameSystem.h"
#include "logoframe.h"

/******************************************************************
* Parameters
******************************************************************/

static int testValue;
enum ResCode res_code;

// Initialize window parameters
void initDisplayParameters(void)
{
	testValue = 1;
	res_code = Default;
}

// Display empty frame
void displayFrame(void)
{
	gotoxy(0, 0);

	for (int i = 0; i < WINDOW_HEIGHT; i++)
	{
		if (i == 0 || i == WINDOW_HEIGHT - 1)	// Upper & below
			printf("\n****************************************************************************************************");
		else									// Middle
			printf("\n*                                                                                                  *");
	}
}

enum ResCode checkCharValidation(char c)
{
	// TODO - Add char validation
	return OK;
}

void openMainWindow(void)
{
	// Initialize window parameters
	initDisplayParameters();

	// Set terminal size
	system("mode con: cols=100 lines=30");

	// Display empty Frame
	displayFrame();					

	// Display logo window
	openLogoWindow();

	char keyChar;	// get input char from keyboard
	for (;;)
	{
		// When keyboard interrupt, get char data
		keyChar = _getch();					// Save char data to keyChar
		res_code = checkCharValidation(keyChar);
		// TODO - Validation
		if (res_code)	continue;
		
		displayCharInXY(2, 4, keyChar);		// Test, Display one char
		displayCharInXY(15, 15, keyChar);	// Test, Display one char
	}
}
