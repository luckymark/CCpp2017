##define _CRT_SECURE_NO_WARNINGS//大神教的
#include<stdio.h>
#include<stdlib.h>

void turn_up();
void turn_down();
void turn_left();
void turn_right();
void show();

char map[22][22];
int x = 20, y = 0;
int point = 'R';

int main()
{
	int i=0, j=0;
	char *p;
	char step;
	p = map[0];
	FILE *fp;
	fp = fopen("mazemap.txt", "r");

	if (fp == NULL) {
		printf("can't open");
		exit(1);
	}

	for (;p < map[0] + 484;p++) {
		fscanf_s(fp, "%c", p);
		if ((p - map[0]) % 22 == 0) {
			i += 1;
			j = 0;
		}
		j++;
	}
	map[x][y] = 'R';;
	show();

	while (x > 0 || y < 20) {
		step = _getch();
		switch (step) {
		case 'w': {
			turn_up();
			break;
		}
		case 'a': {
			turn_left();
			break;
		}
		case 'd': {
			turn_right();
			break;
		}
		case 's': {
			turn_down();
			break;
		}
		}
	}
	system("cls");
	printf("             That's  cool , you  have  win!\n");
	getchar();
}


void show()
{
	for (int i = 0;i < 22;i++) {
		for (int j = 0;j < 22;j++) {
			printf("%c", map[i][j]);
			if (j == 21)printf("\n");
		}
	}
}


void turn_up()
{
	if (map[x - 1][y] != '*') {
		map[x][y] = ' ';
		map[x - 1][y] = point;
		system("cls");
		show();
		x = x - 1;
	}
}


void turn_left()
{
	if (map[x][y - 1] != '*') {
		map[x][y] = ' ';
		map[x][y - 1] = point;
		system("cls");
		show();
		y = y - 1;
	}
}


void turn_right()
{
	if (map[x][y + 1] != '*') {
		map[x][y] = ' ';
		system("CLS");
		map[x][y + 1] = point;
		show();
		y = y + 1;
	}
}


void turn_down()
{
	if (map[x + 1][y] != '*') {
		map[x][y] = ' ';
		map[x + 1][y] = point;
		system("cls");
		show();
		x += 1;
	}
}
