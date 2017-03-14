#include<stdio.h>
#include<windows.h>
#define boundry 80

int i = 0;
void move();
void main()
{
	for (i = 0;i < boundry;i++) {
		move();
	}
	for (i = boundry;i >= 0;i--) {
		move();
	}
}

void move()
{
	Sleep(50);
	system("cls");
	for (int j = 0;j < i - 1;j++) {
		printf(" ");
	}
	printf("R");
}