# include<stdio.h>
# include<stdlib.h>
#include <conio.h>
# define SIZE 10

int maze[SIZE][SIZE] = {
	1,1,1,1,1,1,1,1,1,1,
	1, 0, 0, 0, 1, 0, 1, 1, 0, 1,
	1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
	1,0,0,1,0,1,1,1,0,1,
	1,1,0,1,0,1,0,0,1,1,
	1,0,0,1,0,0,0,1,0,1,
	1,1,0,0,1,1,1,0,0,1,
	1,1,1,0,0,0,1,1,0,1,
	1,0,0,0,1,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1

};

void begin()
{
	printf("this is a small maze game\n");
	printf("please enter any key to continue...");
	getchar();
	system("cls");
	for (int i = 0; i < 40; i++) {
		printf("Maze generation...");
		system("cls");
	}
}

void show_maze(int prex,int prey,char c,int cnt)
{
	system("cls");
	int i, j;
	
	for ( i = 0; i < SIZE; i++) {
		for ( j = 0; j < SIZE; j++) {
			if (maze[i][j]==1)		printf("%c%c", 0xa8, 0x80);
			else if (i == prey&&j == prex)	printf("**");
			else printf("  ");
			if (j == SIZE - 1)	printf("\n");
		}
	}
	if (cnt) {
		printf("You can't head to a wall!!\n");
	}
}

int ifhead(int *nowx, int *nowy,char c)
{
	if (maze[*nowy][*nowx] == 1) {
		
		switch (c)
		{
		case 72:
			*nowy += 1;
			break;
		case 75:
			*nowx += 1;
			break;
		case 80:
			*nowy -= 1;
			break;
		case 77:
			*nowx -= 1;
			break;
		}
		return 1;
	}
	return 0;
}

int main()
{
	int k = 0, cnt = 0;
	int nowx = 1, nowy = 1;
	begin();
	show_maze(1,1,0,cnt);

	while (1) {
		char c = _getch();

		switch (c)
		{
		case 72:
			nowy -= 1;
			break;
		case 75:
			nowx -= 1;
			break;
		case 80:
			nowy += 1;
			break;
		case 77:
			nowx += 1;
			break;
		}
		cnt = ifhead(&nowx, &nowy, c);
		show_maze(nowx, nowy, c,cnt);
		
		if (nowx == SIZE - 2 && nowy == SIZE - 2) {
			printf("Congratulations,You have passed this game!\n");
			break;
		}
	}

	system("pause");
	return 0;
}
