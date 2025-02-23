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

// init apple, spike, snake
static SnakeBody* initGameParameter()
{
	SnakeBody* snakeHead = snakeInitialize();

	initAppleAndSpike();
	addRandomApple(snakeHead);
	addRandomSpike(snakeHead);
	return snakeHead;
}

// init show apple, spike, snake
static void showGameObject(SnakeBody* input_snake_body)
{
	showAppleSpike();
	showSnake(input_snake_body);
}

void openGameWindow(void)
{
	enum MoveResult res = MOVE_IDLE;

	displayEmptyWindow();

	openGameFrame();

	openGameScoreFrame();

	SnakeBody* snakeHead = initGameParameter();

	showGameObject(snakeHead);


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

			if (res == MOVE_DIE)	
				break;

			showGameObject(snakeHead);

		}
	}
}