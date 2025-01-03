#include <stdlib.h>
#include <stdbool.h>

#include "snake.h"
#include "gameSystem.h"
#include "gameWindow.h"
#include "apple.h"

// snake length
static int snakeCount = 0;

// snake prevent direction
char prev_direction = UP_ARROW_CHAR;

// return snake length
int countSnake(SnakeBody* input_snakeHead)
{
	
	snakeCount = 0;
	SnakeBody* currBody = input_snakeHead;

	// count snake body
	do
	{
		snakeCount++;
		currBody = currBody->next;
	} while (currBody != NULL);

	return snakeCount;
}

// create one snake body and return
SnakeBody* createSnakeBody(int x, int y)
{
	SnakeBody* newSnakeBody = (SnakeBody*)malloc(sizeof(SnakeBody));

	if (newSnakeBody == NULL)
	{
		// TODO - add exception alart
		exit(1);
	}

	// initialize and return body
	newSnakeBody->x = x;
	newSnakeBody->y = y;
	newSnakeBody->next = NULL;
	return newSnakeBody;
}

// connect body to snake tail
void connectSnake(SnakeBody* prev_tail, SnakeBody* curr_body)
{
	prev_tail->next = curr_body;
}

SnakeBody* snakeInitialize()
{
	// create bodies
	SnakeBody* init_snakeHead = createSnakeBody(SNAKE_START_X, SNAKE_START_Y);
	SnakeBody* Body1 = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 1);
	SnakeBody* Body2 = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 2);
	SnakeBody* Body3 = createSnakeBody(SNAKE_START_X, SNAKE_START_Y + 3);

	// connect bodies
	connectSnake(init_snakeHead, Body1);
	connectSnake(Body1, Body2);
	connectSnake(Body2, Body3);

	// return head
	return init_snakeHead;
}

// get arrow data and move snake
enum Game_Window_ResCode moveSnake(SnakeBody* input_snakeHead, char direction)
{

	// get snake head and initialize data
	SnakeBody* currBody = input_snakeHead;
	int currX = currBody->x;
	int currY = currBody->y;
	int prevX, prevY;
	int addSnakeFlag = false;

	if (direction == UP_ARROW_CHAR)
		currBody->y--;
	else if (direction == BELOW_ARROW_CHAR)
		currBody->y++;
	else if (direction == LEFT_ARROW_CHAR)
		currBody->x--;
	else if (direction == RIGHT_ARROW_CHAR)
		currBody->x++;

	if (checkEatApple(currBody->x, currBody->y))
		addSnakeFlag = true;

	prev_direction = direction;

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

	} while (currBody->next != NULL);

	// Save position of current 
	prevX = currX;
	prevY = currY;

	// Save position of next
	if (currBody == NULL)
	{
		exit(1);
	}
	currX = currBody->x;
	currY = currBody->y;

	// Update position to current
	currBody->x = prevX;
	currBody->y = prevY;

	if (addSnakeFlag)
	{
		SnakeBody* SnakeTail = createSnakeBody(currX, currY);
		currBody->next = SnakeTail;
	}

	return SURVIVE;
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

void freeSnake(SnakeBody* input_snakeHead)
{

}

enum Game_Window_ResCode snakeSystem(SnakeBody* input_snakeHead, char direction)
{
	enum Game_Window_ResCode resCode = moveSnake(input_snakeHead, direction);
	if (resCode == DEAD)
		return resCode;

	showSnake(input_snakeHead);

	resCode = SURVIVE;
	return resCode;
}