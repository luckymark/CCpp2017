/*Maze*/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "map.h"  //include function: void print_map(void);

#define START_ROW 2
#define START_COL 3

enum DIRECTION{UP, DOWN, LEFT, RIGHT, STILL};
enum Bool{False, True}; //error: can't declarate FALSE or TRUE
int row = START_ROW, col = START_COL;

enum DIRECTION get_dir(void);
enum Bool move(void);

int main(void)
{
	print_map();
	while (move())
		;
	print_success();
	
	return 0;
}

enum DIRECTION get_dir(void)
{
	char dir1, dir2;
	
	dir1 = (int)getch();
	dir2 = (int)getch();
	if (dir1 == 0)
		switch (dir2){
			case 72: return UP;
			case 80: return DOWN;
			case 77: return RIGHT;
			case 75: return LEFT;
			default: return STILL;
		}
		
	return STILL;
}

enum Bool move(void)
{
	enum DIRECTION dir;
	int c_row = row, c_col = col;
	
	dir = get_dir();
	switch (dir){
		case UP: c_row = row - 1; break;
		case DOWN: c_row = row + 1; break;
		case RIGHT: c_col = col + 2; break;
		case LEFT: c_col = col - 2; break;
	}
	if (map[c_row - 1][c_col - 1] == 0){
		gotoxy(col, row);
		printf("  ");
		row = c_row;
		col = c_col;
		gotoxy(col, row);
		textcolor(RED);
		cprintf("●");
		if (row == 22 && col == 47)
			return False;
		else
			return True;
	}
	else
		return True;
}
