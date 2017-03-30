#include<stdio.h>
#include<conio.h>
#include<windows.h>
void show_map(void);
void move(void);
void gotoxy(int x, int y);
void HideCursor(void);
int count = 0;
int map[8][6] = {
	{0,1,1,1,1,0},
	{1,1,0,0,1,0},
	{1,4,3,0,1,0},
	{1,1,3,0,1,1},
	{1,1,0,3,0,1},
	{1,2,3,0,0,1},
	{1,2,2,5,2,1},
	{1,1,1,1,1,1},
};
int main(void)
{
	system("mode con cols=16 lines=11");
	system("chcp 437");
	move();
}
void show_map(void)
{
	int i, j;
	system("cls");
	printf("\n ");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 6; j++) {
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1)printf("%c", 219);
			else if (map[i][j] == 2)printf("%c", 236);
			else if (map[i][j] == 3)printf("%c", 240);
			else if (map[i][j] == 4)printf("%c", 232);
			else if (map[i][j] == 5)printf("%c", 178);
			else if (map[i][j] == 6)printf("%c", 232);
		}
		printf("\n ");
	}
	gotoxy(1, 9);
	printf("%d times moved.", count);
	HideCursor();
}
void move(void)
{
	show_map();
	int x = 2, y = 1;
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
		if (ch == 'a') {
			if (map[x][y] == 4) {  //如果角色所在地没有标志物
				if (map[x][y - 1] == 3) {    //如果角色左边是一个空箱子
					if (y > 1 && map[x][y - 2] == 0) {   //如果箱子左边是空地
						map[x][y - 2] = 3;
						map[x][y - 1] = 4;
						map[x][y] = 0;
						--y;
						count++;
					}
					else if (y > 1 && map[x][y - 2] == 2) {   //如果箱子左边是一个标志地
						map[x][y - 2] = 5;       //箱子移动至目标地
						map[x][y - 1] = 4;
						map[x][y] = 0;
						--y;
						count++;
					}
				}
				else if (map[x][y - 1] == 5) {     //角色左边是一个满箱子
					if (y > 1 && map[x][y - 2] == 0) {    //如果满箱子左边是空地
						map[x][y - 2] = 3;
						map[x][y - 1] = 6;    //角色移动到目标地
						map[x][y] = 0;
						--y;
						count++;
					}
					else if (y > 1 && map[x][y - 2] == 2) {    //满箱子左边是目标地
						map[x][y - 2] = 5;
						map[x][y - 1] = 6;
						map[x][y] = 0;
						--y;
						count++;
					}
				}
				else if (map[x][y - 1] == 0) {   //如果角色左边是空地
					map[x][y - 1] = 4;
					map[x][y] = 0;
					--y;
					count++;
				}
				else if (map[x][y - 1] == 2) {
					map[x][y - 1] = 6;
					map[x][y] = 0;
					--y;
					count++;
				}
			}
			else if (map[x][y] == 6) {     //如果角色位于标记地
				if (map[x][y - 1] == 5) {   //如果左侧箱子位于标记地
					if (y > 1 && map[x][y - 2] == 0) {      //如果箱子左侧是空地
						map[x][y - 2] = 3;
						map[x][y - 1] = 6;
						map[x][y] = 2;
						--y;
						count++;
					}
					else if (y > 1 && map[x][y - 2] == 2) {    //如果箱子左侧是标记地
						map[x][y - 2] = 5;
						map[x][y - 1] = 6;
						map[x][y] = 2;
						--y;
						count++;
					}
				}
				else if (map[x][y - 1] == 3) {   //如果左侧是个空箱子
					if (y > 1 && map[x][y - 2] == 0) {  //如果箱子左侧是个空地
						map[x][y - 2] = 3;
						map[x][y - 1] = 4;
						map[x][y] = 2;
						--y;
						count++;
					}
					else if (y > 1 && map[x][y - 2] == 2) {  //如果箱子左侧是一个标志地
						map[x][y - 2] = 5;
						map[x][y - 1] = 4;
						map[x][y] = 2;
						--y;
						count++;
					}
				}
				else if (map[x][y - 1] == 0) {
					map[x][y - 1] = 4;
					map[x][y] = 2;
					--y;
					count++;
				}
				else if (map[x][y - 1] == 2) {
					map[x][y - 1] = 6;
					map[x][y] = 2;
					--y;
					count++;
				}
			}
		}
		if (ch == 'w') {
			if (map[x][y] == 4) {  //如果角色所在地没有标志物
				if (map[x - 1][y] == 3) {    //如果角色上面是一个空箱子
					if (x > 1 && map[x - 2][y] == 0) {   //如果箱子上面是空地
						map[x - 2][y] = 3;
						map[x - 1][y] = 4;
						map[x][y] = 0;
						--x;
						count++;
					}
					else if (x > 1 && map[x - 2][y] == 2) {   //如果箱子上面是一个标志地
						map[x - 2][y] = 5;       //箱子移动至目标地
						map[x - 1][y] = 4;
						map[x][y] = 0;
						--x;
						count++;
					}
				}
				else if (map[x - 1][y] == 5) {     //角色上面是一个满箱子
					if (x > 1 && map[x - 2][y] == 0) {    //如果满箱子上面是空地
						map[x - 2][y] = 3;
						map[x - 1][y] = 6;    //角色移动到目标地
						map[x][y] = 0;
						--x;
						count++;
					}
					else if (x > 1 && map[x - 2][y] == 2) {    //满箱子上面是目标地
						map[x - 2][y] = 5;
						map[x - 1][y] = 6;
						map[x][y] = 0;
						--x;
						count++;
					}
				}
				else if (map[x - 1][y] == 0) {   //如果角色上面是空地
					map[x - 1][y] = 4;
					map[x][y] = 0;
					--x;
					count++;
				}
				else if (map[x - 1][y] == 2) {
					map[x - 1][y] = 6;
					map[x][y] = 0;
					--x;
					count++;
				}
			}
			else if (map[x][y] == 6) {     //如果角色位于标记地
				if (map[x - 1][y] == 5) {   //如果左侧箱子位于标记地
					if (x > 1 && map[x - 2][y] == 0) {      //如果箱子左侧是空地
						map[x - 2][y] = 3;
						map[x - 1][y] = 6;
						map[x][y] = 2;
						--x;
						count++;
					}
					if (x > 1 && map[x - 2][y] == 2) {    //如果箱子左侧是标记地
						map[x - 2][y] = 5;
						map[x - 1][y] = 6;
						map[x][y] = 2;
						--x;
						count++;
					}
				}
				else if (map[x - 1][y] == 3) {   //如果左侧是个空箱子
					if (x > 1 && map[x - 2][y] == 0) {  //如果箱子左侧是个空地
						map[x - 2][y] = 3;
						map[x - 1][y] = 4;
						map[x][y] = 2;
						--x;
						count++;
					}
					else if (x > 1 && map[x - 2][y] == 2) {  //如果箱子左侧是一个标志地
						map[x - 2][y] = 5;
						map[x - 1][y] = 4;
						map[x][y] = 2;
						--x;
						count++;
					}
				}
				else if (map[x - 1][y] == 0) {
					map[x - 1][y] = 4;
					map[x][y] = 2;
					--x;
					count++;
				}
				else if (map[x - 1][y] == 2) {
					map[x - 1][y] = 6;
					map[x][y] = 2;
					--x;
					count++;
				}
			}
		}
		if (ch == 'd') {
			if (map[x][y] == 4) {  //如果角色所在地没有标志物
				if (map[x][y + 1] == 3) {    //如果角色右边是一个空箱子
					if (y < 6 && map[x][y + 2] == 0) {   //如果箱子右边是空地
						map[x][y + 2] = 3;
						map[x][y + 1] = 4;
						map[x][y] = 0;
						++y;
						count++;
					}
					else if (y < 6 && map[x][y + 2] == 2) {   //如果箱子右边是一个标志地
						map[x][y + 2] = 5;       //箱子移动至目标地
						map[x][y + 1] = 4;
						map[x][y] = 0;
						++y;
						count++;
					}
				}
				else if (map[x][y + 1] == 5) {     //角色右边是一个满箱子
					if (y < 6 && map[x][y + 2] == 0) {    //如果满箱子右边是空地
						map[x][y + 2] = 3;
						map[x][y + 1] = 6;    //角色移动到目标地
						map[x][y] = 0;
						++y;
						count++;
					}
					else if (y < 6 && map[x][y + 2] == 2) {    //满箱子右边是目标地
						map[x][y + 2] = 5;
						map[x][y + 1] = 6;
						map[x][y] = 0;
						++y;
						count++;
					}
				}
				else if (map[x][y + 1] == 0) {   //如果角色右边是空地
					map[x][y + 1] = 4;
					map[x][y] = 0;
					++y;
					count++;
				}
				else if (map[x][y + 1] == 2) {
					map[x][y + 1] = 6;
					map[x][y] = 0;
					++y;
					count++;
				}
			}
			else if (map[x][y] == 6) {     //如果角色位于标记地
				if (map[x][y + 1] == 5) {   //如果左侧箱子位于标记地
					if (y < 6 && map[x][y + 2] == 0) {      //如果箱子左侧是空地
						map[x][y + 2] = 3;
						map[x][y + 1] = 6;
						map[x][y] = 2;
						++y;
						count++;
					}
					else if (y < 6 && map[x][y + 2] == 2) {    //如果箱子左侧是标记地
						map[x][y + 2] = 5;
						map[x][y + 1] = 6;
						map[x][y] = 2;
						++y;
						count++;
					}
				}
				else if (map[x][y + 1] == 3) {   //如果左侧是个空箱子
					if (y < 6 && map[x][y + 2] == 0) {  //如果箱子左侧是个空地
						map[x][y + 2] = 3;
						map[x][y + 1] = 4;
						map[x][y] = 2;
						++y;
						count++;
					}
					else if (y < 6 && map[x][y + 2] == 2) {  //如果箱子左侧是一个标志地
						map[x][y + 2] = 5;
						map[x][y + 1] = 4;
						map[x][y] = 2;
						++y;
						count++;
					}
				}
				else if (map[x][y + 1] == 0) {
					map[x][y + 1] = 4;
					map[x][y] = 2;
					++y;
					count++;
				}
				else if (map[x][y + 1] == 2) {
					map[x][y + 1] = 6;
					map[x][y] = 2;
					++y;
					count++;
				}
			}
		}
		if (ch == 's') {
			if (map[x][y] == 4) {  //如果角色所在地没有标志物
				if (map[x + 1][y] == 3) {    //如果角色下面是一个空箱子
					if (x < 5 && map[x + 2][y] == 0) {   //如果箱子下面是空地
						map[x + 2][y] = 3;
						map[x + 1][y] = 4;
						map[x][y] = 0;
						++x;
						count++;
					}
					else if (x < 5 && map[x + 2][y] == 2) {   //如果箱子下面是一个标志地
						map[x + 2][y] = 5;       //箱子移动至目标地
						map[x + 1][y] = 4;
						map[x][y] = 0;
						++x;
						count++;
					}
				}
				else if (map[x + 1][y] == 5) {     //角色下面是一个满箱子
					if (x < 5 && map[x + 2][y] == 0) {    //如果满箱子下面是空地
						map[x + 2][y] = 3;
						map[x + 1][y] = 6;    //角色移动到目标地
						map[x][y] = 0;
						++x;
						count++;
					}
					else if (x < 5 && map[x + 2][y] == 2) {    //满箱子下面是目标地
						map[x + 2][y] = 5;
						map[x + 1][y] = 6;
						map[x][y] = 0;
						++x;
						count++;
					}
				}
				else if (map[x + 1][y] == 0) {   //如果角色下面是空地
					map[x + 1][y] = 4;
					map[x][y] = 0;
					++x;
					count++;
				}
				else if (map[x + 1][y] == 2) {
					map[x + 1][y] = 6;
					map[x][y] = 0;
					++x;
					count++;
				}
			}
			else if (map[x][y] == 6) {     //如果角色位于标记地
				if (map[x + 1][y] == 5) {   //如果左侧箱子位于标记地
					if (x < 5 && map[x + 2][y] == 0) {      //如果箱子左侧是空地
						map[x + 2][y] = 3;
						map[x + 1][y] = 6;
						map[x][y] = 2;
						++x;
						count++;
					}
					else if (x < 5 && map[x + 2][y] == 2) {    //如果箱子左侧是标记地
						map[x + 2][y] = 5;
						map[x + 1][y] = 6;
						map[x][y] = 2;
						++x;
						count++;
					}
				}
				else if (map[x + 1][y] == 3) {   //如果左侧是个空箱子
					if (x < 5 && map[x + 2][y] == 0) {  //如果箱子左侧是个空地
						map[x + 2][y] = 3;
						map[x + 1][y] = 4;
						map[x][y] = 2;
						++x;
						count++;
					}
					else if (x < 5 && map[x + 2][y] == 2) {  //如果箱子左侧是一个标志地
						map[x + 2][y] = 5;
						map[x + 1][y] = 4;
						map[x][y] = 2;
						++x;
						count++;
					}
				}
				else if (map[x + 1][y] == 0) {
					map[x + 1][y] = 4;
					map[x][y] = 2;
					++x;
					count++;
				}
				else if (map[x + 1][y] == 2) {
					map[x + 1][y] = 6;
					map[x][y] = 2;
					++x;
					count++;
				}
			}
		}
		show_map();
		if (map[2][2] == 5 && map[3][2] == 5 && map[3][3] == 5) {
			system("cls");
			gotoxy(35, 15);
			printf("Congratulations!\n");
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
