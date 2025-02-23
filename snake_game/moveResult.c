#include "moveResult.h"
#include "gameSystem.h"
#include "snake.h"
#include "appleSpike.h"

static void gameEnd(SnakeBody** input_snake_body)
{
	freeSnake(input_snake_body);
}

static NewHeadXY returnHeadXY(SnakeBody* input_snake_body, char input_direction)
{
	NewHeadXY headXY = { 0, };

	headXY.x = input_snake_body->x;
	headXY.y = input_snake_body->y;

	switch (input_direction)
	{
	case UP_ARROW_CHAR:
		headXY.y--;
		break;
	case BELOW_ARROW_CHAR:
		headXY.y++;
		break;
	case LEFT_ARROW_CHAR:
		headXY.x--;
		break;
	case RIGHT_ARROW_CHAR:
		headXY.x++;
		break;
	}

	return headXY;
}

static enum MoveResult checkMoveSpike(NewHeadXY input_xy)
{

	if (spike[input_xy.y - GAME_FRAME_Y_START-1][input_xy.x - GAME_FRAME_X_START-1]) return MOVE_DIE;

	return MOVE_IDLE;
}

static enum MoveResult checkMoveWall(NewHeadXY input_xy)
{
	if (input_xy.x <= GAME_FRAME_X_START ||
		input_xy.x >= GAME_FRAME_X_START + GAME_FRAME_WIDTH - 1 ||
		input_xy.y <= GAME_FRAME_Y_START ||
		input_xy.y >= GAME_FRAME_Y_START + GAME_FRAME_HEIGHT - 1)
	{
		return MOVE_DIE;
	}
		
	return MOVE_IDLE;
}

static enum MoveResult checkMoveApple(NewHeadXY input_xy)
{
	if (apple[input_xy.y - GAME_FRAME_Y_START - 1][input_xy.x - GAME_FRAME_X_START - 1])
	{
		if (countApple() <= ADD_SPIKE_COUNT)
			return MOVE_ADD_APPLE_AND_SPIKE;
		else 
			return MOVE_EAT;
	}
	
	return MOVE_IDLE;
}

enum MoveResult move_result(SnakeBody** input_snake_body, int input_direction)
{
	enum MoveResult res = MOVE_IDLE;
	bool eatAppleFlag = false;

	res = checkForwardMove(input_direction);
	if (res == MOVE_INVALID)
		return MOVE_INVALID;	

	NewHeadXY headXY = returnHeadXY(*input_snake_body, input_direction);

	res = checkMoveSpike(headXY);
	if (res == MOVE_DIE)	
		return MOVE_DIE;

	res = checkMoveWall(headXY);
	if (res == MOVE_DIE)	
		return MOVE_DIE;

	res = checkMoveApple(headXY);
	if (res != MOVE_IDLE)
	{
		deleteApple(headXY.x, headXY.y);
		eatAppleFlag = true;
	}
		

	*input_snake_body = moveSnakeAndAdd(*input_snake_body, input_direction, eatAppleFlag);

	if (res == MOVE_ADD_APPLE_AND_SPIKE)
	{
		addRandomApple(*input_snake_body);
		addRandomSpike(*input_snake_body);
	}

	return res;
}

