#pragma once

#define UP_ARROW_CHAR				72
#define BELOW_ARROW_CHAR			80
#define LEFT_ARROW_CHAR				75
#define RIGHT_ARROW_CHAR			77

// Print getchar value
void printGetchar(void);

// Move cursor to (x, y)
void gotoxy(int x, int y);

// Move cursor to end
void gotoEnd();

// print char in (x, y)
void printChar(int x, int y, char c);

// print empty frame
void displayFrame(void);

// draw frame
void printSquare(int inputX, int inputY, int inputWidth, int inputHeight);

void printString(int inputX, int inputY, char str[], int strLength);