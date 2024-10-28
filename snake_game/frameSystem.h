#pragma once

// Move cursor to (x, y)
void gotoxy(int x, int y);

// Move cursor to end
void gotoEnd();

// print char in (x, y)
void displayCharInXY(int x, int y, char c);

// draw frame
void printSquare(int inputWidth, int inputHeight, int inputX, int inputY);