/* code:	Running Letter
 * author:	Kyrios0
 * date: 	2017.02.26
 * state: 	finished
 * version: 1.0.0
 */

#include<stdio.h>
#include<windows.h>
 
void gotoxy(int x, int y)
{
	HANDLE hOutput;
	COORD coo;
	coo.X = x;
	coo.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, coo);
}

int main(int argc, char** argv)
{
	system("chcp 437");
	system("color 0f");
	system("mode con cols=63 lines=32");
	
	int x = 0, y = 0, round = 0;
	
	while(1)
	{
		system("cls");
		
		gotoxy(x, y);
		putchar('#');
		gotoxy(x, y);
		
		(round % 2 == 0) ? x++ : x--;
		if((x == 0) || (x == 63))
		{
			round++;
		}
		
		Sleep(25);
	}
	return 0;
}