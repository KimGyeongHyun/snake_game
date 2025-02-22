#include "moveResult.h"
#include "gameSystem.h"
#include "snake.h"
#include "appleSpike.h"

enum MoveResult move_result(SnakeBody** input_snake_body, int input_direction)
{
	enum MoveResult res = MOVE_IDLE;
	*input_snake_body = moveSnakeAndAdd(*input_snake_body, input_direction, false);



	return res;
}