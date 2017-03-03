// Puzzle.cpp : 定义控制台应用程序的入口点。
//

/* code:	Puzzle Game for Kira
 * author:	Kyrios0
 * date:	2017.03.03
 * state:	finished
 * version:	1.0.5
 */

#include "stdafx.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<string.h> 

char *getWall(int x, int y);
int sr(int x, int y);
void Make_Maze(int x, int y);
void gotoxy(int x, int y);
void ctrl(int x, int y);
void modeSelection();
DWORD WINAPI clocks(LPVOID lpParameter);

char cw[][4] = { "　","┃","━","┗","┃","┃","┏","┣","━","┛","━","┻","┓","┫","┳" ,"╋" };//map
char m[50][50], cm1, cm2, level;
//Automatically generate walls
char *getWall(int x, int y)
{
	int a = (m[x][y - 1] ? 0 : 1) | (m[x + 1][y] ? 0 : 2) | (m[x][y + 1] ? 0 : 4) | (m[x - 1][y] ? 0 : 8);
	return cw[(m[x][y - 1] ? 0 : 1) | (m[x + 1][y] ? 0 : 2) | (m[x][y + 1] ? 0 : 4) | (m[x - 1][y] ? 0 : 8)];//CORE!
}
//Determine the path
int sr(int x, int y)//CORE algorithm!
{
	static int d[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };
	int zx = x * 2, zy = y * 2, nx, tn = rand() % 2 ? 1 : 3, i;
	m[zx][zy] = 1;

	for (i = 0, nx = rand() % 4; i < 4; i++, nx = (nx + tn) % 4)
	{
		if (m[zx + 2 * d[nx][0]][zy + 2 * d[nx][1]] == 0)
		{
			m[zx + d[nx][0]][zy + d[nx][1]] = 1, sr(x + d[nx][0], y + d[nx][1]);
		}
	}

	return 0;
}

void Make_Maze(int x, int y)
{
	int z1, z2;
	
	for (z1 = 0, z2 = 2 * y + 2; z1 <= 2 * x + 2; z1++)
	{
		m[z1][0] = 1, m[z1][z2] = 1;
	}
	
	for (z1 = 0, z2 = 2 * x + 2; z1 <= 2 * y + 2; z1++)
	{
		m[0][z1] = 1, m[z2][z1] = 1;
	}

	m[1][2] = 1; m[2 * x + 1][2 * y] = 1;
	srand((unsigned)time(NULL));
	sr(rand() % x + 1, rand() % y + 1);
}

void gotoxy(int x, int y)
{
	HANDLE hOutput;
	COORD coo;
	coo.X = x;
	coo.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, coo);
}

void ctrl(int x, int y)
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
		}
		if ((( ((m[x][y + 1] == 0) && (cm2 == 's'))
			|| ((m[x + 1][y] == 0) && (cm2 == 'd'))
			|| ((m[x][y - 1] == 0) && (cm2 == 'w'))
			|| (((x - 1 == 0) || (m[x - 1][y] == 0)) && (cm2 == 'a')) ) == 0))//if it's vaild 
		{
			cm1 = cm2;//Accept
			break;
		}
	}
}

void modeSelection()
{
	system("mode con cols=63 lines=32");
	gotoxy(26, 13);
	printf("CHOOSE MODE");
	gotoxy(28, 14);
	printf("E-easy");
	gotoxy(28, 15);
	printf("N-normal");
	gotoxy(28, 16);
	printf("H-hard");
	gotoxy(28, 17);
	printf("L-lunatic");
	level = _getch();
	system("cls");
}

DWORD WINAPI clocks(LPVOID lpParameter)
{
	int x = *(int*)lpParameter;
	int i = 0;
	while (1)
	{
		Sleep(250);
		Sleep(250);
		gotoxy(4 * x + 5, 3);
		printf("Time: %ds", i++);
		Sleep(250); 
		Sleep(250);
	}
}

int main(void)
{
	system("color 0f");
	while (1)
	{
		modeSelection();
		int x, y;
		switch (level)
		{
			case 'e':
				x = 5, y = 5;
				system("mode con cols=50 lines=13");
				break;
			case 'n':
				x = 10, y = 10;
				system("mode con cols=62 lines=23");
				break;
			case 'h':
				x = 15, y = 15;
				system("mode con cols=82 lines=33");
				break;
			case 'l':
				x = 29, y = 22;
				system("mode con cols=138 lines=47");
				break;
			default:
				gotoxy(15, 13);
				puts("Because recently someone is lazy");
				gotoxy(12, 15);
				puts("so there is no hidden difficulty(～￣▽￣)～");
				gotoxy(23, 17);
				system("pause");
				exit(0);
				break;
		}
		
		int z1, z2, nx = 1, ny = 2;

		Make_Maze(x, y);
		for (z2 = 1; z2 <= y * 2 + 1; z2++)
		{
			for (z1 = 1; z1 <= x * 2 + 1; z1++)
				printf(m[z1][z2] ? "　" : getWall(z1, z2));
			if (z2 <= y * 2)
			{
				putchar(10);
			}
		}

		switch (level)
		{
			case 'e':
				gotoxy(25, 1);
				puts("Mode: Easy");
				gotoxy(27, 5);
				puts("Just");
				gotoxy(28, 6);
				puts("For");
				gotoxy(27, 7);
				puts("Kids");
				break;
			case 'n':
				gotoxy(45, 1);
				puts("Mode: Normal");
				gotoxy(45, 6);
				puts("Relax~~");
				break;
			case 'h':
				gotoxy(65, 1);
				puts("Mode: Hard");
				gotoxy(65, 6);
				puts("Enjoy it!");
				break;
			case 'l':
				gotoxy(121, 1);
				puts("Mode: Lunatic");
				gotoxy(121, 6);
				puts("Be patient");
				break;
			default:;
		}
		gotoxy(4 * x - 1, 2 * y - 1);
		puts("End");
		HANDLE hThread_1 = CreateThread(NULL, 0, clocks, &x, 0, NULL);
		cm1 = 'd';		

		while (1)
		{		
			
			gotoxy(2 * nx - 2, ny - 1);
			putchar('█');
			gotoxy(2 * nx - 2, ny - 1);
			ctrl(nx, ny);
			gotoxy(2 * nx - 2, ny - 1);
			putchar(' '); putchar(' ');
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
			if ((2 * nx - 1 == 4 * x - 1) && (ny - 1 == 2 * y - 1))
			{
				gotoxy(0, 2 * y + 1);
				puts("Congratulations!!!    Press Q to quit");
				printf("                      Press other key to restart");
				TerminateThread(hThread_1, 1);
				CloseHandle(hThread_1);			
				cm2 = _getch();				
				(cm2 == 'q') ? exit(0) : cm2++;
				break;
			}
		}

	}

	return 0;
}// Puzzle Game
/*  This algorithm is a randomized version of Prim's algorithm.
	1.Start with a grid full of walls.
	2.Pick a cell, mark it as part of the maze. Add the walls of the cell to the wall list.
	3.While there are walls in the list:
		3.1.Pick a random wall from the list. If the cell on the opposite side isn't in the maze yet:
			3.1.1.Make the wall a passage and mark the cell on the opposite side as part of the maze.
			3.1.2.Add the neighboring walls of the cell to the wall list.
		3.2.Remove the wall from the list.

	It will usually be relatively easy to find the way to the starting cell, but hard to find the way 
	anywhere else.

	Note that simply running classical Prim's on a graph with random edge weights would create mazes 
	stylistically identical to Kruskal's, because they are both minimal spanning tree algorithms. 
	Instead, this algorithm introduces stylistic variation because the edges closer to the starting 
	point have a lower effective weight.
 */

