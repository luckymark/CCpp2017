// Maze2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<windows.h>
#include<conio.h>

void MapPrint(void);
void Position(void);
void Turn(void);
bool Check(void);
const int xdir[5] = { 0,0,-1,1,0 };
const int ydir[5] = { -1,1,0,0,0 };
void Move(void);
struct Point
{
	int x;
	int y;
	int dir;
};
struct Point Exit;
struct Point Person;

char map[9][9] =
{
	{ '0','R','0','0','0','0','0','0','0', },
	{ '0',' ','0',' ','0',' ',' ',' ','0', },
	{ '0',' ','0',' ',' ',' ','0','0','0', },
	{ '0',' ','0',' ','0','0','0',' ','E', },
	{ '0',' ',' ',' ','0',' ',' ',' ','0', },
	{ '0',' ','0','0',' ',' ','0',' ','0', },
	{ '0',' ','0',' ',' ','0','0',' ','0', },
	{ '0',' ',' ',' ','0',' ',' ',' ','0', },
	{ '0','0','0','0','0','0','0','0','0', },
};

int main()
{
	Position();
	while (true)
	{
		MapPrint();
		Turn();
		if (Check())
		Move();
		Person.dir = 4;
		system("cls");
	}
    return 0;
}

void MapPrint()
{
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void Position() 
{
	Exit.x = 3;
	Exit.y = 8;
	Person.x = 0;
	Person.y = 1;
}

void Turn() 
{
	if(_kbhit())
	{
		char dir = _getch();
			switch (dir)
			{
			case 'a': Person.dir = 0; break;
			case 'd': Person.dir = 1; break;
			case 'w': Person.dir = 2; break;
			case 's': Person.dir = 3; break;
			default:
				break;
			}
	}
}

bool Check()
{
	if (map[Person.x + xdir[Person.dir]][Person.y + ydir[Person.dir]] == '0')
			return false;
	else if(map[Person.x + xdir[Person.dir]][Person.y + ydir[Person.dir]] == 'E')
	{
		printf("You win!\n");
		exit(0);
	}
	else
			return true;
}

void Move()
{
	map[Person.x][Person.y] = ' ';
	Person.x = Person.x + xdir[Person.dir];
	Person.y = Person.y + ydir[Person.dir];
	map[Person.x][Person.y] = 'R';
}