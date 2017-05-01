/*version 1.1
update at 2017-05-01
*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
void show_map(void);
void move(void);
void gotoxy(int x, int y);
void HideCursor(void);
void readin(void);
int **map;
int Het = 0;
int Wid = 0;
int t = 1;
FILE *fp;
int main(void)
{
	system("mode con cols=27 lines=15");
	move();
}
void show_map(void)
{
	int i, j;
	system("cls");
	printf("   Level %d\n",t);
	for (i = 0; i < Het; i++) {
		for (j = 0; j < Wid; j++) {
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1)printf("█");//墙
			else if (map[i][j] == 2)printf("●");//标记地
			else if (map[i][j] == 3)printf("≡");//空地上的箱子
			else if (map[i][j] == 4)printf("♀");//人
			else if (map[i][j] == 5)printf("▓");//标记点的箱子
			else if (map[i][j] == 6)printf("♀");//人
		}
		printf("\n");
	}
}
void move(void)
{
	int score = 0;
	gotoxy(16, 5);
	printf("score:%d", score);
	for (; t < 2; t++) {
		fp = fopen("map.txt", "r");
		readin();
		show_map();
		int x, y;
		for (int k = 0; k < Het; k++) {
			for (int m = 0; m < Wid; m++) {
				if (map[k][m] == 4) {
					x = k;
					y = m;
				}
			}
		}
		int flag = 0;
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
							score++;
							--y;
						}
						else if (y > 1 && map[x][y - 2] == 2) {   //如果箱子左边是一个标志地
							map[x][y - 2] = 5;       //箱子移动至目标地
							map[x][y - 1] = 4;
							map[x][y] = 0;
							score++;
							--y;
						}
					}
					else if (map[x][y - 1] == 5) {     //角色左边是一个满箱子
						if (y > 1 && map[x][y - 2] == 0) {    //如果满箱子左边是空地
							map[x][y - 2] = 3;
							map[x][y - 1] = 6;    //角色移动到目标地
							map[x][y] = 0;
							score++;
							--y;
						}
						else if (y > 1 && map[x][y - 2] == 2) {    //满箱子左边是目标地
							map[x][y - 2] = 5;
							map[x][y - 1] = 6;
							map[x][y] = 0;
							score++;
							--y;
						}
					}
					else if (map[x][y - 1] == 0) {   //如果角色左边是空地
						map[x][y - 1] = 4;
						map[x][y] = 0;
						score++;
						--y;
					}
					else if (map[x][y - 1] == 2) {
						map[x][y - 1] = 6;
						map[x][y] = 0;
						score++;
						--y;
					}
				}
				else if (map[x][y] == 6) {     //如果角色位于标记地
					if (map[x][y - 1] == 5) {   //如果左侧箱子位于标记地
						if (y > 1 && map[x][y - 2] == 0) {      //如果箱子左侧是空地
							map[x][y - 2] = 3;
							map[x][y - 1] = 6;
							map[x][y] = 2;
							score++;
							--y;
						}
						else if (y > 1 && map[x][y - 2] == 2) {    //如果箱子左侧是标记地
							map[x][y - 2] = 5;
							map[x][y - 1] = 6;
							map[x][y] = 2;
							score++;
							--y;
						}
					}
					else if (map[x][y - 1] == 3) {   //如果左侧是个空箱子
						if (y > 1 && map[x][y - 2] == 0) {  //如果箱子左侧是个空地
							map[x][y - 2] = 3;
							map[x][y - 1] = 4;
							map[x][y] = 2;
							score++;
							--y;
						}
						else if (y > 1 && map[x][y - 2] == 2) {  //如果箱子左侧是一个标志地
							map[x][y - 2] = 5;
							map[x][y - 1] = 4;
							map[x][y] = 2;
							score++;
							--y;
						}
					}
					else if (map[x][y - 1] == 0) {
						map[x][y - 1] = 4;
						map[x][y] = 2;
						score++;
						--y;
					}
					else if (map[x][y - 1] == 2) {
						map[x][y - 1] = 6;
						map[x][y] = 2;
						score++;
						--y;
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
							score++;
							--x;
						}
						else if (x > 1 && map[x - 2][y] == 2) {   //如果箱子上面是一个标志地
							map[x - 2][y] = 5;       //箱子移动至目标地
							map[x - 1][y] = 4;
							map[x][y] = 0;
							score++;
							--x;
						}
					}
					else if (map[x - 1][y] == 5) {     //角色上面是一个满箱子
						if (x > 1 && map[x - 2][y] == 0) {    //如果满箱子上面是空地
							map[x - 2][y] = 3;
							map[x - 1][y] = 6;    //角色移动到目标地
							map[x][y] = 0;
							score++;
							--x;
						}
						else if (x > 1 && map[x - 2][y] == 2) {    //满箱子上面是目标地
							map[x - 2][y] = 5;
							map[x - 1][y] = 6;
							map[x][y] = 0;
							score++;
							--x;
						}
					}
					else if (map[x - 1][y] == 0) {   //如果角色上面是空地
						map[x - 1][y] = 4;
						map[x][y] = 0;
						score++;
						--x;
					}
					else if (map[x - 1][y] == 2) {
						map[x - 1][y] = 6;
						map[x][y] = 0;
						score++;
						--x;
					}
				}
				else if (map[x][y] == 6) {     //如果角色位于标记地
					if (map[x - 1][y] == 5) {   //如果左侧箱子位于标记地
						if (x > 1 && map[x - 2][y] == 0) {      //如果箱子左侧是空地
							map[x - 2][y] = 3;
							map[x - 1][y] = 6;
							map[x][y] = 2;
							score++;
							--x;
						}
						if (x > 1 && map[x - 2][y] == 2) {    //如果箱子左侧是标记地
							map[x - 2][y] = 5;
							map[x - 1][y] = 6;
							map[x][y] = 2;
							score++;
							--x;
						}
					}
					else if (map[x - 1][y] == 3) {   //如果左侧是个空箱子
						if (x > 1 && map[x - 2][y] == 0) {  //如果箱子左侧是个空地
							map[x - 2][y] = 3;
							map[x - 1][y] = 4;
							map[x][y] = 2;
							score++;
							--x;
						}
						else if (x > 1 && map[x - 2][y] == 2) {  //如果箱子左侧是一个标志地
							map[x - 2][y] = 5;
							map[x - 1][y] = 4;
							map[x][y] = 2;
							score++;
							--x;
						}
					}
					else if (map[x - 1][y] == 0) {
						map[x - 1][y] = 4;
						map[x][y] = 2;
						score++;
						--x;
					}
					else if (map[x - 1][y] == 2) {
						map[x - 1][y] = 6;
						map[x][y] = 2;
						score++;
						--x;
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
							score++;
							++y;
						}
						else if (y < 6 && map[x][y + 2] == 2) {   //如果箱子右边是一个标志地
							map[x][y + 2] = 5;       //箱子移动至目标地
							map[x][y + 1] = 4;
							map[x][y] = 0;
							score++;
							++y;
						}
					}
					else if (map[x][y + 1] == 5) {     //角色右边是一个满箱子
						if (y < 6 && map[x][y + 2] == 0) {    //如果满箱子右边是空地
							map[x][y + 2] = 3;
							map[x][y + 1] = 6;    //角色移动到目标地
							map[x][y] = 0;
							score++;
							++y;
						}
						else if (y < 6 && map[x][y + 2] == 2) {    //满箱子右边是目标地
							map[x][y + 2] = 5;
							map[x][y + 1] = 6;
							map[x][y] = 0;
							score++;
							++y;
						}
					}
					else if (map[x][y + 1] == 0) {   //如果角色右边是空地
						map[x][y + 1] = 4;
						map[x][y] = 0;
						score++;
						++y;
					}
					else if (map[x][y + 1] == 2) {
						map[x][y + 1] = 6;
						map[x][y] = 0;
						score++;
						++y;
					}
				}
				else if (map[x][y] == 6) {     //如果角色位于标记地
					if (map[x][y + 1] == 5) {   //如果左侧箱子位于标记地
						if (y < 6 && map[x][y + 2] == 0) {      //如果箱子左侧是空地
							map[x][y + 2] = 3;
							map[x][y + 1] = 6;
							map[x][y] = 2;
							score++;
							++y;
						}
						else if (y < 6 && map[x][y + 2] == 2) {    //如果箱子左侧是标记地
							map[x][y + 2] = 5;
							map[x][y + 1] = 6;
							map[x][y] = 2;
							score++;
							++y;
						}
					}
					else if (map[x][y + 1] == 3) {   //如果左侧是个空箱子
						if (y < 6 && map[x][y + 2] == 0) {  //如果箱子左侧是个空地
							map[x][y + 2] = 3;
							map[x][y + 1] = 4;
							map[x][y] = 2;
							score++;
							++y;
						}
						else if (y < 6 && map[x][y + 2] == 2) {  //如果箱子左侧是一个标志地
							map[x][y + 2] = 5;
							map[x][y + 1] = 4;
							map[x][y] = 2;
							score++;
							++y;
						}
					}
					else if (map[x][y + 1] == 0) {
						map[x][y + 1] = 4;
						map[x][y] = 2;
						++y;
						score++;

					}
					else if (map[x][y + 1] == 2) {
						map[x][y + 1] = 6;
						map[x][y] = 2;
						++y;
						score++;
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
							score++;
							++x;
						}
						else if (x < 5 && map[x + 2][y] == 2) {   //如果箱子下面是一个标志地
							map[x + 2][y] = 5;       //箱子移动至目标地
							map[x + 1][y] = 4;
							map[x][y] = 0;
							score++;
							++x;
						}
					}
					else if (map[x + 1][y] == 5) {     //角色下面是一个满箱子
						if (x < 5 && map[x + 2][y] == 0) {    //如果满箱子下面是空地
							map[x + 2][y] = 3;
							map[x + 1][y] = 6;    //角色移动到目标地
							map[x][y] = 0;
							score++;
							++x;
						}
						else if (x < 5 && map[x + 2][y] == 2) {    //满箱子下面是目标地
							map[x + 2][y] = 5;
							map[x + 1][y] = 6;
							map[x][y] = 0;
							score++;
							++x;
						}
					}
					else if (map[x + 1][y] == 0) {   //如果角色下面是空地
						map[x + 1][y] = 4;
						map[x][y] = 0;
						score++;
						++x;
					}
					else if (map[x + 1][y] == 2) {
						map[x + 1][y] = 6;
						map[x][y] = 0;
						score++;
						++x;
					}
				}
				else if (map[x][y] == 6) {     //如果角色位于标记地
					if (map[x + 1][y] == 5) {   //如果左侧箱子位于标记地
						if (x < 5 && map[x + 2][y] == 0) {      //如果箱子左侧是空地
							map[x + 2][y] = 3;
							map[x + 1][y] = 6;
							map[x][y] = 2;
							score++;
							++x;
						}
						else if (x < 5 && map[x + 2][y] == 2) {    //如果箱子左侧是标记地
							map[x + 2][y] = 5;
							map[x + 1][y] = 6;
							map[x][y] = 2;
							score++;
							++x;
						}
					}
					else if (map[x + 1][y] == 3) {   //如果左侧是个空箱子
						if (x < 5 && map[x + 2][y] == 0) {  //如果箱子左侧是个空地
							map[x + 2][y] = 3;
							map[x + 1][y] = 4;
							map[x][y] = 2;
							score++;
							++x;
						}
						else if (x < 5 && map[x + 2][y] == 2) {  //如果箱子左侧是一个标志地
							map[x + 2][y] = 5;
							map[x + 1][y] = 4;
							map[x][y] = 2;
							score++;
							++x;
						}
					}
					else if (map[x + 1][y] == 0) {
						map[x + 1][y] = 4;
						map[x][y] = 2;
						score++;
						++x;
					}
					else if (map[x + 1][y] == 2) {
						map[x + 1][y] = 6;
						map[x][y] = 2;
						score++;
						++x;
					}
				}
			}
			system("cls");
			show_map();
			flag = 0;
			for (int k = 0; k < Het; k++) {
				for (int m = 0; m < Wid; m++) {
					if (map[k][m] == 2) {
						flag = 1;
					}
				}
			}
			if (flag == 0) {
				system("cls");
				printf("You win!");
				break;
			}
			gotoxy(16, 5);
			printf("score:%d",score);
		}
		free(map);
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
	HideCursor();
}
void HideCursor(void)//隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void readin(void) {
	char temp[1000] = { 0 };
	while (fgets(temp, 1000, fp))Het++;
	Wid = 1;
	fseek(fp, 0L, SEEK_SET);
	for (int i = 1; temp[i] == ','; i += 2)Wid++;
	map = (int **)malloc(sizeof(int *)*Het);
	for (int i = 0; i < Het; i++) {
		map[i] = (int *)malloc(sizeof(int)*Wid);
	}
	for (int i = 0; i < Het; i++) {
		for (int j = 0; j < Wid; j++) {
			fscanf(fp, "%d,", &map[i][j]);
		}
	}
}