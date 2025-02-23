#include <stdlib.h>
#include <time.h>

#include "appleSpike.h"
#include "gameSystem.h"

bool apple[][GAME_FRAME_WIDTH - 2] = {false, };
bool spike[][GAME_FRAME_WIDTH - 2] = { false, };

void initAppleAndSpike()
{
	for (int x = 0; x < GAME_FRAME_WIDTH - 2; x++)
	{
		for (int y = 0; y < GAME_FRAME_HEIGHT - 2; y++)
		{
			apple[y][x] = false;
			spike[y][x] = false;
		}
	}
}

void addApple(int x, int y)
{
	apple[y][x] = true;
}

void deleteApple(int x, int y)
{
	apple[y][x] = false;
}

void addSpike(int x, int y)
{
	spike[y][x] = true;
}

int countApple()
{
	int appleCount = 0;
	for (int i = 0; i < GAME_FRAME_WIDTH - 2; i++)
	{
		for (int j = 0; j < GAME_FRAME_HEIGHT - 2; j++)
		{
			if (apple[j][i])	appleCount++;
		}
	}

	return appleCount;
}

void addRandomApple(SnakeBody* input_SnakeHead)
{
	int randX, randY;
	bool closeSnakeFlag;
	SnakeBody* currBody;
	int appleCount = 0;

	srand((unsigned int)time(NULL));

	while (appleCount < ADD_APPLE_COUNT)
	{
		closeSnakeFlag = false;
		currBody = input_SnakeHead;		

		randX = rand() % (GAME_FRAME_WIDTH - 2);
		randY = rand() % (GAME_FRAME_HEIGHT - 2);
		if (apple[randY][randX] || spike[randY][randX]) closeSnakeFlag = true;

		if (closeSnakeFlag)	continue;

		do
		{
			if ((currBody->x - 1 <= randX && randX <= currBody->x + 1) &&
				(currBody->y - 1 <= randY && randY <= currBody->y + 1))
			{
				closeSnakeFlag = true;
				break;
			}
			
			currBody = currBody->next;
		} while (currBody != NULL);

		if (closeSnakeFlag)	continue;

		addApple(randX, randY);
		appleCount++;
	}
}

void addRandomSpike(SnakeBody* input_SnakeHead)
{
	int randX, randY;
	bool closeSnakeFlag;
	SnakeBody* currBody;
	int appleCount = 0;

	srand((unsigned int)time(NULL));

	while (appleCount < ADD_SPIKE_COUNT)
	{
		closeSnakeFlag = false;
		currBody = input_SnakeHead;

		randX = rand() % (GAME_FRAME_WIDTH - 2);
		randY = rand() % (GAME_FRAME_HEIGHT - 2);

		if (apple[randY][randX] || spike[randY][randX]) closeSnakeFlag = true;

		if (closeSnakeFlag)	continue;

		do
		{
			if ((currBody->x - 1 <= randX && randX <= currBody->x + 1) &&
				(currBody->y - 1 <= randY && randY <= currBody->y + 1))
			{
				closeSnakeFlag = true;
				break;
			}

			currBody = currBody->next;
		} while (currBody != NULL);

		if (closeSnakeFlag)	continue;

		addSpike(randX, randY);
		appleCount++;
	}
}

void showAppleSpike()
{
	for (int x = 0; x < GAME_FRAME_WIDTH - 2; x++)
	{
		for (int y = 0; y < GAME_FRAME_HEIGHT - 2; y++)
		{
			if (apple[y][x])
				printChar(x + GAME_FRAME_X_START + 1, y + GAME_FRAME_Y_START + 1, '@');
			else if (spike[y][x])
				printChar(x + GAME_FRAME_X_START + 1, y + GAME_FRAME_Y_START + 1, '*');
		}
	}
}
