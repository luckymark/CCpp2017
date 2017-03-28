#include<stdio.h>
#include<Windows.h>

char map[11][12]=
{
	"OOOOOOOOOOO",
	"OKO   O   O",
	"O O O O O O",
	"O   O O O O",
	"OOOOO O O O",
	"O       O O",
	"O OOOOOOO O",
	"O O   OO  O",
	"O O O OOOOO",
	"O   O      ",
	"OOOOOOOOOOO"
};
int x=1;
int y=1;

void print();

int main()
{
	print();
	while (true)
	{
		if (GetKeyState(VK_DOWN) < 0)
		{
			if (map[y+1][x] == ' ')
			{
				map[y][x] = ' ';
				y += 1;
				map[y][x] = 'K';
				print();
			}
			Sleep(100);
		}
		if (GetKeyState(VK_UP) < 0)
		{
			if (map[y -1][x] == ' ')
			{
				map[y][x] = ' ';
				y -= 1;
				map[y][x] = 'K';
				print();
			}
			Sleep(100);
		}
		if (GetKeyState(VK_RIGHT) < 0)
		{
			if (map[y ][x+1] == ' ')
			{
				map[y][x] = ' ';
				x += 1;
				map[y][x] = 'K';
				print();
			}
			Sleep(100);
		}
		if (GetKeyState(VK_LEFT) < 0)
		{
			if (map[y ][x-1] == ' ')
			{
				map[y][x] = ' ';
				x-=1;
				map[y][x] = 'K';
				print();
			}
			Sleep(100);
		}
		
		if (x == 10 && y == 9)
		{
			system("cls");
			printf("You win!\n");
			Sleep(1000);
			break;
		}
	}
	return 0;
}

void print()
{
	system("cls");
	for (int i = 0; i < 11; i++)
	{
		printf("%s\n", map[i]);
	}
}


