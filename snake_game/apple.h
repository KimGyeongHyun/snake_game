#pragma once

#include "gameFrame.h"
#include <stdbool.h>
#include "snake.h"

#define ADD_APPLE_COUNT		7

extern bool apple[GAME_FRAME_HEIGHT-2][GAME_FRAME_WIDTH-2];

void addRandomApple(SnakeBody* input_SnakeHead);
void showApple();