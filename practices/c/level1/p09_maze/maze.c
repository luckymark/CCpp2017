#define _CRT_SECURE_NO_WARNINGS//大神教的
#include<stdio.h>
#include<stdlib.h>

void turnup();
void turndown();
void turnleft();
void turnright();
void show();

char A[22][22];
char *p;
int i, j, x=20, y=0;
char step;
int point = 'R';

int main()
{
	p = A[0];
	FILE *fp;
	fp = fopen("mazemap.txt", "r");

	if (fp == NULL) {
		printf("can't open");
		exit(1);
	}

	for (;p < A[0] + 484;p++) {
		fscanf_s(fp, "%c", p);
		if ((p - A[0]) % 22 == 0) {
			i += 1;
			j = 0;
		}
		j++;
	}
	A[x][y] = 'R';;
	show();

	while (x > 0 || y < 20) {
		step = _getch();
		switch (step){
			case 'w': {
				turnup();
				break;
			}
			case 'a': {
				turnleft();
				break;
			}
			case 'd': {
				turnright();
				break;
			}
			case 's': {
				turndown();
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
			printf("%c", A[i][j]);
			if (j == 21)printf("\n");
		}
	}
}


void turnup()
{
	if (A[x - 1][y] != '*') {
		A[x][y] = ' ';
		A[x - 1][y] = point;
		system("cls");
		show();
		x = x - 1;
	}
}


void turnleft()
{
	if (A[x][y - 1] != '*') {
		A[x][y] = ' ';
		A[x][y - 1] = point;
		system("cls");
		show();
		y = y - 1;
	}
}


void turnright()
{
	if (A[x][y + 1] != '*') {
		A[x][y] = ' ';
		system("CLS");
		A[x][y + 1] = point;
		show();
		y = y + 1;
	}
}


void turndown()
{
	if (A[x + 1][y] != '*') {
		A[x][y] = ' ';
		A[x + 1][y] = point;
		system("cls");
		show();
		x += 1;
	}
}

