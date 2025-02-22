#include <stdlib.h>
#include <stdbool.h>

#include "snake.h"
#include "gameSystem.h"
#include "gameWindow.h"

int snakeCount = 0;

static int countSnake(SnakeBody* input_snakeHead)
{
	snakeCount = 0;
	SnakeBody* currBody = input_snakeHead;
	do
	{
		snakeCount++;
		currBody = currBody->next;
	} while (currBody->next != NULL);

	return snakeCount;
}

static SnakeBody* returnTail(SnakeBody* input_snakeHead)
{
	SnakeBody* currBody = input_snakeHead;

	do
	{
		currBody = currBody->next;
	} while (currBody->next != NULL);

	return currBody;
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
	SnakeBody* Body1 = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 1);
	SnakeBody* Body2 = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 2);
	SnakeBody* Body3 = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 3);

	char prev_direction = UP_ARROW_CHAR;

	init_snakeHead->next = Body1;
	Body1->next = Body2;
	Body2->next = Body3;

	return init_snakeHead;
}

enum SnakeMoveValid snakeMoveValidCheck(char input_direction)
{
	switch (input_direction)
	{
	case UP_ARROW_CHAR:
		if (prev_direction == BELOW_ARROW_CHAR)	return SNAKE_MOVE_NO;
		else									return SNAKE_MOVE_OK;
		break;
	case BELOW_ARROW_CHAR:
		if (prev_direction == UP_ARROW_CHAR)	return SNAKE_MOVE_NO;
		else									return SNAKE_MOVE_OK;
		break;
	case LEFT_ARROW_CHAR:
		if (prev_direction == RIGHT_ARROW_CHAR)	return SNAKE_MOVE_NO;
		else									return SNAKE_MOVE_OK;
		break;
	case RIGHT_ARROW_CHAR:
		if (prev_direction == LEFT_ARROW_CHAR)	return SNAKE_MOVE_NO;
		else									return SNAKE_MOVE_OK;
		break;
	default:
		return SNAKE_MOVE_NO;
	}
}

void deleteSnakeTail(SnakeBody* input_snakeHead)
{
	while ((input_snakeHead)->next->next != NULL)
	{
		(input_snakeHead) = (input_snakeHead)->next;
	}
	free((input_snakeHead)->next);
	(input_snakeHead)->next = NULL;
}

SnakeBody* moveSnakeAndAdd(SnakeBody* input_snakeHead, char input_direction, bool add_flag)
{
	enum SnakeMoveValid moveValidFlag = snakeMoveValidCheck(input_direction);

	if (moveValidFlag == SNAKE_MOVE_NO)
		return input_snakeHead;
	else
		prev_direction = input_direction;

	int currX = input_snakeHead->x;
	int currY = input_snakeHead->y;

	switch (input_direction)
	{
	case UP_ARROW_CHAR:
		currY--;
		break;
	case BELOW_ARROW_CHAR:
		currY++;
		break;
	case LEFT_ARROW_CHAR:
		currX--;
		break;
	case RIGHT_ARROW_CHAR:
		currX++;
		break;
	}

	SnakeBody* new_head = createSnakeBody(currX, currY);
	new_head->next = input_snakeHead;

	// if (!add_flag)
	deleteSnakeTail(new_head);

	return new_head;
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
	} while (currBody->next != NULL);
	printChar(currBody->x, currBody->y, ' ');
}

void freeSnake(SnakeBody** input_snakeHead)
{
	if (*input_snakeHead == NULL)
	{
		return;
	}
	
	if ((*input_snakeHead)->next != NULL)
	{
		freeSnake((*input_snakeHead)->next);
	}
	free(*input_snakeHead);
	*input_snakeHead = NULL;
}