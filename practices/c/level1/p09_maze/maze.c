#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
struct player
{
	int x;
	int y;
	struct player* next; 
};	

void gotoxy(int x,int y);
void move(struct player* p,int x,int y,int m[x][y]);
int keydown(int x,int y,struct player* p);
void drmap(int x,int y,int m[x][y]); 
int main()
{
	system("title Maze");
	system("mode con cols=64 lines=30");
	struct player* play;
	play=(struct player*)malloc(sizeof(struct player));
	play->x=0;
	play->y=0; 
	int x=10,y=10;
	int maze[10][10]=
	{
		{1,1,1,1,0,0,0,0,0,0},
		{1,0,0,1,1,0,0,0,0,0},
		{1,0,0,0,1,1,1,1,0,0},
		{1,1,0,0,1,0,0,1,0,0},
		{0,1,1,0,1,0,0,1,1,0},
		{0,0,1,0,1,1,0,0,1,0},
		{0,0,1,1,0,1,1,0,1,0},
		{0,0,0,1,0,0,1,0,0,0},
		{0,0,0,1,1,1,1,1,1,0},
		{0,0,0,0,0,0,0,0,1,1},
	} ;
	drmap(x,y,maze);
	
	return 0;
}


void gotoxy(int x, int y)
{
COORD pos = {x,y};
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOut, pos);
}


void drmap(int x,int y,int m[x][y])
{
	for(int i=0;i<x;i++)
	for(int j=0;j<y;j++)
	{
		int y1=2*(y-1); 
		if(m[x][y]==1)
		{
			gotoxy(y1,x);
			printf("  ");
		} 
		else if(m[x][y]==0)
		{
			gotoxy(y1,x);
			printf("¡ö");
		}
	}
}
