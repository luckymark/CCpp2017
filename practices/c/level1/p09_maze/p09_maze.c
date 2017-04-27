#include<stdio.h>
#include<Windows.h>
#include<conio.h>
void HideCursor(void);
void show_map(void);
void welcome(void);
void move(void);
void gotoxy(int x, int y);
void reflash(int x, int y);
void readin(void);
char *getwall(int x,int y);
int count = 0;
int Het = 0, Wid = 0;
int **map;
char wall[16][4]= { "  ","━","┃","┓","━","━","┏","┳","┃","┛","┃","┫","┗","┻","┣" ,"╋" };
int main(void)
{
	int ch;
	system("cls");
	welcome();
	if ((ch = _getch()) == '1') {
		readin();
		show_map();
		move();
	}
	else return 0;
}
void welcome(void)
{
	char ch;//用来表示用户选择的选项
	system("mode con cols=25 lines=15");
	printf("\n\n\n");
	printf("       MAZE GAME\n\n");
	printf("     Just for fun\n\n");
	printf("        1-play\n\n");
	printf("        2-quit\n\n");
}
char * getwall(int x,int y)
{
	return wall[(map[x][y - 1]==1 ? 1 : 0) | (map[x + 1][y]==1 ? 2 : 0) | (map[x][y + 1]==1 ? 4 : 0) | (map[x - 1][y] ==1? 8 : 0)];
}
void show_map(void)
{

	system("mode con cols=65 lines=26");
	system("cls");
	for (int i = 0; i < Het; i++) {
		for (int j = 0; j < Wid; j++) {
			if (i == 0 && j == 0)printf("┏");
			else if (i == 0 && j == Wid - 1)printf("┓");
			else if (i == Het - 1 && j == 0)printf("┗");
			else if (i == Het - 1 && j == Wid - 1)printf("┛");
			else if (i == 0 && (j > 0 && j < Wid - 1)) {
				if (map[i + 1][j] == 1)printf("┳");
				else printf("━");
			}
			else if (i == Het - 1 && (j < Wid - 1 && j>0)) {
				if (map[i - 1][j] == 1)printf("┻");
				else if (map[i][j] == 0)printf("　");
				else printf("━");
			}
			else if ((i > 0 && i < Wid - 1) && j == 0) {
				if (map[i][j + 1] == 1)printf("┣");
				else printf("┃");
			}
			else if ((i > 0 && i < Het) && j == Wid - 1) {
				if (map[i][j - 1] == 1)printf("┫");
				else printf("┃");
			}
			else if (map[i][j] == 1)printf(getwall(i, j));
			else if (map[i][j] == 2)printf("LH");
			else printf("  ");
		}
		printf("   \n");
	}
	HideCursor();
}
void move(void)
{
	int x = 1, y = 1;
	static int count = 0;
	gotoxy(Wid * 2, Het / 5);
	printf("%d times moved", count);
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
			map[x][y - 1] = 2;	
			reflash(x, y);
			--y;
			reflash(x, y);
			count++;
		}
		else if (map[x - 1][y] == 0 && ch == 'w') {
			map[x][y] = 0;
			reflash(x, y);
			x = x - 1;
			map[x][y] = 2;
			reflash(x, y);
			count++;
		}
		else if (map[x][y + 1] == 0 && ch == 'd') {
			map[x][y] = 0;
			map[x][y + 1] = 2;
			reflash(x, y);
			y = y + 1;
			reflash(x, y);
			count++;
		}
		else if (map[x + 1][y] == 0 && ch == 's') {
			map[x][y] = 0;
			reflash(x,y);
			x = x + 1;
			map[x][y] = 2;	
			reflash(x, y);
			count++;
		}
		gotoxy(Wid * 2, Het / 5);
		printf("%d times moved ", count);
		if (x == Wid - 1 || y == Wid - 1) {
			system("mode con cols=25 lines=15");
			system("cls");
			printf("\n\n\n");
			printf("       You Win!!\n\n");
			printf("moved %d times in total", count);
			break;
		}
	}
}
void reflash(int i, int j)
{

	HideCursor();
	gotoxy(2 * j, i);
		if (i == 0 && j == 0)printf("┏");
		else if (i == 0 && j == Wid-1)printf("┓");
		else if (i == Het - 1 && j == 0)printf("┗");
		else if (i == Het - 1 && j == Wid - 1)printf("┛");
		else if (i == 0 && (j > 0 && j < Wid-1)) {
			if (map[i + 1][j] == 1)printf("┳");
			else printf("━");
		}
		else if (i ==Het-1  && (j < Wid-1 && j>0)) {
			if (map[i - 1][j] == 1)printf("┻");
			else if (map[i][j] == 0)printf("　");
			else printf("━");
		}
		else if ((i > 0 && i < Wid-1) && j == 0) {
			if (map[i][j + 1] == 1)printf("┣");
			else printf("┃");
		}
		else if ((i > 0 && i < Het) && j == Wid-1) {
			if (map[i][j - 1] == 1)printf("┫");
			else printf("┃");
		}
		else if (map[i][j] == 1)printf(getwall(i, j));
		else if (map[i][j] == 2)printf("LH");
		else printf("  ");
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
void readin(void) {
	char temp[1000] = { 0 };
	FILE *fp;
	fp = fopen("map.txt", "r");
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
			fscanf(fp,"%d,",&map[i][j]);
		}
	}
}
