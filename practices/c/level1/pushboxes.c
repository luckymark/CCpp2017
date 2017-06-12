#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print(int a,int b);
void move(char ch);
int i,a,b,count;
char ch;
char map[11][21]={0};
int main(int argc, char *argv[])
{
	int level;
	printf("choose level 1 or 2:");
	scanf("%d",&level);
	switch (level)
	{
		case 1:freopen("map_easy.txt","r",stdin);
		break;
		case 2:freopen("map_difficult.txt","r",stdin);
		break;
		default:printf("error");
		return 0;
	}
	for(i=0;i<10;i++)
	{
		gets(map[i]);
	}
	fclose(stdin);
	a=1,b=1,count=0;
	map[a][b]='0';
	for(i=0;i<10;i++)
	{
		printf("%s\n",map[i]);
	}
	while(map[4][6]!='+')
	{
		ch=getch();
		move(ch);
		print(a,b);
	}
	switch (level)
	{
		case 1:freopen("out_easy.txt","w",stdout);
		break;
		case 2:freopen("out_difficult","w",stdin);
		break;
	}
	
	printf("Success! Your steps are %d",count);
	return 0;
}

void print(int a,int b)
{
	system("cls");
	map[a][b]='0';
	for(i=0;i<10;i++)
	{
		printf("%s\n",map[i]);
	}
}
void move(char ch)
{
	map[a][b]=' ';
	if(ch=='w')
	{
		if(map[a-1][b]==' ')
		{
			a--;
		}
		else if(map[a-1][b]=='#'&&map[a-2][b]==' ')
		{
			map[a-2][b]='#';
			a--;
		}
		else if(map[a-1][b]=='#'&&map[a-2][b]=='0')
		{
			map[a-2][b]='+';
			a--;
		}
	}
	else if(ch=='s')
	{
		if(map[a+1][b]==' ')
		{
			a++;
		}
		else if(map[a+1][b]=='#'&&map[a+2][b]==' ')
		{
			map[a+2][b]='#';
			a++;
		}
		else if(map[a+1][b]=='#'&&map[a+2][b]=='0')
		{
			map[a+2][b]='+';
			a++;
		}
	}
	else if(ch=='a')
	{
		if(map[a][b-1]==' ')
		{
			b--;
		}
		else if(map[a][b-1]=='#'&&map[a][b-2]==' ')
		{
			map[a][b-2]='#';
			b--;
		}
		else if(map[a][b-1]=='#'&&map[a][b-2]=='0')
		{
			map[a][b-2]='+';
			b--;
		}
	} 
	else if(ch=='d')
	{
		if(map[a][b+1]==' ')
		{
			b++;
		}
		else if(map[a][b+1]=='#'&&map[a][b+2]==' ')
		{
			map[a][b+2]='#';
			b++;
		}
		else if(map[a][b+1]=='#'&&map[a][b+2]=='0')
		{
			map[a][b+2]='+';
			b++;
		}
	}
	count++;
}
