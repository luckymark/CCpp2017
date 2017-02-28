#include<stdio.h>
#include<windows.h>
#define TIMES 50
int main(void)
{
	int i,j;
	
	for(i=1;i<TIMES;i++)
	{
		for(j=1;j<i;j++)	
		{
			printf(" ");
		}	
		printf("R");
		Sleep(200);
		system("cls");
	}
	for(i=TIMES;i>0;i--)
	{
		for(j=1;j<i;j++)	
		{
			printf(" ");
		}	
		printf("R");
		Sleep(200);
		system("cls");
	}
 	return 0;
 } 
