#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void to_xy(int x, int y);
void panel_score();
void show_pos();
void MoveBox(int x, int y, int xt, int yt);
int isfree(int x, int y, char ch);
int victory();
void MainMenu(FILE* fp);
void load(FILE* fp);
void show_map();
void show_goal();
void reset();

char maze[10][10];
int locat1[2] = { 10,10 };		//迷宫开始坐标
int locat2[2] = {0 };		//当前坐标
int goal[3][2] = {0};
int win = 0;
int step = 0;
int complete[3] = { 0 };

clock_t t1, t2;


void main()
{
	char input;
	int des = 0;
	
	FILE* fp = NULL;

	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

	MainMenu(fp);


	while (1)
	{

		
		if (win)
		{

			reset();
			MainMenu(fp);
		
		}

		show_map();
		show_goal();
		show_pos();

		input = _getch();
		switch (input)
		{
		case'w':
			if(isfree(locat2[0] , locat2[1] - 1,'*'))		//人不靠墙
			{
				if (isfree(locat2[0], locat2[1] - 1, '#'))			//不靠箱子且不靠墙
				{
					
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[1]--;
					step++;
				}
				else if (isfree(locat2[0], locat2[1] - 2, '*') && isfree(locat2[0], locat2[1] - 2, '#'))	//靠箱子且可移动
				{
					
					MoveBox(locat2[0], locat2[1] - 1, locat2[0], locat2[1] - 2);
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[1]--;
					step++;
					
				}
			}

			break;
		case's':
			if (isfree(locat2[0] , locat2[1] + 1, '*'))		//人不靠墙
			{
				if (isfree(locat2[0], locat2[1] + 1, '#'))			//不靠箱子且不靠墙
				{

					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[1]++;
					step++;
				}
				else if (isfree(locat2[0], locat2[1] + 2, '*') && isfree(locat2[0], locat2[1] + 2, '#'))	//靠箱子且可移动
				{
				
					MoveBox(locat2[0], locat2[1] + 1, locat2[0], locat2[1] + 2);
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[1]++;
					step++;
				}
			}

			break;
		case'a':
			if (isfree(locat2[0] - 1, locat2[1], '*'))		//人不靠墙
			{
				if (isfree(locat2[0]-1, locat2[1] , '#'))			//不靠箱子且不靠墙
				{

					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[0]--;
					step++;
				}
				else if (isfree(locat2[0]-2, locat2[1] , '*') && isfree(locat2[0]-2, locat2[1], '#'))	//靠箱子且可移动
				{
					
					MoveBox(locat2[0]-1, locat2[1], locat2[0]-2, locat2[1]);
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[0]--;
					step++;
				}
			}

			break;
		case'd':
			if (isfree(locat2[0] + 1, locat2[1] , '*'))		//人不靠墙
			{
				if (isfree(locat2[0] + 1, locat2[1], '#'))			//不靠箱子且不靠墙
				{

					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[0]++;
					step++;
				}
				else if (isfree(locat2[0] + 2, locat2[1], '*') && isfree(locat2[0] + 2, locat2[1], '#'))	//靠箱子且可移动
				{
					
					MoveBox(locat2[0] + 1, locat2[1], locat2[0] + 2, locat2[1]);
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[0]++;
					step++;
				}
			}
			break;
		case'm':
			MainMenu(fp);
			break;

	
		}
		
		show_map();
		show_goal();
		show_pos();
		if (victory())
		{
			panel_score();
		}
	}
	
}


void to_xy(int x, int y)												//到指定坐标
{
	HANDLE hout;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}



void panel_score()
{
	system("color 0e");

	to_xy(locat1[0] + 8, locat1[1] + 4);
	printf("#################################");
	to_xy(locat1[0] + 8, locat1[1] + 5);
	printf("#                               #");
	to_xy(locat1[0] + 8, locat1[1] + 6);
	printf("#          - VICTORY -          #");
	to_xy(locat1[0] + 8, locat1[1] + 7);
	printf("#                               #");
	to_xy(locat1[0] + 8, locat1[1] + 8);
	printf("#     time:%3.1f                 #", (double)((t2 - t1) / CLOCKS_PER_SEC));
	to_xy(locat1[0] + 8, locat1[1] + 9);
	printf("#     step:%-3d                  #",step);
	to_xy(locat1[0] + 8, locat1[1] + 10);
	printf("# Press any key to continue...  #");
	to_xy(locat1[0] + 8, locat1[1] + 11);
	printf("#################################");
	
	_getch();

	to_xy(locat1[0] + 8, locat1[1] + 4);
	printf("#################################");
	to_xy(locat1[0] + 8, locat1[1] + 5);
	printf("#                               #");
	to_xy(locat1[0] + 8, locat1[1] + 6);
	printf("#                               #");
	to_xy(locat1[0] + 8, locat1[1] + 7);
	printf("#    - A Philosjay Product -    #");
	to_xy(locat1[0] + 8, locat1[1] + 8);
	printf("#                               #");
	to_xy(locat1[0] + 8, locat1[1] + 9);
	printf("#                               #");
	to_xy(locat1[0] + 8, locat1[1] + 10);
	printf("#                               #");
	to_xy(locat1[0] + 8, locat1[1] + 11);
	printf("#################################");
	Sleep(900);
}


void show_pos()
{
	to_xy(locat2[0], locat2[1]);
	printf("O");
}



int isfree(int y, int x,char ch)
{
	if (maze[x-10][y-10] == ch)
		return 0;
	else
		return 1;
}
void MoveBox(int y, int x,int yt,int xt)
{
	maze[x-10][y-10] = ' ';
	maze[xt-10][yt-10] = '#';

}

int victory()
{
	if (complete[0]==1&& complete[1] == 1&& complete[2] == 1)
	{
		t2 = clock();
		win = 1;
		return 1;
	}
	else
		return 0;
}
void load(FILE* fp)
{
	char ch;

		
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			fscanf_s(fp, "%c", &ch);
			while (ch == '\n')
				fscanf_s(fp, "%c", &ch);
			maze[i][j] = ch;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			fscanf_s(fp, "%d", &goal[i][j]);
		}
	}
	fscanf_s(fp, "%d", &locat2[0]);
	fscanf_s(fp, "%d", &locat2[1]);
	locat2[0] += 10;
	locat2[1] += 10;
}
void show_map()
{
	to_xy(locat1[0], locat1[1]);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%c", maze[i][j]);
			if (j == 9)
			{
				to_xy(locat1[0], locat1[1] + i + 1);
			}
		}
	}
	to_xy(1, 1);
	printf("WSAD:direction");
	to_xy(1,2);
	printf("M:main menu");
	to_xy(1, 4);
	printf("O:you");
	to_xy(1, 5);
	printf("*:wall");
	to_xy(1, 6);
	printf("#:box");
	to_xy(1,7);
	printf("@:terminal");
}
void show_goal()
{
	for (int i = 0; i < 3; i++)
	{
		if (maze[goal[i][1]][goal[i][0]] == '#')
		{
			to_xy(goal[i][0] + 10, goal[i][1] + 10);
			printf("%c", '#');
			complete[i] = 1;
		}
		else
		{
			to_xy(goal[i][0] + 10, goal[i][1] + 10);
			printf("%c", '@');
			complete[i] = 0;
		}
	}
}
void MainMenu(FILE* fp)
{
	int ch = 0;
	system("color 0f");
	system("cls");
	to_xy(locat1[0]+8, locat1[1] -5);
	printf("#################################");
	to_xy(locat1[0]+8, locat1[1] -4);
	printf("#                               #");
	to_xy(locat1[0]+8 , locat1[1] - 3);
	printf("#     - A Push Box Game -       #");
	to_xy(locat1[0]+8 , locat1[1] -2);
	printf("#                               #");
	to_xy(locat1[0]+8, locat1[1] -1);
	printf("#  Enter                        #");
	to_xy(locat1[0]+8 , locat1[1] );
	printf("#  to choose the map 1~3 :      #");
	to_xy(locat1[0]+8 , locat1[1] + 1);
	printf("#                               #");
	to_xy(locat1[0]+8, locat1[1] + 2);
	printf("#################################");
	
	while (!(ch == 49 || ch == 50 || ch == 51))
	{
		ch = _getch();

	}
	switch (ch)
	{
	case'1':
		if (fopen_s(&fp, "map1.txt", "r") != 0)
			puts("cannot open file");
		break;
	case'2':
		if (fopen_s(&fp, "map2.txt", "r") != 0)
			puts("cannot open file");
		break;
	case'3':
		if (fopen_s(&fp, "map3.txt", "r") != 0)
			puts("cannot open file");
		break;

	}
	load(fp);
	fclose(fp);
	system("cls");
	t1 = clock();
}
void reset()
{
	win = 0;
	step = 0;
	t2 = t1 = 0;
}