#include<stdio.h>
#include<windows.h>


void gotoxy(int x, int y)
{
	HANDLE hand;
	COORD where;
	where.X = x;
	where.Y = y;
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hand, where);
}



int main(void)
{
	system("mode con cols=100 lines=1");
	int i = 0;
	int k = 0;
	while(1)
	{
		gotoxy(i, 0);
		printf("R");
		Sleep(50);
		gotoxy(i, 0);
		printf(" ");
		(k % 2 == 0) ? i++ : i--;
		if (i == 0 || i == 99)k++;

		
	}
	
	return 0;
}




