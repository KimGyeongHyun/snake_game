#pragma once

#include <stdbool.h>

#include "gameFrame.h"
#include "snake.h"

#define ADD_APPLE_COUNT		7
#define ADD_SPIKE_COUNT		3

extern bool apple[GAME_FRAME_HEIGHT - 2][GAME_FRAME_WIDTH - 2];
extern bool spike[GAME_FRAME_HEIGHT - 2][GAME_FRAME_WIDTH - 2];

void initAppleAndSpike();
int countApple();
void deleteApple(int x, int y);
void addRandomApple(SnakeBody* input_SnakeHead);
void addRandomSpike(SnakeBody* input_SnakeHead);
void showAppleSpike();