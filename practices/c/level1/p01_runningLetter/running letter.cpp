#include<stdio.h>
#include<windows.h>
int main()
{
	int n,i,j,k,speed;
	char ch='R';
	scanf("%d %d",&n,&speed);
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)putchar(' ');
		putchar(ch);
		Sleep(speed); 
		system("cls");
	}
	for(;i>=0;i--)
	{
		system("cls");
		for(j=0;j<i;j++)putchar(' ');
		putchar(ch);
		Sleep(speed);
		
	}
	return 0;
}
