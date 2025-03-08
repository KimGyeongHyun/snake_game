#include <stdlib.h>

#include "gameFrame.h"
#include "gameSystem.h"

void openGameFrame(void)
{
	printSquare(GAME_FRAME_X_START, GAME_FRAME_Y_START, GAME_FRAME_WIDTH, GAME_FRAME_HEIGHT);
}

void resetGameFrame(void)
{
	openGameFrame();
	char* blankStr = (char *)malloc(sizeof(char) * (GAME_FRAME_X_START - 2));
	if (blankStr == NULL)
	{
		exit(2);
	}
	for (int i = 0; i < GAME_FRAME_X_START - 2; i++)	blankStr[i] = ' ';

	for (int j = GAME_FRAME_Y_START + 1; j < GAME_FRAME_Y_START + GAME_FRAME_HEIGHT - 1; j++)
	{
		gotoxy(GAME_FRAME_X_START + 1, j);

	}
	free(blankStr);
}