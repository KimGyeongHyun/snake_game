#pragma once

typedef struct {
	int headX;
	int headY;
	int direction;
	int length;
}st_snake;

typedef struct {
	snake_body* nextBody;
	int bodyX;
	int bodyY;
}snake_body;



void openGameWindow(void);