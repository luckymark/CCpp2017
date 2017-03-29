#include<stdio.h>
#include<windows.h>
void gotoxy(int x, int y);

int main()
{
	boundry();

}

void boundry()
{
	gotoxy(20, 20);
	printf("1");
	gotoxy(20, 22);
	printf("2");
	gotoxy(20, 24);
	printf("3");
	gotoxy(20, 26);
	printf("4");
}
void gotoxy(int x, int y)//ָ光标控制函数
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}