#include "gameFrame.h"
#include "gameSystem.h"

void openGameFrame(void)
{
	printSquare(GAME_FRAME_X_START, GAME_FRAME_Y_START, GAME_FRAME_WIDTH, GAME_FRAME_HEIGHT);
}

void resetGameFrame(void)
{
	printSquare(GAME_FRAME_X_START, GAME_FRAME_Y_START, GAME_FRAME_WIDTH, GAME_FRAME_HEIGHT);
	for (int i = GAME_FRAME_X_START + 1; i < GAME_FRAME_X_START + GAME_FRAME_WIDTH - 1; i++)
	{
		for (int j = GAME_FRAME_Y_START + 1; j < GAME_FRAME_Y_START + GAME_FRAME_HEIGHT - 1; j++)
		{
			printChar(i, j, ' ');
		}
	}
}