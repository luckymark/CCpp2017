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
struct maze box;
const int xdir[5] = { 0, 1, 0, -1 ,0 };//w a s d
const int ydir[5] = { -1,0,1,0 ,0 };//w a s d

void map(FILE *fp);
void show(void);
void ini(FILE *fp);
void turn(void);//·½ÏòÒÆ¶¯
bool check(struct maze *);
void move(void);
bool checkbox(void);//¼ì²éÈËÊÇ·ñ×²»÷Ïä×
void movebox(void);//ÒÆ¶¯Ïä×Ó
bool win(void);//Ê¤Àû
char get(FILE * fp);//¶ÁÈ¡ÎÄ¼þ
void play(FILE * fp);//ÓÎÏ·

int main(void)
{
	FILE *fp;
	fopen_s(&fp, "C:\\Users\\q9160\\Desktop\\map1.txt", "r");
	play(fp);
	fopen_s(&fp, "C:\\Users\\q9160\\Desktop\\map2.txt", "r");
	play(fp);
	getchar();
	return 0;
}

void map(FILE * fp)
{

	for (int i = 0; i < 30; ++i)
		for (int j = 0; j < 30; ++j)
		{
			m[i][j] = get(fp);

		}
}

void show(void)
{
	for (int a = 0; a < 30; ++a)
	{
		for (int b = 0; b < 30; ++b)
		{
			printf("%c", m[a][b]);
		}
		printf("\n");
	}
}

void ini(FILE * fp)
{
	map(fp);
	man.x = 0;
	man.y = 1;
	m[man.y][man.x] = 'H';
	box.x = 10;
	box.y = 10;
	m[box.y][box.x] = '0';
	m[29][28] = 'X';
}

void turn(void) {
	if (_kbhit()) {
		char dir = _getch();  //¶ÁÈ¡ÊäÈëµÄ¼ü 
		switch (dir) {  //¸Ä±ä·½Ïò 
		case 119: man.dir = 0; break;
		case 100: man.dir = 1; break;
		case 115: man.dir = 2; break;
		case 97: man.dir = 3; break;
		}
	}
}

bool check(struct maze * p)
{
	if (m[p->y + ydir[p->dir]][p->x + xdir[p->dir]] == '*')
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

bool checkbox(void)
{
	if (man.x + xdir[man.dir] == box.x&&man.y + ydir[man.dir] == box.y) {
		box.dir = man.dir;
		return true;
	}
	else
		return false;
}

void movebox(void)
{
	box.x = box.x + xdir[box.dir];
	box.y = box.y + ydir[box.dir];
	m[box.y][box.x] = '0';
}

bool win(void)
{
	if (box.y == 29 && box.x == 28)
		return true;
	return false;
}

char get(FILE *fp)
{
	char ch;
	fread(&ch, 1, 1, fp);
	if (ch == '\n')
	{
		fread(&ch, 1, 1, fp);
	}
	return ch;
}

void play(FILE * fp)
{
	ini(fp);
	while (true)
	{
		if (_kbhit())
		{
			Sleep(20);
			system("cls");
			turn();
			if (check(&man))
				if (checkbox())
				{
					if (check(&box))
					{
						move();
						movebox();
					}
				}
				else
					move();
			if (win())
			{
				break;
			}
			show();
			man.dir = 4;
		}
	}
}
