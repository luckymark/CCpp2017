#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void HideCursor(void);
void show_map(void);
void welcome(void);
void move(void);
void gotoxy(int x, int y);
count = 0;
static int map[25][25] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,2,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1 },
	{ 1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,1 },
	{ 1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1,0,1,0,1 },
	{ 1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1 },
	{ 1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1 },
	{ 1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,0,0,1 },
	{ 1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0,1 },
	{ 1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1 },
	{ 1,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1 },
	{ 1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1 },
	{ 1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1 },
	{ 1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1 },
	{ 1,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,1,0,0,0,1 },
	{ 1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1 },
	{ 1,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1 },
	{ 1,1,1,1,1,1,1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1 },
	{ 1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1 }
};
int main(void)
{
	system("mode con cols=68 lines=27");
	system("chcp 437");
	system("cls");


	welcome();

	return 0;
}
void welcome(void)
{
	char ch;//用来表示用户选择的选项
	printf("\n\n\n\n\n\n");
	printf("**********************************************************\n");
	printf("**                                                      **\n");
	printf("**                                                      **\n");
	printf("**             Welcome to play the game!                **\n");
	printf("**                                                      **\n");
	printf("**                                                      **\n");
	printf("**********************************************************\n");
	printf("please press the button for the desired selecion.\n");
	printf("       1.play                        2.quit\n");
	ch = getch();
	if (ch == '1')move();
	else return;
}
void show_map(void)
{
	system("cls");
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			if (map[i][j] == 1)printf("%c", 219);
			else if (map[i][j] == 2)printf("%c",232);
			else printf("  ");
		}
		printf("     \n");
	}
	gotoxy(35, 22);
	printf("moved %d times.", count);
	HideCursor();
}
void move(void)
{
	show_map();
	int x = 1, y = 1;
	while (1) {
		char ch = _getch();
		if (ch = -32) {
			switch (ch = getch()) {
			case 72:ch = 'w'; break;
			case 80:ch = 's'; break;
			case 75:ch = 'a'; break;
			case 77:ch = 'd'; break;
			}
		}
		if (map[x][y - 1] == 0 && ch == 'a') {
			map[x][y] = 0;
			y = y - 1;
			map[x][y] = 2;
			count++;
		}
		else if (map[x - 1][y] == 0 && ch == 'w') {
			map[x][y] = 0;
			x = x - 1;
			map[x][y] = 2;
			count++;
		}
		else if (map[x][y + 1] == 0 && ch == 'd') {
			map[x][y] = 0;
			y = y + 1;
			map[x][y] = 2;
			count++;
		}
		else if (map[x + 1][y] == 0 && ch == 's') {
			map[x][y] = 0;
			x = x + 1;
			map[x][y] = 2;
			count++;
		}
		show_map();
		if (x == 24 && y == 23) {
			system("cls");
			gotoxy(35, 15);
			printf("Congratulations!\n"
				"now you are a \n"
				"little smarter pig than before.\n");
			break;
		}
	}

}
void gotoxy(int x, int y)//移动光标到坐标（x,y) 
{
	HANDLE hwnd;    //创建一个名为hwnd的句柄类型 
	COORD coord;    //struct类型定义 
	coord.X = x;      //对结构体中变量赋值，相对横坐标 
	coord.Y = y;      //相对控制台纵坐标 
	hwnd = GetStdHandle(STD_OUTPUT_HANDLE); //获取当前控制台窗口句柄 
	SetConsoleCursorPosition(hwnd, coord);//光标移动到该窗口的相对位置（x,y) 
}
void HideCursor(void)//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
