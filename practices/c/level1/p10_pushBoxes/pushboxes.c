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
int move(struct player* p,int x,int y,int m[100][100]);
void keydown(struct player* p);
void drmap(int x,int y,int maze[100][100]); 
int main()
{
	FILE *fp;
	fp=fopen("mission.txt","r");
	char m[100]={5};
	int x,y;
	int z，maze[100][100],mission=1;
	system("title Maze");
	system("mode con cols=64 lines=30");
	
	struct player* box;
	struct player* boxlink;
	box=(struct player*)malloc(sizeof(struct player));
	boxlink=box;

	struct player* play;
	play=(struct player*)malloc(sizeof(struct player));
	play->x=0;
	play->y=1; 
	play->next=(struct player*)malloc(sizeof(struct player));
	play->next->x=play->x;
	play->next->y=play->y;

	while(mission<=3)
	{
		switch(mission)
		{
			case 1:x=21;y=20;break;
			case 2:x=31;y=30;break;
			case 3:x=41;y=40;break;
		}
		for(int i=0;i<y;i++)
		{
			fegts(&m,x,fp);
			for(int j=0;j<x;j++)
			{
				if(m[j]==' ')maze[i][j]=1;
				else if(m[j]=='#')maze[i][j]=0;
				else if(m[j]=='*')
				{
					box->x=j;
					box->y=i;
					box=box->next;
					box=(struct player*)malloc(sizeof(struct player));
					maze[i][j]=2;
				}
			}
		}
		free(box);
		box=boxlink;
		drmap(x,y);
		z=move(play,x,y,maze);
		if(z==1)system("cls");
	}
	return 0;
}


void gotoxy(int x, int y)
{
COORD pos = {x,y};
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOut, pos);
}
void drmap(int x,int y)
{
	for(int i=0;i<x;i++)
	for(int j=0;j<y;j++)
	{
		if(maze[i][j]==1)printf("  ");
		else if(maze[i][j]==0)printf("■");
		else if(maze[i][j]==2)printf("▣")；
		if(j==y-1)putchar('\n'); 
	}
}
int move(struct player* p,int x,int y,int m[x][y])
{
	struct player* temp;
	gotoxy(p->x,p->y);
	printf("●") ;
	while(1)
	{
		do
		{ 
			keydown(p);
			if((p->next->x)/2==10&&p->next->y==8)return 1;
		} 
		while(m[p->next->y][(p->next->x)/2]==0||(p->next->x/2)<0||p->next->y<0);
		temp=p->next;
		gotoxy(p->x,p->y);
		printf("  ");
		gotoxy(temp->x,temp->y);
		printf("●");
		free(p);
		p=temp;
		p->next=(struct player*)malloc(sizeof(struct player)); 
		p->next->x=p->x;
		p->next->y=p->y;
	} 
}
void keydown(struct player* p)
{
	char ch=getch();
	switch(ch)
	{
		case'A':
		case'a':p->next->x=p->x-2;break;
		case'D':
		case'd':p->next->x=p->x+2;break;
		case'W':
		case'w':p->next->y=p->y-1;break;
		case'S':
		case's':p->next->y=p->y+1;break; 
	}
	
	
} 
