#ifndef MZAE_H
#define MAZE_H
#include <stdio.h>
#include <conio.h>
#include <windows.h>

/*从文件中打开地图*/
void open(char *filename);

/*欢迎界面*/
void hello(void);

/*显示地图*/
void show_map(void);

/*实现移动*/
void move(void);

/*将光标移动到当前位置*/
void gotoxy(int x, int y);

/*隐藏光标*/
void HideCursor(void);

char map[31][31] = { 0 };

void open(char *filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("File open error!");
		return;
	}
	else {
		for (int i = 0;i < 31;i++) {
			for (int j = 0;j < 31;j++) {
				fscanf(fp, "%d", &map[i][j]);
			}
		}
	}
	return;
}
void hello(void) {
	system("mode con cols=30 lines=15");
	system("cls");
	printf("***     A LITTLE MAZE      ***\n\n\n\n");
	printf("          1.play\n\n");
	printf("          2.quit\n\n\n\n\n");
	printf("***      JUST FOR FUN      ***\n\n");
	HideCursor();
	char option;
	option = getch();
	if (option == '1') {
		move();
	}
	else {
		system("cls");
		gotoxy(15, 7);
		printf("Bye~");
		return;
	}
}

void show_map(void) {
	int i, j;
	for (i = 0;i < 31;i++) {
		for (j = 0;j < 31;j++) {
			if (map[i][j] == 0) printf("  ");
			else if (map[i][j] == 1) printf("█");
			else  printf("∞");
		}
		printf("         \n");
	}
}

void move(void) {
	system("mode con cols=85 lines=33");
	system("cls");

	int count = 0;
	int x = 29, y = 29;
	show_map();

	char ch;
	do {
		ch = getch();
		if (ch == -32) {
			switch (ch = getch()) {
			case 72:ch = 'w';break;
			case 80:ch = 's';break;
			case 75:ch = 'a';break;
			case 77:ch = 'd';break;
			default:
				printf("Oh!Wrong button!");
				break;
			}
		}
		else {
			system("cls");
			printf("Are you sure you want to quit?\n");
			printf("        1.yes   2.no\n");
			if (getch() == '1') {
				printf("Bye~");
				return;
			}
			else {
				system("cls");
				show_map();
			}
		}
		if (ch == 'w'&&map[x - 1][y] == 0) {
			map[x][y] = 0;
			gotoxy(2 * y, x);
			printf("  ");
			map[x--][y] = 1;
			gotoxy(2 * y, x);
	        printf("∞");
			count++;
		}
		else if (ch == 's'&&map[x + 1][y] == 0) {
			map[x][y] = 0;
			gotoxy(2 * y, x);
			printf("  ");
			map[x++][y] = 1;
			gotoxy(2 * y, x);
			printf("∞");
			count++;
		}
		else if (ch == 'a'&&map[x][y - 1] == 0) {
			map[x][y] = 0;
			gotoxy(2 * y, x);
			printf("  ");
			map[x][y--] = 1;
			gotoxy(2 * y, x);
			printf("∞");
			count++;
		}
		else if (ch == 'd'&&map[x][y + 1] == 0) {
			map[x][y] = 0;
			gotoxy(2 * y, x);
			printf("  ");
			map[x][y++] = 1;
			gotoxy(2 * y, x);
			printf("∞");
			count++;
		}
		if (x == 29 && y == 30) {
			system("mode con cols=30 lines=15");
			system("cls");
			gotoxy(13, 6);
			printf("You win!");
			return;
		}
	} while (1);
}

void gotoxy(int x, int y) {
	HANDLE hwnd;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hwnd, coord);
	HideCursor();
}

void HideCursor(void)//度娘教的
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void refresh(int x, int y) {
	for (;y < 31;y++) {
		if (map[x][y] == 0)printf("  ");
		else if (map[x][y] == 1)printf("%c", 219);
		else printf("%c", 236);
	}
}
#endif