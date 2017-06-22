#include<stdio.h>
#include<windows.h>
#define TIMES 100
int main(void)
{
	int j; 
	system("mode con  cols=100 lines=28");
	for(int i=1;i<TIMES;i++)
	{
		for(j=1;j<i;j++)	
		{
			printf(" ");
		}	
		printf("R");
		Sleep(20);
		system("cls");
	}
	for(int i=TIMES;i>0;i--)
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
