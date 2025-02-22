#pragma once

#include "snake.h"

enum MoveResult
{
	MOVE_IDLE = 0,
	MOVE_JUST,
	MOVE_EAT,
	MOVE_DIE,
};

enum MoveResult move_result(SnakeBody** input_snake_body, int input_direction);