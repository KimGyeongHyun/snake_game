#pragma once

// Snake head start index
#define SNAKE_START_X	15
#define SNAKE_START_Y	15

typedef struct SNAKE_BODY {
	int x, y;
	struct SNAKE_BODY* next;
}SnakeBody;

int countSnake(SnakeBody* input_snakeHead);
SnakeBody* snakeInitialize();
void showSnake(SnakeBody* input_snakeHead);
void snakeSystem(SnakeBody* input_snakeHead, char direction);