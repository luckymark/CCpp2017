#include<stdio.h>
#include<windows.h>
#define BOUNDRY 80

void move(int m);

void main()
{
	for ( int i = 0;i < BOUNDRY;i++) {
		move(i);
	}
	for (int i = BOUNDRY;i >= 0;i--) {
		move(i);
	}
}

void move(int m)
{
	Sleep(50);
	system("cls");
	for (int j = 0;j < m - 1;j++) {
		printf(" ");
	}
	printf("R");
}
