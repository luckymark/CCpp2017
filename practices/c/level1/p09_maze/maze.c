#include <windows.h>
#include <stdio.h>
#include <stdbool.h>


COORD man;
HANDLE handle_out;
int dx[5], dy[5];
bool flag = 0;
void go(int x, int y);

const bool map[10][19] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void prepare() {
	CONSOLE_CURSOR_INFO cci;
	handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
	cci.bVisible =  false;
	SetConsoleCursorInfo(handle_out, &cci);
	dx[0] = 0; dy[0] = 0;
	dx[1] = 0; dy[1] = -1;
	dx[2] = 0; dy[2] = 1;
	dx[3] = -1; dy[3] = 0;
	dx[4] = 1; dy[4] = 0;
	int i;
	for (i = 0; i < 10; i++)
	{
		int j;
		for (j = 0; j < 19; j++)
			if (map[i][j])
			{
				printf(" ");
			}
			else
			{
				printf("#");
			}
		puts("");
	}
	go(1, 1); printf("%c", 2);
	go(17, 8); printf("O");
}

void go(int x, int y) {
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle_out, pos);
}

int getkey() {
	if (GetKeyState(VK_UP) < 0)
		return 1;
	if (GetKeyState(VK_DOWN) < 0)
		return 2;
	if (GetKeyState(VK_LEFT) < 0)
		return 3;
	if (GetKeyState(VK_RIGHT) < 0)
		return 4;
	return 0;
}


bool check(int x, int y) {
	return map[y][x];
}

void move() {
	int tmp = getkey();
	if (tmp)
	{
		if (!check(man.X + dx[tmp], man.Y + dy[tmp]))
			return;
		go(man.X, man.Y);
		putchar(' ');
		man.X += dx[tmp];	man.Y += dy[tmp];
		go(man.X, man.Y);
		printf("%c", 2);
		if ((man.X == 17) && (man.Y == 8))
		{
			flag = 1;
			return;
		}
	}
}


int main() {
	prepare();
	man.X = 1;
	man.Y = 1;
	go(1, 1);
	while (1)
	{
		move();
		if (flag)
			break;
		Sleep(100);
	}
	go(0, 20);
	puts("You Win");
	return 0;
}