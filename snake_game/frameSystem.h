#pragma once

// Move cursor to (x, y)
void gotoxy(int x, int y);

// Move cursor to end
void gotoEnd();

// print char in (x, y)
void printChar(int x, int y, char c);

// draw frame
void printSquare(int inputX, int inputY, int inputWidth, int inputHeight);

void printString(int inputX, int inputY, char str[], int strLength);