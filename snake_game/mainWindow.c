#include "mainWindow.h"

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

// Move cursor to (x, y)
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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

// Move cursor to end
void gotoEnd()
{
	gotoxy(WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
}

// Display c(char) in (x, y)
void displayCharInXY(int x, int y, char c)
{
	// validation x, y coordinate
	if (x < 0 || x >= WINDOW_WIDTH)		return;
	if (y < 0 || y >= WINDOW_HEIGHT)	return;

	// Move cursor to (x, y)
	gotoxy(x, y);
	// print c(char)
	printf("%c", c);

	// Return to end
	gotoEnd();
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
