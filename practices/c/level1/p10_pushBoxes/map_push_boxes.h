#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define HIGH1 7
#define WIDTH1 16
#define HIGH2 8
#define WIDTH2 16
#define HIGH3 7
#define WIDTH3 16
#define NUM_RIGHT_PLACE1 6
#define NUM_RIGHT_PLACE2 4
#define NUM_RIGHT_PLACE3 6

int map1[HIGH1][WIDTH1] = {0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 
													1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 
													1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
													1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
													1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
													1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 
													0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
int map2[HIGH2][WIDTH2] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 
													0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 
													0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 
													1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
													1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 
													1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 
													0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 
													0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
int map3[HIGH3][WIDTH3] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
													1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 
													1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
													1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 
													1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 
													1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 
													1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
int right_place1[NUM_RIGHT_PLACE1][2] = {{4, 3}, {4, 5}, {4, 7}, {4, 9}, {4, 11}, {4, 13}};
int right_place2[NUM_RIGHT_PLACE2][2] = {{2, 7}, {4, 13}, {5, 3}, {7, 9}};
int right_place3[NUM_RIGHT_PLACE3][2] = {{3, 7}, {3, 9}, {4, 7}, {4, 9}, {5, 7}, {5, 9}};
int boxes1[NUM_RIGHT_PLACE1][2] = {{3, 5}, {3, 9}, {3, 11}, {5, 5}, {5, 9}, {5, 11}};
int boxes2[NUM_RIGHT_PLACE2][2] = {{4, 7}, {4, 11}, {5, 7}, {6, 9}};
int boxes3[NUM_RIGHT_PLACE3][2] = {{3, 5}, {3, 11}, {4, 5}, {4, 11}, {5, 5}, {5, 11}};
int start1[2] = {2, 5};
int start2[2] = {5, 9};
int start3[2] = {2, 3};
int num_right_place,  step = 0;


void print_map(int map[][WIDTH1], int high, int width, int right_place[][2], int boxes[][2], int *start, int num_boxes)
{
	clrscr();
	textcolor(RED);
	for (int i = 0; i < high; i++){
		for (int j = 0; j < width; j += 2){
			if (map[i][j] == 1)
				cprintf("■");
			else
				printf("  ");
		}
		printf("\n");
	}	
	for (int i = 0; i < num_boxes; i++){
		gotoxy(right_place[i][1], right_place[i][0]);
		textcolor(GREEN);
		cprintf("□");
		gotoxy(boxes[i][1], boxes[i][0]);
		textcolor(YELLOW);
		cprintf("■");
	}
	gotoxy(start[1], start[0]);
	cprintf("♂");
	gotoxy(6, 10);
	textcolor(GREEN);
	printf("Step: ");
	cprintf("0");
}

void print_begain(int chap)
{
	clrscr();
	gotoxy(37, 13);
	printf("Chapter %d", chap);
	Sleep(400);
	clrscr();	
}
