#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void print(int a,int b);
void move(char ch);
int i,a,b;
char ch;
char map[11][21]={0};
int main(int argc, char *argv[])
{

	
	freopen("map.txt","r",stdin);
	for(i=0;i<10;i++)
	{
		gets(map[i]);
	}
	a=1;
	b=1;
	map[a][b]='0';
	for(i=0;i<10;i++)
	{
		printf("%s\n",map[i]);
	}
	freopen("con","r",stdin);
	while(a!=9||b!=1)
	{
		ch=getchar();
		move(ch);
		print(a,b);
	}
	printf("Success");
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
	if(ch=='w'&&map[a-1][b]==' ')
	{
		a--;
	}
	else if(ch=='s'&&map[a+1][b]==' ')
	{
		a++;
	}
	else if(ch=='a'&&map[a][b-1]==' ')
	{
		b--;
	}
	else if(ch=='d'&&map[a][b+1]==' ')
	{
		b++;
	}
}
