#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
const int LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80;
const int size = 15;  		  //地图大小 
int map[size][size]={0};      //记录地图的数组  0代表墙 
const char WALL[]="■"; 
const char AIR[]="  ";
const char PLAYER[]="○";
void printGame(int x,int y);
void creatMap(int map[size][size]);
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
		if(x>=size || x<=1 || y>=size || y<=1)
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
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size;j++)
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

void creatMap(int map[size][size])   //生成地图 
{
	for(int i=1;i<size-1;i++)
	{
		map[1][i]=1;
	} 
	for(int i=1;i<size;i++)
	{
		map[i][13]=1;
	} 
}

void gameOver()
{
	system("cls");
	printf("YOU WIN!");
}


