#include <windows.h>
#include <conio.h>

#include "gameSystem.h"
#include "gameWindow.h"
#include "gameFrame.h"
#include "gameScoreFrame.h"
#include "snake.h"

// Scores
int currentScore = 0;
int highScore = 0;
char inputChar;

int testInt = 0;

void openGameWindow(void)
{
	displayFrame();

	openGameFrame();

	openGameScoreFrame();

	SnakeBody* snakeHead = snakeInitialize();

	showSnake(snakeHead);

	for (;;)
	{
		inputChar = _getch();

		if (inputChar == UP_ARROW_CHAR ||
			inputChar == BELOW_ARROW_CHAR ||
			inputChar == LEFT_ARROW_CHAR ||
			inputChar == RIGHT_ARROW_CHAR)
		{
			snakeSystem(snakeHead, inputChar);
			testInt = countSnake(snakeHead);
		}
		
	}
}