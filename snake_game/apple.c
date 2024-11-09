#include <stdlib.h>
#include <time.h>

#include "apple.h"
#include "gameSystem.h"

bool apple[][GAME_FRAME_WIDTH - 2] = {false,};

void addApple(int x, int y)
{
	apple[y][x] = true;
}

void deleteApple(int x, int y)
{
	apple[y][x] = false;
}

void addRandomApple(SnakeBody* input_SnakeHead)
{
	//addApple(0, 0);
	//addApple(1, 1);
	//addApple(2, 3);
	//addApple(GAME_FRAME_WIDTH - 3, GAME_FRAME_HEIGHT - 3);

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

		if (closeSnakeFlag)
			continue;

		addApple(randX, randY);
		appleCount++;
	}
}

void showApple()
{
	for (int x = 0; x < GAME_FRAME_WIDTH - 2; x++)
	{
		for (int y = 0; y < GAME_FRAME_HEIGHT - 2; y++)
		{
			if (apple[y][x])
				printChar(x + GAME_FRAME_X_START + 1, y + GAME_FRAME_Y_START + 1, '@');
			else
				printChar(x + GAME_FRAME_X_START + 1, y + GAME_FRAME_Y_START + 1, ' ');
		}
	}
}

bool checkEatApple(int x, int y)
{
	if (apple[y - GAME_FRAME_Y_START - 1][x - GAME_FRAME_X_START - 1])
	{
		apple[y - GAME_FRAME_Y_START - 1][x - GAME_FRAME_X_START - 1] = false;
		return true;
	}
	else
	{
		return false;
	}
}