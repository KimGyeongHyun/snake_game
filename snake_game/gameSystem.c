#include "gameSystem.h"
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include "mainWindow.h"

// Move cursor to (x, y)
void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Move cursor to end
void gotoEnd()
{
	gotoxy(WINDOW_WIDTH - 1, WINDOW_HEIGHT - 1);
}

// Display c(char) in (x, y)
void printChar(int x, int y, char c)
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

// Draw square
void printSquare(int inputX, int inputY, int inputWidth, int inputHeight)
{

	char printChar;

	for (int i = inputY; i < inputHeight + inputY; i++)
	{
		gotoxy(inputX, i);
		for (int j = inputX; j < inputWidth + inputX; j++)
		{
			if ((i == inputY && j == inputX) ||
				(i == inputHeight + inputY - 1 && j == inputX) ||
				(i == inputY && j == inputWidth + inputX - 1) ||
				(i == inputHeight + inputY - 1 && j == inputWidth + inputX - 1))
				printChar = '+';
			else if (j == inputX || j == inputWidth + inputX - 1)
				printChar = '|';
			else if (i == inputY || i == inputHeight + inputY - 1)
				printChar = '-';
			else
				printChar = ' ';

			printf("%c", printChar);
		}
	}

	gotoEnd();
}

void printString(int inputX, int inputY, char str[], int strLength)
{
	gotoxy(inputX, inputY);

	for (int i = 0; i < strLength; i++)
		printf("%c", str[i]);

	gotoEnd();
}