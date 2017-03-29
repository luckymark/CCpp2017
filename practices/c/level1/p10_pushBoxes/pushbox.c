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


char A[8][8];
int x = 4, y = 4;
char step;

int main()
{
	int i = 0;
	char *p;
	p = A;
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
	A[x][y] = r;
	A[5][4] = b;
	A[4][3] = b;
	A[3][3] = b;
	A[3][5] = b;
	show();
	//操作判断
	
	do {
		step=_getch();
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
	while ((A[4][1]!= (char)254) || (A[1][3]!= (char)254) || (A[3][6] != (char)254) || (A[6][4] != (char)254));
	system("cls");
	printf("you have win!\n");
	system("pause");
}


void show()
{
	system("chcp 437");
	for (int i = 0;i < 8;i++) {
		for (int j = 0;j < 8;j++) {
			if (A[i][j] == 'w') {
				printf("%c", 219);
			}
			else if (A[i][j] == 'l' || A[i][j] == ' ') {
				printf("%c", 255);
			}
			else
				printf("%c", A[i][j]);
			if (j == 7) {
				printf("\n");
			}
		}
	}
}
	



void turnup()
{
	if ((A[x - 1][y] == (char)254)&&(A[x - 2][y] == 'l'))
	{
			system("cls");
			A[x][y] = 'l';
			A[x - 1][y] = 208;
			A[x - 2][y] = 254;
			x -= 1;
			show();
	}
	else if (A[x - 1][y] == 'l') {
		system("cls");
		A[x][y] = 'l';
		A[x - 1][y] = 208;
		x -= 1;
		show();
	}
}

void turndown()
{
	if ((A[x+1][y] == (char)254)&&(A[x + 2][y] == 'l'))
	{
			putchar(step);
			system("cls");
			A[x][y] = 'l';
			A[x + 1][y] = 208;
			A[x + 2][y] = 254;
			x += 1;
			show();
	}
	else if (A[x + 1][y] == 'l') {
		system("cls");
		A[x][y] = 'l';
		A[x + 1][y] = 208;
		x += 1;
		show();
	}
}

void turnleft()
{
	if ((A[x][y - 1] == (char)254) && (A[x][y - 2] == 'l'))
	{
		system("cls");
		A[x][y] = 'l';
		A[x][y - 1] = 208;
		A[x][y - 2] = 254;
		y -= 1;
		show();
	}
	else if (A[x][y - 1] == 'l') {
		system("cls");
		A[x][y] = 'l';
		A[x][y - 1] = 208;
		y -= 1;
		show();
	}
}

void turnright()
{
	if ((A[x][y + 1] == (char)254) && (A[x][y + 2] == 'l'))
	{
		system("cls");
		A[x][y] = 'l';
		A[x][y + 1] = 208;
		A[x][y + 2] = 254;
		y += 1;
		show();
	}
	else if (A[x][y + 1] == 'l') {
		system("cls");
		A[x][y] = 'l';
		A[x][y + 1] = 208;
		y += 1;
		show();
	}
}
