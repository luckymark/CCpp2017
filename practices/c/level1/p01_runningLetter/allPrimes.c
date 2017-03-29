#include<stdio.h>
#include<windows.h>
#define boundry 80

void move(int m);

void main()
{
	for ( int i = 0;i < boundry;i++) {
		move(i);
	}
	for (int i = boundry;i >= 0;i--) {
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