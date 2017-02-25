#include <iostream>
#include<stdio.h>
#include<windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
		while(1)
	{
	
		for(int i=0;i<80;i++)
		{
			for(int j=0;j<i;j++)
			{
				printf(" ");
			}
			printf("R");
			system("cls");
			Sleep(25);
		}
		
		for(int i=80;i>0;i--)
		{
			for(int j=0;j<i;j++)
			{
				printf(" ");
			}
			printf("R");
			system("cls");
			Sleep(25);
		}
	}
	return 0;
}
