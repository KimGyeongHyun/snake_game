#pragma once

#define MAIN_WINDOW_WIDTH	100
#define MAIN_WINDOW_HEIGHT	30

#define GETCH_CHAR_ENTER	13

enum ResCode {
	OK = 0,
	NO = 1,
	ValidationError = 2,
	Default = 100,
};

void openMainMenuWindow(void);