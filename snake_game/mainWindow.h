#pragma once

#define WINDOW_WIDTH	100
#define WINDOW_HEIGHT	30

#define GETCH_CHAR_ENTHER	13

// Active menu index
extern int menuIndex;

enum ResCode {
	OK = 0,
	NO = 1,
	ValidationError = 2,
	Default = 100,
};

void openMainMenuWindow(void);