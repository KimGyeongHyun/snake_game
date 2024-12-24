#pragma once

#include "snake.h"

#define GAME_FRAME_X_START		34
#define GAME_FRAME_Y_START		12
#define GAME_FRAME_WIDTH		32
#define GAME_FRAME_HEIGHT		16

enum Game_Window_ResCode processingGame(SnakeBody* input_snakeHead, int counterTh);
void openGameFrame(void);