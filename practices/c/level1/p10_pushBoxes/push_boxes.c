#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "map_push_boxes.h"
/*♂*/
enum DIRECTION get_dir(void);
enum DIRECTION{UP, DOWN, LEFT, RIGHT, STILL};
enum Bool{False, True};
int row, col;

enum Bool move(int map[][WIDTH1], int num_boxes, int boxes[][2]);
void redisp(int num_boxes, int boxes[][2], int right_place[][2]);
void run(int chap, int map[][WIDTH1], int high, int width, int right_place[][2], int boxes[][2], int *start, int num_boxes);

int main(void)
{
	run(1, map2, HIGH2, WIDTH2, right_place2, boxes2, start2, NUM_RIGHT_PLACE2);
	run(2, map3, HIGH3, WIDTH3, right_place3, boxes3, start3, NUM_RIGHT_PLACE3);
	run(3, map1, HIGH1, WIDTH1, right_place1, boxes1, start1, NUM_RIGHT_PLACE1);

	return 0;
}

enum Bool move(int map[][WIDTH1], int num_boxes, int boxes[][2], int right_place[][2])
{
	enum DIRECTION dir;
	int c_row = row, c_col = col;
	int b_row, b_col;
	
	dir = get_dir();
	switch (dir){
		case UP: c_row = row - 1; break;
		case DOWN: c_row = row + 1; break;
		case RIGHT: c_col = col + 2; break;
		case LEFT: c_col = col - 2; break;
	}
	if (map[c_row - 1][c_col - 1] == 0){
		for (int i = 0; i < num_boxes; i++){
			if ((b_row = boxes[i][0]) == c_row && (b_col = boxes[i][1]) == c_col){
				switch (dir){
					case UP: b_row = c_row - 1; break;
					case DOWN: b_row = c_row + 1; break;
					case RIGHT: b_col = c_col + 2; break;
					case LEFT: b_col = c_col - 2; break;
				}
				if (map[b_row - 1][b_col - 1] == 0){
					for (int j = 0; j < num_boxes; j++){
						if (b_row == boxes[j][0] && b_col == boxes[j][1]){
							return True;
						}
					}
					boxes[i][0] = b_row;
					boxes[i][1] = b_col;
					textcolor(YELLOW);
					gotoxy(b_col, b_row);
					cprintf("■");
				}
				else
					return True;
			}
		}
		gotoxy(col, row);
		printf("  ");
		row = c_row;
		col = c_col;
		gotoxy(col, row);
		textcolor(YELLOW);
		cprintf("♂");
		step++;
		gotoxy(6, 10);
		textcolor(GREEN);
		printf("Step: ");
		cprintf("%d", step);
		redisp(num_boxes, boxes, right_place);
		return True;
	}
	else
		return True;
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


void redisp(int num_boxes, int boxes[][2], int right_place[][2])
{
	enum Bool value;
	
	for (int i = 0; i < num_boxes; i++){
		value = True;
		for (int j = 0; j < num_boxes; j++){
			if (boxes[j][0] == right_place[i][0] && boxes[j][1] == right_place[i][1]){
				value = False;
				break;
			}
			if (col == right_place[i][1] && row == right_place[i][0]){
				value = False;
				break;
			}
		}
		if (value){
			gotoxy(right_place[i][1], right_place[i][0]);
			textcolor(GREEN);
			cprintf("□");
		}
	}
}

void run(int chap, int map[][WIDTH1], int high, int width, int right_place[][2], int boxes[][2], int *start, int num_boxes)
{
	print_begain(chap);
	step = 0;
	row = start[0];
	col = start[1];
	textcolor(YELLOW);
	gotoxy(col, row);
	cprintf("♂");
	print_map(map, high, width, right_place, boxes, start, num_boxes);
	while (move(map, num_boxes, boxes, right_place)){
		num_right_place = 0;
		for (int i = 0; i < num_boxes; i++){
			for (int j = 0; j < num_boxes; j++){
				if (boxes[i][0] == right_place[j][0] && boxes[i][1] == right_place[j][1])
					num_right_place++;
			}
		}
		if (num_right_place == num_boxes)
			return;
	}
}
