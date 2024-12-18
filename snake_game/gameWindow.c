#include <windows.h>
#include <conio.h>
#include <stdbool.h>

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
enum Game_Window_ResCode gwResCode;
enum Direction_Validation dirResCode;

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
	displayEmptyWindow();

	openGameFrame();

	openGameScoreFrame();

	SnakeBody* snakeHead = snakeInitialize();

	addRandomApple(snakeHead);
	showApple();

	showSnake(snakeHead);

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
			gwResCode = snakeSystem(snakeHead, inputChar, apple);
			if (gwResCode == DEAD)
			{
				freeSnake(snakeHead);
				break;
			}
		}
	}
}