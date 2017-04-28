#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h> 
#include<conio.h>
int score=1000;
int highscore[3];
struct player
{
	int x;
	int y;
	struct player* next; 
};	
void gotoxy(int x,int y);
int move(struct player* p,struct player* box,struct player* target,int x,int y,int mission,int m[100][100]);
int keydown(struct player* p);
int boxmove(struct player* box,struct player* tempbox,int z,int maze[100][100],int i);
void drmap(int x,int y,int maze[100][100]); 
void add(struct player* p,int mission,int i,int j);
int main()
{
	FILE *fp,*record;
	fp=fopen("mission.txt","r");
	char m[100];
	int x,y,step,boxes;
	int maze[100][100];
	char mission=1,targets;
	system("title pushbox");
	system("mode con cols=96 lines=32");
	system("color F0");
	struct player* box;
	box=(struct player*)malloc(sizeof(struct player));
	struct player* boxlink=box;

	struct player* play;
	play=(struct player*)malloc(sizeof(struct player));
	play->next=(struct player*)malloc(sizeof(struct player));

	struct player* target;
	target=(struct player*)malloc(sizeof(struct player));
	struct player* targetlink=target;

	 if((record=fopen("record.txt","r"))==NULL)for(int i=0;i<3;i++)highscore[i]=0;
	 else fscanf(record,"%d %d %d",&highscore[0],&highscore[1],&highscore[2]);
	 fclose(record);
	system("cls");
	for(;mission<=3;mission++)
	{
		boxes=0;
		targets=0;
		switch(mission)
		{
			case 1:x=20;y=9;break;
			case 2:x=9;y=9;break;
			case 3:x=8;y=8;break;
		}
		for(int i=0;i<y;i++)
		{
			fgets(m,x+2,fp);
			for(int j=0;j<x;j++)
			{
				if(m[j]==' ')maze[i][j]=1;
				else if(m[j]=='#')maze[i][j]=0;
				else if(m[j]=='*')
				{
					boxes++;
					boxlink->x=j;
					boxlink->y=i;
					maze[i][j]=2;
					
					if(boxes!=3)
					{
						boxlink->next=(struct player*)malloc(sizeof(struct player));
						boxlink=boxlink->next;
					}
					else if(mission!=1&&boxes!=3)boxlink=boxlink->next; 
					else if(boxes==3)boxlink->next=NULL;
					
					//add(boxlink,mission,boxes,1);
				}
				else if(m[j]=='x')
				{
					targets++;
					targetlink->x=j;
					targetlink->y=i;
					maze[i][j]=3;
					
					if(targets!=3&&mission==1)
					{
						targetlink->next=(struct player*)malloc(sizeof(struct player));
						targetlink=targetlink->next;
					}
					else if(targets!=3&&mission!=1)targetlink=targetlink->next;
					else if(targets==3)targetlink->next=NULL;
					
					//add(targetlink,mission,targets,2);
				}
				else if(m[j]=='s')
				{
					play->x=j;
					play->y=i;
					maze[i][j]=1;
				}
			}
		}
	
		boxlink=box;
		targetlink=target;
		fscanf(record,"%d ",highscore[mission-1]);
		drmap(x,y,maze);
		printf("record:%d",highscore[mission-1]);
		step=move(play,box,target,x,y,mission-1,maze);
		system("cls");
		if(mission!=3)
		{
			gotoxy(30,15);
			puts("The Next mission will be started after 2 seconds");
		}
		if(1000-step>highscore[mission-1])
		{		
			gotoxy(30,16);
			puts("You break the record in this mission");
			highscore[mission-1]=1000-step;			
		}
		gotoxy(30,17);
		printf("In this mission you score is %d,record is %d\n",1000-step,highscore[mission-1]);
		Sleep(2000);
		system("cls");
		box=boxlink;
		target=targetlink;
		play=(struct player*)malloc(sizeof(struct player));
		play->next=(struct player*)malloc(sizeof(struct player));
	}
	fclose(fp);
	record=fopen("record.txt","w+");
	fprintf(record,"%d %d %d",highscore[0],highscore[1],highscore[2]);
	fclose(record); 
	return 0;
}


void gotoxy(int x, int y)
{

COORD pos = {x,y};
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleCursorPosition(hOut, pos);
}

void drmap(int x,int y,int maze[100][100])
{
	for(int i=0;i<y;i++)
	for(int j=0;j<x;j++)
	{ 
		if(maze[i][j]==1)printf(" ");
		else if(maze[i][j]==0)printf("#");
		else if(maze[i][j]==2)printf("O");
		else if(maze[i][j]==3)printf("x");
		if(j==x-1)putchar('\n'); 
	}
	putchar('\n');
}
int move(struct player* p,struct player* box,struct player* target,int x,int y,int mission,int m[100][100])
{
	struct player* tempbox=box;
	struct player* temp;
	struct player* targetlink=target;
	int mo,step=0,t=0;
	int mv,i;
	gotoxy(p->x,p->y);
	printf("@") ;
	while(1)
	{
		mv=1; 
		t=0;
		do	
		{
			p->next->x=p->x;
			p->next->y=p->y;
			mo=keydown(p);
		}
		while(m[p->next->y][p->next->x]==0||p->next->x<0||p->next->y<0);
		if(mo==5)
		{
			system("cls");
			drmap(x,y,m);
			printf("record:%d",highscore[mission]);
			gotoxy(p->x,p->y);
			printf("@") ;
			continue;
		}
		temp=p->next;
		i=0;
		while(box!=NULL)
		{
			i++;
			if(temp->x==box->x&&temp->y==box->y)mv=boxmove(box,tempbox,mo,m,i);
			box=box->next;
		}
		box=tempbox;
		if(mv==0)continue;
		step++;
		gotoxy(p->x,p->y);
		printf(" ");
		gotoxy(temp->x,temp->y);
		printf("@");
		free(p);
		while(box!=NULL)
		{
			while(target!=NULL)
			{
				if(box->x==target->x&&box->y==target->y)t++;
				target=target->next;
			}
			target=targetlink;
			box=box->next; 
		}
		if(t==3)
		{
			free(temp);
			break;
			
		}
		box=tempbox;
		target=targetlink;
		while(target!=NULL)
		{
			if(temp->x!=target->x&&temp->y!=target->y)
			{
				gotoxy(target->x,target->y);
				printf("x");
			}
			while(box!=NULL)
			{
				if(box->x!=target->x&&box->y!=target->y)
				{
					gotoxy(target->x,target->y);
					printf("x");
				}
				box=box->next;
			}
			box=tempbox;
			while(box!=NULL)
			{
				if(box->x==target->x&&box->y==target->y)
				{
					gotoxy(box->x,box->y);
					printf("O");
				}
				box=box->next;
			}
			if(temp->x==target->x&&temp->y==target->y)
			{
				gotoxy(temp->x,temp->y);
				printf("@");
			}
			target=target->next;
			box=tempbox;
		}
		target=targetlink;
		box=tempbox;
		p=temp;
		p->next=(struct player*)malloc(sizeof(struct player)); 
		p->next->x=p->x;
		p->next->y=p->y;
	} 
	return step;
}
int keydown(struct player* p)
{
	int z;
	char ch=getch();
	switch(ch)
	{
		case 'A':
		case 'a':p->next->x=p->x-1;z=1;break;
		case 'D':
		case 'd':p->next->x=p->x+1;z=2;break;
		case 'W':
		case 'w':p->next->y=p->y-1;z=3;break;
		case 'S':
		case 's':p->next->y=p->y+1;z=4;break; 
		case 'R':
		case 'r':z=5;
	}
	return z;
	
} 
int boxmove(struct player* box,struct player* tempbox,int z,int maze[100][100],int i)
{
	int x,y;
	x=box->x;
	y=box->y;
	struct player* box2=tempbox;
	switch(z)
	{
		case 1:x-=1;break; 
		case 2:x+=1;break; 
		case 3:y--;break; 
		case 4:y++;break; 
		
	}
	for(int j=0;j<3;j++)
	{
		if(j!=i&&x==tempbox->x&&y==tempbox->y)return 0;
		if(j<2)tempbox=tempbox->next;
	}
	tempbox=box2;
	if(maze[y][x]!=0)
	{
		box->x=x;
		box->y=y;
		gotoxy(box->x,box->y);
		printf("O");
		return 1;
	}
	else return 0;
}
void add(struct player* p,int mission,int i,int j)
{
	if(j==1&&i!=3)
	{
		p->next=(struct player*)malloc(sizeof(struct player));
		p=p->next;
	}
	else if(j==2&&i!=3&&mission==1)
	{
		p->next=(struct player*)malloc(sizeof(struct player));
		p=p->next;
	}

	if(mission!=1&&i!=3)p=p->next; 
	else if(i==3)p->next=NULL;
}
