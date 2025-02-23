#pragma once

#include "snake.h"

enum MoveResult
{
	MOVE_IDLE = 0,
	MOVE_INVALID,
	MOVE_EAT,
	MOVE_DIE,
	MOVE_ADD_APPLE_AND_SPIKE,
};

enum MoveResult move_result(SnakeBody** input_snake_body, int input_direction);