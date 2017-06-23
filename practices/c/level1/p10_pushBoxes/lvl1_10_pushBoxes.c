// Box.c
//

/* code:	Box for Kira
 * author:	Kyrios0
 * date:	2017.03.04
 * state:	finished
 * version:	1.1.0
 * when you run it first, please creat s01.txt s02.txt s03.txt.
 */

#include "stdafx.h"
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

void gotoxy(int x, int y);
int ctrl(int x, int y);
void writeScreen(LPCWSTR str, int x, int color);
void go(char cm1);
void push(char cm1);
unsigned int SDBMHash(char *str);
void loadMap(int lvl);
void loadBox(int lvl);
void makeMap();
void loadBox(int lvl);
void makeMap();
int loadScore(int lvl);
int saveScore(int lvl, int score);
int loadScore(int lvl);
int saveScore(int lvl, int step);

char m[50][50];
char cm1, cm2;
int nx = 3, ny = 2;
int x[6], y[6];

void gotoxy(int x, int y)
{
	HANDLE hOutput;
	COORD coo;
	coo.X = x;
	coo.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, coo);
}
//a simple hash function
unsigned int SDBMHash(char *str)
{
	unsigned int hash = 0;

	while (*str)
	{
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}

	return (hash & 0x7FFFFFFF);
}
//enhanced gotoxy, it could wiriting something on the screen with different colors
void writeScreen(LPCWSTR str, int x, int y, int color)
{
	COORD coord;
	DWORD buf[128];
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	coord.Y = y;
	coord.X = x;
	FillConsoleOutputAttribute(hConsoleOutput, color, 2, coord, buf);
	WriteConsoleOutputCharacter(hConsoleOutput, str, 1, coord, buf);
}

void go(char cm1)
{
	switch (cm1)
	{
	case 'w':
		ny--; break;
	case 'd':
		nx++; break;
	case 's':
		ny++; break;
	case 'a':
		nx--; break;
	}
}

void push(char cm1)
{	
	switch (cm1)
	{
	case 'w':
		ny--;
		writeScreen(L"█", 2 * nx - 2, ny - 2, FOREGROUND_GREEN);
		m[nx][ny - 1] = 2;
		break;
	case 'd':
		nx++; 
		writeScreen(L"█", 2 * nx, ny - 1, FOREGROUND_GREEN);
		m[nx + 1][ny] = 2;
		break;
	case 's':
		ny++; 
		writeScreen(L"█", 2 * nx - 2, ny, FOREGROUND_GREEN);
		m[nx][ny + 1] = 2;
		break;
	case 'a':
		nx--; 
		writeScreen(L"█", 2 * nx - 4, ny - 1, FOREGROUND_GREEN);
		m[nx - 1][ny] = 2;
		break;
	}
	m[nx][ny] = 1;	
}

int ctrl(int x, int y)
{
	while (1)
	{
		char cm2 = _getch();

		if ((cm2 == -32) && (cm2 != 'w') && (cm2 != 'a') && (cm2 != 's') && (cm2 != 'd'))
		{
			switch (cm2 = _getch())
			{
			case 72:	cm2 = 'w'; break;
			case 80:	cm2 = 's'; break;
			case 75:	cm2 = 'a'; break;
			case 77:	cm2 = 'd'; break;
			}
		}//arrow key to wasd

		if ((  ((m[x][y + 1] == 2) && (cm2 == 's'))
			|| ((m[x + 1][y] == 2) && (cm2 == 'd'))
			|| ((m[x][y - 1] == 2) && (cm2 == 'w'))
			|| (((x - 1 == 0) || (m[x - 1][y] == 2)) && (cm2 == 'a'))) == 0)//if no box
		{
			if (( ((m[x][y + 1] == 0) && (cm2 == 's'))
				|| ((m[x + 1][y] == 0) && (cm2 == 'd'))
				|| ((m[x][y - 1] == 0) && (cm2 == 'w'))
				|| (((x - 1 == 0) || (m[x - 1][y] == 0)) && (cm2 == 'a'))) == 0)//if it's vaild 
			{
				cm1 = cm2;//Accept
				return 0;
			}
		}
		else if (((((m[x][y + 2] == 0) && (cm2 == 's'))
				|| ((m[x + 2][y] == 0) && (cm2 == 'd'))
				|| ((m[x][y - 2] == 0) && (cm2 == 'w'))
				|| (((x - 1 == 0) || (m[x - 2][y] == 0)) && (cm2 == 'a'))) == 0)
			  && ((((m[x][y + 2] == 2) && (cm2 == 's'))
				|| ((m[x + 2][y] == 2) && (cm2 == 'd'))
				|| ((m[x][y - 2] == 2) && (cm2 == 'w'))
				|| (((x - 1 == 0) || (m[x - 2][y] == 2)) && (cm2 == 'a'))) == 0) )//if it's vaild
		{
			cm1 = cm2;//Accept
			return 1;
		}		
	}
}

void loadMap(int lvl)
{
	char buf[50][50];
	FILE *fptr;
	switch (lvl)
	{
	case 1:
		fptr = fopen("lvl01.txt", "r");
		break;
	case 2:
		fptr = fopen("lvl02.txt", "r");
		break;
	case 3:
		fptr = fopen("lvl03.txt", "r");
		break;
	default:
		break;

	}
	for (int i = 0; i < 11; i++)//input
	{
		for (int j = 0; j < 1; j++)
		{
			fgets(&buf[i][j], 256, fptr);
			if (buf[i][j] == -52)
			{
				break;
			}
			for (int k = 0; buf[i][k] != 0 && buf[i][k] != 10; k++)
			{
				m[i][k] = (int)(buf[i][k] - 48);
			}
		}
	}
}

void loadBox(int lvl)
{
	char buf[50][50];
	FILE *fptr;
	switch (lvl)
	{
	case 1:
		fptr = fopen("bag01.txt", "r");
		break;
	case 2:
		fptr = fopen("bag02.txt", "r");
		break;
	case 3:
		fptr = fopen("bag03.txt", "r");
		break;
	default:
		break;
	}
	for (int i = 0; i < 2; i++)//input
	{
		fgets(&buf[0][0], 128, fptr);
		for (int j = 0; j < 12; j += 4)
		{
			x[j / 4] = (int)(buf[0][j] - 48);
			y[j / 4] = (int)(buf[0][j + 1] - 48);
			x[j/4 + 3] = (int)(buf[0][j + 2] - 48);
			y[j/4 + 3] = (int)(buf[0][j + 3] - 48);
		}
	}
}

void makeMap()
{
	int z1, z2, x = 4, y = 4;

	for (z2 = 1; z2 <= y * 2 + 1; z2++)
	{
		for (z1 = 1; z1 <= x * 2 + 1; z1++)
			printf(m[z1][z2] ? "　" : "█");
		if (z2 <= y * 2)
		{
			putchar(10);
		}
	}
}

int loadScore(int lvl)
{
	int score = 0;
	char *charScore;
	charScore = (char*)malloc(8 * sizeof(char));
	char *state;
	char hash[8];
	FILE *fpsr;
	switch (lvl)
	{
	case 1:
		fpsr = fopen("s01.txt", "r");
		break;
	case 2:
		fpsr = fopen("s02.txt", "r");
		break;
	case 3:
		fpsr = fopen("s03.txt", "r");
		break;
	default:
		break;
	}
	state = fgets(hash, 128, fpsr);
	if (state == NULL)
	{
		return 999;
	}
	hash[7] = '\0';
	char *currentHash;
	currentHash = (char*)malloc(8 * sizeof(char));
	while (1)
	{
		itoa(score, charScore, 10);
		itoa(SDBMHash(charScore), currentHash, 16);
		if (!strcmp(hash, currentHash))
		{
			break;
		}
		score++;
	}

	return score;
	
}

int saveScore(int lvl, int step)
{
	FILE *fps;
	char *newScore;
	newScore = (char*)malloc(8 * sizeof(char));
	switch (lvl)
	{
	case 1:
		fps = fopen("s01.txt", "w+");
		break;
	case 2:
		fps = fopen("s02.txt", "w+");
		break;
	case 3:
		fps = fopen("s03.txt", "w+");
		break;
	default:
		break;
	}
	itoa(step, newScore, 10);
	fprintf(fps, "%x", SDBMHash(newScore));
	return 0;
}

int main()
{
	system("color 0f");
	int level = 1;
	
	while (1)
	{
		loadMap(level);
		loadBox(level);
		int best = loadScore(level);
		
		nx = 3; ny = 2;
		int step = 0, PoG;
		system("mode con cols=32 lines=11");

		makeMap();

		writeScreen(L"█", x[0], y[0], FOREGROUND_GREEN);
		writeScreen(L"█", x[1], y[1], FOREGROUND_GREEN);
		writeScreen(L"█", x[2], y[2], FOREGROUND_GREEN);
		writeScreen(L"▒", x[3]*2 - 2, y[3], FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeScreen(L"▒", x[4]*2 - 2, y[4], FOREGROUND_RED | FOREGROUND_INTENSITY);
		writeScreen(L"▒", x[5]*2 - 2, y[5], FOREGROUND_RED | FOREGROUND_INTENSITY);

		gotoxy(21, 3);
		puts("Step: 0");
		gotoxy(21, 4);
		printf("Best: %d", best);
		cm1 = 'd';

		while (1)
		{
			gotoxy(2 * nx - 2, ny - 1);
			printf("♂");
			gotoxy(2 * nx - 2, ny - 1);
			PoG = ctrl(nx, ny);
			gotoxy(2 * nx - 2, ny - 1);
			putchar(' '); putchar(' ');

			PoG ? push(cm1) : go(cm1);
			gotoxy(21, 3);
			printf("Step: %d", ++step);
			
			writeScreen((m[x[3]][y[3]+1] == 2) ? L"█" : L"▒", x[3] * 2 - 2, y[3], (m[x[3]][y[3] + 1] == 2) ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_INTENSITY);
			writeScreen((m[x[4]][y[4]+1] == 2) ? L"█" : L"▒", x[4] * 2 - 2, y[4], (m[x[4]][y[4] + 1] == 2) ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_INTENSITY);
			writeScreen((m[x[5]][y[5]+1] == 2) ? L"█" : L"▒", x[5] * 2 - 2, y[5], (m[x[5]][y[5] + 1] == 2) ? FOREGROUND_GREEN | FOREGROUND_INTENSITY : FOREGROUND_RED | FOREGROUND_INTENSITY);

			if (m[x[3]][y[3] + 1] == 2 && m[x[4]][y[4] + 1] == 2 && m[x[5]][y[5] + 1] == 2)
			{
				gotoxy(0, 9);
				puts("Congratulations!!!");
				if (step < best)
				{
					saveScore(level, step);
				}
				Sleep(1000);
				system("cls");
				
				if (level < 3)
				{
					level++;
					break;
				}

				system("mode con cols=54 lines=3");
				puts("  C language is the best language in the world!!");
				printf("  Press any key to quit");
				cm2 = _getch();
				exit(0);
			}
		}

	}

	return 0;
}
 