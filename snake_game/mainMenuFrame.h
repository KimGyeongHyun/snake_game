#pragma once

#define MAIN_MENU_FRAME_X_START		40
#define MAIN_MENU_FRAME_Y_START		15
#define MAIN_MENU_FRAME_WIDTH		20
#define MAIN_MENU_FRAME_HEIGHT		10

#define MAIN_MENU_NUMBER			3

#define UP_ARROW_CHAR				72
#define BELOW_ARROW_CHAR			80

void printSelectedMenuIcon();
void changeMenuIndex(char inputChar);
void openMainMenu();