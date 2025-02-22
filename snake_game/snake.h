#pragma once

#include <stdbool.h>

#include "gameFrame.h"

// Snake head start index
#define SNAKE_START_X	50
#define SNAKE_START_Y	16

enum SnakeMoveValid
{
	SNAKE_MOVE_OK = 0,
	SNAKE_MOVE_NO,
};

typedef struct SNAKE_BODY {
	int x, y;
	struct SNAKE_BODY* next;
}SnakeBody;

enum SnakeMoveValid prev_direction;

SnakeBody* createSnakeBody(int x, int y);
int countSnake(SnakeBody* input_snakeHead);
SnakeBody* snakeInitialize();
SnakeBody* moveSnakeAndAdd(SnakeBody* input_snakeHead, char input_direction, bool add_flag);
void showSnake(SnakeBody* input_snakeHead);
void freeSnake(SnakeBody** input_snakeHead);