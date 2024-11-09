#pragma once

// Snake head start index
#define SNAKE_START_X	50
#define SNAKE_START_Y	16

typedef struct SNAKE_BODY {
	int x, y;
	struct SNAKE_BODY* next;
}SnakeBody;

extern char prev_direction;

int countSnake(SnakeBody* input_snakeHead);
SnakeBody* snakeInitialize();
void showSnake(SnakeBody* input_snakeHead);
void freeSnake(SnakeBody* input_snakeHead);
enum Game_Window_ResCode snakeSystem(SnakeBody* input_snakeHead, char direction);