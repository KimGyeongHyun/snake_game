#include "snake.h"

#include "gameSystem.h"

#include "stdlib.h"

int snakeCount = 0;

int countSnake(SnakeBody* input_snakeHead)
{
	snakeCount = 0;
	SnakeBody* currBody = input_snakeHead;
	do
	{
		snakeCount++;
		currBody = currBody->next;
	} while (currBody != NULL);

	return snakeCount;
}

SnakeBody* createSnakeBody(int x, int y)
{
	SnakeBody* newSnakeBody = (SnakeBody*)malloc(sizeof(SnakeBody));

	if (newSnakeBody == NULL)
	{
		// TODO - add exception alart
		exit(1);
	}

	newSnakeBody->x = x;
	newSnakeBody->y = y;
	newSnakeBody->next = NULL;
	return newSnakeBody;
}

SnakeBody* snakeInitialize()
{
	SnakeBody* init_snakeHead = createSnakeBody(SNAKE_START_X, SNAKE_START_Y);
	SnakeBody* currBody = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 1);
	SnakeBody* currBody2 = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 2);
	SnakeBody* currBody3 = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 3);

	init_snakeHead->next = currBody;
	currBody->next = currBody2;
	currBody2->next = currBody3;

	return init_snakeHead;
}

void expandSnake(SnakeBody* input_snakeHead)
{
	SnakeBody* currBody = input_snakeHead;
	do
	{
		currBody = currBody->next;
	} while (currBody->next != NULL);

	SnakeBody* snakeTail = createSnakeBody(currBody->x, currBody->y);
	currBody->next = snakeTail;
}

void moveSnake(SnakeBody* input_snakeHead, char direction)
{
	SnakeBody* currBody = input_snakeHead;
	int currX = currBody->x;
	int currY = currBody->y;
	int prevX, prevY;

	if (direction == UP_ARROW_CHAR)
		currBody->y--;
	if (direction == BELOW_ARROW_CHAR)
		currBody->y++;
	if (direction == LEFT_ARROW_CHAR)
		currBody->x--;
	if (direction == RIGHT_ARROW_CHAR)
		currBody->x++;

	currBody = currBody->next;

	do
	{
		// Save position of current 
		prevX = currX;
		prevY = currY;

		// Save position of next
		currX = currBody->x;
		currY = currBody->y;

		// Update position to current
		currBody->x = prevX;
		currBody->y = prevY;

		// Move to next object
		currBody = currBody->next;

	} while (currBody != NULL);
}

void showSnake(SnakeBody* input_snakeHead)
{
	SnakeBody* currBody = input_snakeHead;
	int tailX, tailY;
	do
	{
		printChar(currBody->x, currBody->y, 'O');

		tailX = currBody->x;
		tailY = currBody->y;

		currBody = currBody->next;
	} while (currBody != NULL);
	
	printChar(tailX, tailY, ' ');
}

void freeSnake()
{

}

void snakeSystem(SnakeBody* input_snakeHead, char direction)
{
	moveSnake(input_snakeHead, direction);
	showSnake(input_snakeHead);
}