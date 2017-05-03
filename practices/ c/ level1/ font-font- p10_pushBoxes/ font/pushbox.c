#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define SIZE 9
int intmaze[SIZE][SIZE]; 
void print_map();
void scanfmap();
void move(int nn);
void main()
{
	scanfmap();
	move(SIZE);
	system("pause");
}

void scanfmap()
{
	FILE *p;
	p =fopen("level1.txt", "r");
	for (int i = 0; i < SIZE; i++) {
		for (int j= 0; j < SIZE; j++) {
			fscanf(p, "%d", &intmaze[i][j]);
		}
	}
	fclose(p);
}
void print_map()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (intmaze[i][j] == 0) {
				intmaze[i][j] = ' ';		//空格
			}if (intmaze[i][j] == 1) {
				intmaze[i][j] = '*';		//墙壁
			}if (intmaze[i][j] == 9) {
				intmaze[i][j] = 'P';		//人
			}if (intmaze[i][j]== 2) {
				intmaze[i][j] = '@';		//目的地;
			}if (intmaze[i][j]== 3) {
				intmaze[i][j] = '#';		//箱子
			}
		}
	}
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			printf("%c", intmaze[i][j]);
		}
		printf("\n");
	}
}

void move(int nn)
{
	int x = 4, y = 4;
	char walk;
	while (1) {
		print_map();
		walk = _getch();
		if (walk == 'w') {
			if ((intmaze[x - 1][y] == ' ') && (x>0)) {
				intmaze[x - 1][y] = 9;
				intmaze[x][y] = 0;
				x--;
			}
			else if ((intmaze[x - 1][y] == '#') && (intmaze[x - 2][y] != '*') && (x > 1)) {
				intmaze[x - 1][y] = 9;
				intmaze[x - 2][y] = 3;
				intmaze[x][y] = 0;
				x--;
			}
		}
		if (walk == 's') {
			if ((intmaze[x + 1][y] == ' ') && (x < nn - 1)) {
				intmaze[x + 1][y] = 9;
				intmaze[x][y] = 0;
				x++;
			}
			else if ((intmaze[x + 1][y] == '#') && (intmaze[x + 2][y] != '*') && (x < nn - 2)) {
				intmaze[x + 1][y] = 9;
				intmaze[x + 2][y] = 3;
				intmaze[x][y] = 0;
				x++;
			}
		}
		if (walk == 'a'){
			if ((intmaze[x][y - 1] == ' ') && (y > 0)) {
				intmaze[x][y - 1] = 9;
				intmaze[x][y] = 0;
				y--;
			}
			else if ((intmaze[x][y - 1] == '#') && (intmaze[x][y - 2] != '*') && (y>1)) {
				intmaze[x][y - 1] = 9;
				intmaze[x][y - 2] = 3;
				intmaze[x][y] = 0;
				y--;
			}
	}
		if (walk == 'd') {
			if ((intmaze[x][y + 1] == ' ') && (y < nn - 1)) {
				intmaze[x][y + 1] = 9;
				intmaze[x][y] = 0;
				y++;
			}
			else if ((walk == 'd') && (intmaze[x][y + 1] == '#') && (intmaze[x][y + 2] != '*') && (y < nn - 2)) {
				intmaze[x][y + 1] = 9;
				intmaze[x][y + 2] = 3;
				intmaze[x][y] = 0;
				y++;
			}
		}
		system("cls");
		if (intmaze[1][4] != '@' && intmaze[4][1] != '@' && intmaze[7][4] != '@' && intmaze[4][7] != '@') {
			printf("YOU WIN\n");
			break;
		}
	}
}
