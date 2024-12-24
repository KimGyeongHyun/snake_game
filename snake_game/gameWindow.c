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
int counterTh = 1000;

void displayMainGameFrames(void)
{
	// display empty window
	displayEmptyWindow();

	// display game frame
	openGameFrame();

	// display game score frame
	openGameScoreFrame();
}

void openGameWindow(void)
{
	// display all game frames
	displayMainGameFrames();

	SnakeBody* snakeHead = snakeInitialize();

	addRandomApple(snakeHead);
	showApple();

	showSnake(snakeHead);

	for (;;)
	{
		gwResCode = processingGame(snakeHead, counterTh);

		if (gwResCode == DEAD) break;
	}
}