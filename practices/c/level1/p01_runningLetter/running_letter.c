#include <stdio.h>
#include <windows.h>

#define NUM_COL 79

void print(int n);

void main(void)
{
	int i;

	for(;;){
		for (i = 0; i < NUM_COL; i++)
			print(i);
		for (; i >= 0; i--)
			print(i);
	}
}

void print(int n)
{
	system("cls");
	for (; n; n--)
		printf(" ");
	printf("R");
	Sleep(100);
}
