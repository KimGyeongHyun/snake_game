#pragma once

#include "gameFrame.h"
#include <stdbool.h>

extern bool apple[GAME_FRAME_HEIGHT-2][GAME_FRAME_WIDTH-2];

void addRandomApple();
void showApple();