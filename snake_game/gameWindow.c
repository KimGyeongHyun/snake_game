#include <windows.h>
#include <conio.h>
#include <stdbool.h>

#include "gameSystem.h"
#include "gameWindow.h"
#include "gameFrame.h"
#include "gameScoreFrame.h"
#include "snake.h"
#include "appleSpike.h"
#include "moveResult.h"

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

	enum MoveResult res = MOVE_IDLE;

	displayEmptyWindow();

	openGameFrame();

	openGameScoreFrame();

	SnakeBody* snakeHead = snakeInitialize();

	addRandomApple(snakeHead);
	addRandomSpike(snakeHead);
	showAppleSpike();
	showSnake(snakeHead);

	for (;;)
	{
		inputChar = _getch();

		if (inputChar == UP_ARROW_CHAR ||
			inputChar == BELOW_ARROW_CHAR ||
			inputChar == LEFT_ARROW_CHAR ||
			inputChar == RIGHT_ARROW_CHAR)
		{
			// 25.02.22 return result of move
			res = move_result(&snakeHead, inputChar);
			showSnake(snakeHead);

		}
	}
}