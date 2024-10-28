#pragma once

#define WINDOW_WIDTH	100
#define WINDOW_HEIGHT	30

enum ResCode {
	OK = 0,
	ValidationError = 1,
	Default = 100,
};

void openMainWindow(void);