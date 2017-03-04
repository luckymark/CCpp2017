#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
#include<time.h>
void gotoxy(int x,int y);
int creatmaze(int x,int y,int m[x][y]);
void drmap(int x,int y,int m[x][y]); 

char issue[6]={' ','|','+','-','O','#'};
struct player
{
	int x;
	int y;
};
int main()
{
	
	int x,y;
	puts("How big do you want?");
	printf("x(bigger than 1):");
	scanf("%d",&x);
	while(x<2)
	{
		printf("Please enter a bigger number");
		scanf("%d",&x);
	}
	printf("y(bigger than 1):");
	scanf("%d",&y);
	while(y<2)
	{
		printf("Please enter a bigger number");
		scanf("%d",&y);
	}
	printf("Your maze is %dx%d",x,y);
	Sleep(1000);
	system("cls");
	int maze[x][y];
	srand(clock());
	for(int j=0;j<y;j++)maze[i][j]=1;
	creatmaze(x,y,maze);
	return 0;
}
void gotoxy(int x, int y)
{
COORD pos = {x,y};
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOut, pos);
}
int creatmaze(int x,int y,int m[x][y])
{
	int x1=0,y1=0,x2=0,y2=0,i,j,s;
	m[0][0]=0;
	while(1)
	{
		x2=x1;
		y2=y1;
		switch(s=rand()%4+1)
		{
			case 1:if(x1>2){x1--;x2=x1-1;};break;
			case 2:x1++;x2=x1+1;break;
			case 3:if(y1>2){y1--;y2=y1-1;}break;
			case 4:y1++;y2=y1+1;break;
			
		}
		if(m[x2][y2]!=0)m[x1][y1]=0;
		if(x2==x||y2==y)
		{
			m[x2][y2]=0;
			break;
		}
	}
	drmap(x,y,m);
}
void drmap(int x,int y,int m[x][y])
{
	for(int i=0;i<x;i++)
	for(int j=0;j<y;j++)
	{
		if(m[i][j]==0)putchar(issue[0]);
		else if(i>1&&j>1&&m[i-1][j]==1&&m[i][j]==1&&m[i+1][j]==1&&m[i][j+1]==1&&m[i][j-1]==1)putchar(issue[2]);
		else if(j>1&&m[i][j]==1&&m[i][j-1]==1&&m[i][j+1]==1)putchar(issue[1]);
		else if(i>1&&m[i][j]==1&&m[i+1][j]==1&&m[i-1][j]==1)putchar(issue[3]);
		if(j==y-1)putchar('\n');
	}
}
