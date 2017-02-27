#include<stdio.h>
#include<windows.h>
#define TIMES 100
int main(void)
{
	int i,j;
	
	system("mode con  cols=100 lines=28");
	for(i=1;i<TIMES;i++)
	{
		for(j=1;j<i;j++)	
		{
			printf(" ");
		}	
		printf("R");
		Sleep(20);
		system("cls");
	}
	for(i=TIMES;i>0;i--)
	{
		for(j=1;j<i;j++)	
		{
			printf(" ");
		}	
		printf("R");
		Sleep(20);
		system("cls");
	}
 	return 0;
 } 
