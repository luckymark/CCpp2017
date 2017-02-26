#include <iostream>
#include<stdio.h>
#include<windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int i=0,op=1;
	while (1)
	{
		i+=op;
		for(int j=0;j<i;j++)
		{
			printf(" ");
		}
		printf("R");
		system("cls");
		Sleep(25);
		if (i==80)
			op=-1;
		if (i==1)
			op=1;
	}
	return 0;
}
