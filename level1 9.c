#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
	char map[9][13] = { "############",
		"S ##     ###",
		"#    #######",
		"## #########",
		"## ####     ",
		"## #### ####",
		"## #### ####",
		"##      ####",
		"############" };


	int dir[4][2] = { { -1,0, },{ 1,0 },{ 0,-1 },{ 0,1 } };
	int x = 1, y = 0, change_x = 0, change_y = 0;
	while (map[4][11] != 'S')
	{
		system("cls");
		for (int i = 0; i < 9; i++)
		{
			printf("%s\n", map[i]);
		}
		char ch = getch();
		switch (ch) {
		case 'w':
			change_x = dir[0][0];
			change_y = dir[0][1];
			break;
		case 's':
			change_x = dir[1][0];
			change_y = dir[1][1];
			break;
		case 'a':
			change_x = dir[2][0];
			change_y = dir[2][1];
			break;
		case'd':
			change_x = dir[3][0];
			change_y = dir[3][1];
			break;
		}

		if (map[x + change_x][y + change_y] == ' ')
		{
			map[x + change_x][y + change_y] = 'S';
			map[x][y] = ' ';
			x = x + change_x;
			y = y + change_y;
		}
	}
	system("cls");
	for (int i = 0; i < 9; i++)
	{
		printf("%s\n", map[i]);
	}
	printf("you win!!");
	system("pause");
	return 0;
}
