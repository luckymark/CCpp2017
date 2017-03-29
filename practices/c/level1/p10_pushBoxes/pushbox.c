#define _CRT_SECURE_NO_WARNINGS//大神教的
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>

//从文件中读取地图时方便地图的构造
#define w 219;//墙
#define b 254;//箱子
#define l 255;//路
#define r 208;//人

void show();
void turnup();
void turndown();
void turnleft();
void turnright();


char map[8][8];
int x = 4, y = 4;
char step;

int main()
{
	int i = 0;
	char *p;
	p = map;
	FILE *fp;
	fp = fopen("pushbox_0.txt", "rb");

	if (fp == NULL) {
		printf("can't open");
		exit(1);
	}
	while (fscanf_s(fp, "%c", p) != EOF) {
		p++;
	}


	//小人、箱子初始位置
	map[x][y] = r;
	map[5][4] = b;
	map[4][3] = b;
	map[3][3] = b;
	map[3][5] = b;
	show();
	//操作判断

	do {
		step = _getch();
		putchar(step);
		switch (step)
		{
		case'w':
			turnup();
			break;
		case'a':
			turnleft();
			break;
		case's':
			turndown();
			break;
		case'd':
			turnright();
			break;
		}
	}
	//结束标志
	while ((map[4][1] != (char)254) || (map[1][3] != (char)254) || (map[3][6] != (char)254) || (map[6][4] != (char)254));
	system("cls");
	printf("you have win!\n");
	system("pause");
}


void show()
{
	system("chcp 437");
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			if (map[i][j] == 'w') {
				printf("%c", 219);
			}
			else if (map[i][j] == 'l' || map[i][j] == ' ') {
				printf("%c", 255);
			}
			else
				printf("%c", map[i][j]);
			if (j == 7) {
				printf("\n");
			}
		}
	}
}




void turnup()
{
	if ((map[x - 1][y] == (char)254) && (map[x - 2][y] == 'l'))
	{
		system("cls");
		map[x][y] = 'l';
		map[x - 1][y] = 208;
		map[x - 2][y] = 254;
		x -= 1;
		show();
	}
	else if (map[x - 1][y] == 'l') {
		system("cls");
		map[x][y] = 'l';
		map[x - 1][y] = 208;
		x -= 1;
		show();
	}
}

void turndown()
{
	if ((map[x + 1][y] == (char)254) && (map[x + 2][y] == 'l'))
	{
		putchar(step);
		system("cls");
		map[x][y] = 'l';
		map[x + 1][y] = 208;
		map[x + 2][y] = 254;
		x += 1;
		show();
	}
	else if (map[x + 1][y] == 'l') {
		system("cls");
		map[x][y] = 'l';
		map[x + 1][y] = 208;
		x += 1;
		show();
	}
}

void turnleft()
{
	if ((map[x][y - 1] == (char)254) && (map[x][y - 2] == 'l'))
	{
		system("cls");
		map[x][y] = 'l';
		map[x][y - 1] = 208;
		map[x][y - 2] = 254;
		y -= 1;
		show();
	}
	else if (map[x][y - 1] == 'l') {
		system("cls");
		map[x][y] = 'l';
		map[x][y - 1] = 208;
		y -= 1;
		show();
	}
}

void turnright()
{
	if ((map[x][y + 1] == (char)254) && (map[x][y + 2] == 'l'))
	{
		system("cls");
		map[x][y] = 'l';
		map[x][y + 1] = 208;
		map[x][y + 2] = 254;
		y += 1;
		show();
	}
	else if (map[x][y + 1] == 'l') {
		system("cls");
		map[x][y] = 'l';
		map[x][y + 1] = 208;
		y += 1;
		show();
	}
}

