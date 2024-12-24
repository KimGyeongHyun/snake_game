#include <conio.h>
#include <windows.h>

#include "gameWindow.h"
#include "gameFrame.h"
#include "gameSystem.h"
#include "snake.h"
#include "apple.h"

static int counter = 0;
static char inputChar = 0;

void openGameFrame(void)
{
	printSquare(GAME_FRAME_X_START, GAME_FRAME_Y_START, GAME_FRAME_WIDTH, GAME_FRAME_HEIGHT);
}

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

enum Game_Window_ResCode processingGame(SnakeBody* input_snakeHead, int counterTh)
{

	enum Direction_Validation checkOppositeDir = DIR_NO;
	enum Game_Window_ResCode checkRes = DEFAULT;
	
	counter = 0;
	inputChar = 0;

	while (1) {
		if (_kbhit()) {
			inputChar = _getch();

			checkOppositeDir = dir_check(inputChar);

			if (checkOppositeDir == DIR_OK || counter == counterTh)
			{
				checkOppositeDir = DIR_NO;
				break;
			}
		}

		Sleep(1);
		counter++;
	}

	if (inputChar == 0) inputChar = prev_direction;

	if (inputChar == UP_ARROW_CHAR ||
		inputChar == BELOW_ARROW_CHAR ||
		inputChar == LEFT_ARROW_CHAR ||
		inputChar == RIGHT_ARROW_CHAR)
	{
		checkRes = snakeSystem(input_snakeHead, inputChar);
	}

	return checkRes;
}