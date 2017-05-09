#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define SIZE 15             //地图大小 
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
int map[SIZE][SIZE]={0};      //记录地图的数组  0代表墙 
const char WALL[]="■"; 
const char AIR[]="  ";
const char PLAYER[]="○";
void printGame(int x,int y);
void creatMap(int map[SIZE][SIZE]);
void gameOver();

int main()
{
	int x=2,y=2;   //坐标 
	char dir;      //输入 
	creatMap(map);	
	printGame(x,y);
	while((dir = getch()) != 'q')
	{
		dir = getch();	
		switch (dir)
		{
			case UP:
				y = map[y-2][x-1]!=0? y-1:y;
				break;
			case DOWN:
				y = map[y][x-1]!=0? y+1:y;
				break;
			case LEFT:
				x = map[y-1][x-2]!=0? x-1:x;
				break;
			case RIGHT:
				x = map[y-1][x]!=0? x+1:x;
				break;
		}
		printGame(x,y);	
		if(x>=SIZE || x<=1 || y>=SIZE || y<=1)
		{
			break; 
		}
	}
	gameOver();
	Sleep(1500);
	return 0;
	
}

void printGame(int x,int y)   //打印游戏界面的函数 
{
	system("cls");
	for(int i=0;i<SIZE;i++)
	{
		for(int j=0;j<SIZE;j++)
		{
			if(map[i][j] != 1)
			{
				printf("%s",WALL);
			}
			else if(i !=y-1 || j != x-1) 
			{
				printf("%s",AIR);
			}
			else
			{
				printf("%s",PLAYER);
			}
		}
		printf("\n");
	}
}

void creatMap(int map[SIZE][SIZE])   //生成地图 
{
	for(int i=1;i<SIZE-1;i++)
	{
		map[1][i]=1;
	} 
	for(int i=1;i<SIZE;i++)
	{
		map[i][13]=1;
	} 
}

void gameOver()
{
	system("cls");
	printf("YOU WIN!");
}


