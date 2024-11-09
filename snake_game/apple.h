#pragma once

#include <stdbool.h>

#include "gameFrame.h"
#include "snake.h"

#define ADD_APPLE_COUNT		7

extern bool apple[GAME_FRAME_HEIGHT - 2][GAME_FRAME_WIDTH - 2];

void addRandomApple(SnakeBody* input_SnakeHead);
void showApple();
bool checkEatApple(int x, int y);