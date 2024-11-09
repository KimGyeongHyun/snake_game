#pragma once

enum Game_Window_ResCode {
	SURVIVE = 0,
	DEAD = 1,
	DEFAULT = 10,
};

enum Direction_Validation {
	DIR_OK = 0,
	DIR_NO = 1,
};

void openGameWindow(void);