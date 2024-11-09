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

void addRandomApple()
{
	addApple(0, 0);
	addApple(1, 1);
	addApple(2, 3);
	addApple(GAME_FRAME_WIDTH - 3, GAME_FRAME_HEIGHT - 3);
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