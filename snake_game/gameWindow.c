#include <windows.h>
#include <conio.h>

#include "gameSystem.h"
#include "gameWindow.h"
#include "gameFrame.h"
#include "gameScoreFrame.h"
#include "snake.h"
#include "apple.h"

// Scores
int currentScore = 0;
int highScore = 0;
char inputChar;
enum Game_Window_ResCode resCode;
enum Direction_Validation dirResCode;

int testInt = 0;

enum Direction_Validation dir_check(char inputChar)
{
	switch (prev_direction)
	{
	case UP_ARROW_CHAR:
		if (inputChar == BELOW_ARROW_CHAR)
			return DIR_NO;
		else
			return DIR_OK;
		break;
	case BELOW_ARROW_CHAR:
		if (inputChar == UP_ARROW_CHAR)
			return DIR_NO;
		else
			return DIR_OK;
		break;
	case LEFT_ARROW_CHAR:
		if (inputChar == RIGHT_ARROW_CHAR)
			return DIR_NO;
		else
			return DIR_OK;
		break;
	case RIGHT_ARROW_CHAR:
		if (inputChar == LEFT_ARROW_CHAR)
			return DIR_NO;
		else
			return DIR_OK;
		break;
	}

	return DIR_NO;
}

void openGameWindow(void)
{
	displayFrame();

	openGameFrame();

	openGameScoreFrame();

	SnakeBody* snakeHead = snakeInitialize();

	showSnake(snakeHead);

	// For Test
	addRandomApple();
	showApple();

	for (;;)
	{
		inputChar = _getch();

		dirResCode = dir_check(inputChar);

		if (dirResCode == DIR_NO)
			continue;

		if (inputChar == UP_ARROW_CHAR ||
			inputChar == BELOW_ARROW_CHAR ||
			inputChar == LEFT_ARROW_CHAR ||
			inputChar == RIGHT_ARROW_CHAR)
		{
			resCode = snakeSystem(snakeHead, inputChar);
			if (resCode == DEAD)
			{
				freeSnake(snakeHead);
				break;
			}
		}
		
	}
}