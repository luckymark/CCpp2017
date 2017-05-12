#include<stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include<stdbool.h>
struct maze
{
	int x;
	int y;
	int dir;
};
char m[30][30];
struct maze man;
const int xdir[5] = { 0, 1, 0, -1 ,0};//w a s d
const int ydir[5] = { -1,0,1,0 ,0};//w a s d
void map(void);
void show(void);
void ini(void);
void turn(void);
bool check(void);
void move(void);
void show0(void);
int main(void)
{
	ini();
	show();
	while (true)
	{
		Sleep(60);
		system("cls");
		turn();
		if (check())
			move();
		man.dir = 4;
		show();
	}
	getchar();
	return 0;
}

void map(void)
{
	for (int i = 0; i < 30; ++i)
		m[0][i] = '*';
	for (int a = 4; a < 30; ++a)
		m[a][0] = '*';
	for (int b = 1; b < 25; ++b)
		m[29][b] = '*';
	for (int c = 1; c < 30; ++c)
		m[c][29] = '*';
	for (int a = 5; a < 10; ++a)
		m[a][4] = '*';
	for (int b = 1; b < 5; ++b)
		m[4][b] = '*';
	for (int i = 1; i < 20; ++i)
		m[i][14] = '*';
	for (int i = 9; i < 20; ++i)
		m[19][i] = '*';
	for (int i = 24; i < 30; ++i)
		m[4][i] = '*';
	for (int i = 14; i < 29; ++i)
		m[i][24] = '*';
}

void show(void)
{
	for (int a = 0; a < 30; ++a) 
	{
		for (int b = 0; b < 30; ++b)
			printf("%c", m[a][b]);
		printf("\n");
	}
}

void ini(void)
{
	map();
	man.x = 0;
	man.y = 1;
	m[man.y][man.x] = 'H';
}

void turn(void) {  
	if (_kbhit()) {
		char dir = _getch();  //读取输入的键 
		switch (dir) {  //改变方向 
		case 119: man.dir = 0; break;
		case 100: man.dir =1; break;
		case 115: man.dir = 2; break;
		case 97: man.dir =3; break;
		}
	}
}

bool check(void)
{
	if (m[man.y + ydir[man.dir]][man.x + xdir[man.dir]] == '*')
		return false;
	else
		return true;

}

void move(void)
{
	m[man.y][man.x] = ' ';
	man.x = man.x + xdir[man.dir];
	man.y = man.y + ydir[man.dir];
	m[man.y][man.x] = 'H';
}

void show0(void)
{
	for (int a = 0; a < man.y; ++a)
		for (int b = 0; b < man.x; ++b)
			if (m[man.y][man.x] == 'H')
				printf("%c", m[man.y][man.x]);
	
}