// pushbox.cpp : 定义控制台应用程序的入口点。


#include "stdafx.h"
#include <windows.h>
int a[6][6];
int i = 0, j = 0;
int level;
int levelNum = 0;
int scan(int n,const char b[6])
{
	FILE* fp = fopen(b, "r");
	if (fp == NULL)
	{
		printf("Files not found");
		return -1;
	}
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			fscanf(fp, "%d", &a[i][j]);
		}
		fscanf(fp, "\n");
	}
	fclose(fp);
	return 0;
}
void choice()
{
	printf("Select the level:1-2\n");
	scanf("%d", &levelNum);
	if (levelNum == 1)
	{
		scan(6, "1.txt");
	}
	else if (levelNum == 2)
	{
		scan(6, "2.txt");
	}
	else
	{
		printf("Your Input is Wrong!");
	}
}
void print()
{
	system("cls");
	for (i = 0; i<6; i++)
	{
		for (j = 0; j<6; j++)
		{
			if (a[i][j] == 0)
			{
				printf("*");
			}
			else if (a[i][j] == 1)
			{
				printf(" ");
			}
			else if (a[i][j] == 3)
			{
				printf("M");
			}
			else if (a[i][j] == 4)
			{
				printf("B");
			}
			else if (a[i][j] == 5)
			{
				printf("D");
			}
			if (j == 5)
			{
				printf("\n");
			}
		}
	}
}
int score = 1000;
int m = 1, n = 2;
int p = 1, q = 4;

int main(int argc, char** argv) {
	choice();
	print();
	while (1)
	{
		if (GetKeyState(VK_UP)<0 && (a[m - 1][n] == 1 || a[m - 1][n] == 4))
		{
			if (a[m - 1][n] == 1)
			{
				a[m - 1][n] = 3;
				a[m][n] = 1;
				--m;
			}
			else if (a[m - 1][n] == 4)
			{
				if (a[m - 2][n] == 1)
				{
					a[m - 2][n] = 4;
					a[m - 1][n] = 3;
					a[m][n] = 1;
					--m;
				}
				else if (a[m - 2][n] == 5)
				{
					a[m - 2][n] = 4;
					a[m - 1][n] = 3;
					a[m][n] = 1;
					--m;
				}
			}
			if (a[2][4] == 1)
			{
				a[2][4] = 5;
			}
			print();
		}

		if (GetKeyState(VK_DOWN)<0 && (a[m + 1][n] == 1 || a[m + 1][n] == 4))
		{
			if (a[m + 1][n] == 1)
			{
				a[m + 1][n] = 3;
				a[m][n] = 1;
				++m;
			}
			else if (a[m + 1][n] == 4)
			{
				if (a[m + 2][n] == 1)
				{
					a[m + 2][n] = 4;
					a[m + 1][n] = 3;
					a[m][n] = 1;
					++m;
				}
				else if (a[m + 2][n] == 5)
				{
					a[m + 2][n] = 4;
					a[m + 1][n] = 3;
					a[m][n] = 1;
					++m;
				}
			}
			if (a[2][4] == 1)
			{
				a[2][4] = 5;
			}
			print();
		}

		if (GetKeyState(VK_LEFT)<0 && (a[m][n - 1] == 1 || a[m][n - 1] == 4))
		{
			if (a[m][n - 1] == 1)
			{
				a[m][n - 1] = 3;
				a[m][n] = 1;
				--n;
			}
			else if (a[m][n - 1] == 4)
			{
				if (a[m][n - 2] == 1)
				{
					a[m][n - 2] = 4;
					a[m][n - 1] = 3;
					a[m][n] = 1;
					--n;
				}
				else if (a[m][n - 2] == 5)
				{
					a[m][n-2] = 4;
					a[m][n-1] = 3;
					a[m][n] = 1;
					--n;
				}
			}
			if (a[2][4] == 1)
			{
				a[2][4] = 5;
			}
			print();
		}

		if (GetKeyState(VK_RIGHT)<0 && (a[m][n + 1] == 1 || a[m][n + 1] == 4))
		{
			if (a[m][n + 1] == 1)
			{
				a[m][n + 1] = 3;
				a[m][n] = 1;
				++n;
			}
			else if (a[m][n + 1] == 4)
			{
				if (a[m][n + 2] == 1)
				{
					a[m][n + 2] = 4;
					a[m][n + 1] = 3;
					a[m][n] = 1;
					++n;
				}
				else if (a[m][n + 2] == 5)
				{
					a[m][n+2] = 4;
					a[m][n+1] = 3;
					a[m][n] = 1;
					++n;
				}
			}
			if (a[2][4] == 1)
			{
				a[2][4] = 5;
			}
			print();
		}
		Sleep(100);
		if (a[1][4] != 5 && a[2][4] != 5 && a[2][4] != 3)
		{
			system("cls");
			printf("You Win!\nYour score is %d\n",score);
			return 0;
		}
		score--;
	}
	return 0;
}
