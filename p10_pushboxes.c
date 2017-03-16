#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void to_xy(int x, int y);
void panel_score();
int victory();
void background();
void show_pos();
void show_box();
int box_wall(int x, int y);
int box_box(int x, int y);
int box_near(int posx, int posy, int x, int y);
void show_goal();

char maze[20][20];
int locat1[2] = { 10,10 };		//迷宫坐标
int locat2[2] = { 11,11 };		//当前坐标
int box1[2] = { 18,18 };					//箱子坐标
int box2[2] = { 18,19 };
int box3[2] = { 20,20 };
int goal[3][2] = { {25,24},{13,14},{28,27} };
int win = 0;
int complete[3] = {0};



void main()
{
	char input;

	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

	system("color 0f");

	to_xy(locat1[0], locat1[1]);
	background();
	to_xy(locat2[0], locat2[1]);
	show_pos();
	show_box();


	while (1)
	{
		show_goal();
		show_box();
		if (win)
		{
			win = 0;

			system("color 0f");
			system("cls");
			locat2[0] = 11;
			locat2[1] = 11;
			to_xy(locat1[0], locat1[1]);
			background();
			to_xy(locat2[0], locat2[1]);
			show_pos();
		}

		input = _getch();
		switch (input)
		{
		case'w':
			if (maze[locat2[1] - 10 - 1][locat2[0] - 10] != '*')
			{
				if (!((box_near(locat2[0], locat2[1] - 1, box1[0], box1[1]) && (box_wall(box1[0], box1[1] - 1) || box_box(box1[0], box1[1] - 1)))|| 
					(box_near(locat2[0], locat2[1] - 1, box2[0], box2[1]) && (box_wall(box2[0], box2[1] - 1) || box_box(box2[0], box2[1] - 1)))||
					(box_near(locat2[0], locat2[1] - 1, box3[0], box3[1]) && (box_wall(box3[0], box3[1] - 1) || box_box(box3[0], box3[1] - 1)))))
				{
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[1]--;
					if (locat2[0] == box1[0] && locat2[1] == box1[1])
						box1[1]--;
					if (locat2[0] == box2[0] && locat2[1] == box2[1])
						box2[1]--;
					if (locat2[0] == box3[0] && locat2[1] == box3[1])
						box3[1]--;
				}

			}

			break;
		case's':
			if (maze[locat2[1] - 10 + 1][locat2[0] - 10] != '*')
			{
				if (!((box_near(locat2[0], locat2[1] + 1, box1[0], box1[1]) && (box_wall(box1[0], box1[1] + 1) || box_box(box1[0], box1[1] + 1)))||
					(box_near(locat2[0], locat2[1] + 1, box2[0], box2[1]) && (box_wall(box2[0], box2[1] + 1) || box_box(box2[0], box2[1] + 1)))||
					(box_near(locat2[0], locat2[1] + 1, box3[0], box3[1]) && (box_wall(box3[0], box3[1] + 1) || box_box(box3[0], box3[1] + 1)))))
				{
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[1]++;
					if (locat2[0] == box1[0] && locat2[1] == box1[1])
						box1[1]++;
					if (locat2[0] == box2[0] && locat2[1] == box2[1])
						box2[1]++;
					if (locat2[0] == box3[0] && locat2[1] == box3[1])
						box3[1]++;
				}
			}

			break;
		case'a':
			if (maze[locat2[0] - 10 - 1][locat2[1] - 10] != '*')
			{
				if (!((box_near(locat2[0] - 1, locat2[1], box1[0], box1[1]) && (box_wall(box1[0] - 1, box1[1]) || box_box(box1[0] - 1, box1[1])))||
					(box_near(locat2[0] - 1, locat2[1], box2[0], box2[1]) && (box_wall(box2[0] - 1, box2[1]) || box_box(box2[0] - 1, box2[1])))||
					(box_near(locat2[0] - 1, locat2[1], box3[0], box3[1]) && (box_wall(box3[0] - 1, box3[1]) || box_box(box3[0] - 1, box3[1])))))
				{
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[0]--;
					if (locat2[1] == box1[1] && locat2[0] == box1[0])
						box1[0]--;
					if (locat2[1] == box2[1] && locat2[0] == box2[0])
						box2[0]--;
					if (locat2[1] == box3[1] && locat2[0] == box3[0])
						box3[0]--;

				}
			}

			break;
		case'd':
			if (maze[locat2[0] - 10 + 1][locat2[1] - 10] != '*')
			{
				if (!((box_near(locat2[0] + 1, locat2[1], box1[0], box1[1]) && (box_wall(box1[0] + 1, box1[1]) || box_box(box1[0] + 1, box1[1])))||
					(box_near(locat2[0] + 1, locat2[1], box2[0], box2[1]) && (box_wall(box2[0] + 1, box2[1]) || box_box(box2[0] + 1, box2[1])))||
					(box_near(locat2[0] + 1, locat2[1], box3[0], box3[1]) && (box_wall(box3[0] + 1, box3[1]) || box_box(box3[0] + 1, box3[1])))))
				{
					to_xy(locat2[0], locat2[1]);
					printf(" ");
					locat2[0]++;
					if (locat2[1] == box1[1] && locat2[0] == box1[0])
						box1[0]++;
					if (locat2[1] == box2[1] && locat2[0] == box2[0])
						box2[0]++;
					if (locat2[1] == box3[1] && locat2[0] == box3[0])
						box3[0]++;
				}
			}

			break;
		}
		
		show_pos();
		
		


		if (victory())
		{
			show_box();
			to_xy(locat2[0], locat2[1]);
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
void background()
{
	for (int i = 0; i < 20; i++)
	{
		maze[i][0] = maze[i][19] = '*';
		for (int j = 0; j < 20; j++)
		{
			maze[0][j] = maze[19][j] = '*';
			
		}
	}
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			printf("%c", maze[i][j]);
			if (j == 19)
			{
				to_xy(locat1[0], locat1[1] + i + 1);
			}
		}
	}

}

int victory()
{
	for (int i = 0; i < 3; i++)
	{
		if ((goal[i][0] == box1[0] && goal[i][1] == box1[1]) || (goal[i][0] == box2[0] && goal[i][1] == box2[1]) || (goal[i][0] == box3[0] && goal[i][1] == box3[1]))
		{
			complete[i] = 1;
		}
		else
			complete[i] = 0;
	}
	if (complete[0] == 1&&complete[1] == 1&&complete[2] == 1)
	{
		win = 1;
		return 1;
	}
	else
	return 0;
}

void panel_score()
{
	system("color 0a");

	to_xy(locat1[0] + 8, locat1[1] + 4);
	printf("############################");
	to_xy(locat1[0] + 8, locat1[1] + 5);
	printf("#                          #");
	to_xy(locat1[0] + 8, locat1[1] + 6);
	printf("#                          #");
	to_xy(locat1[0] + 8, locat1[1] + 7);
	printf("#       - VICTORY -        #");
	to_xy(locat1[0] + 8, locat1[1] + 8);
	printf("#                          #");
	to_xy(locat1[0] + 8, locat1[1] + 9);
	printf("#                          #");
	to_xy(locat1[0] + 8, locat1[1] + 10);
	printf("#                          #");
	to_xy(locat1[0] + 8, locat1[1] + 11);
	printf("############################");

	system("pause");
}


void show_pos()
{
	to_xy(locat2[0], locat2[1]);
	printf("O");
}

void show_box()
{
	to_xy(box1[0], box1[1]);
	printf("#");
	to_xy(box2[0], box2[1]);
	printf("#");
	to_xy(box3[0], box3[1]);
	printf("#");
}
int box_wall(int x,int y)
{
	
	if (maze[x - 10][y - 10] == '*')
	{
		
		return 1;
	}
	else
		return  0;
}
int box_box(int x,int y)
{
	if ((x == box1[0] && y == box1[1]) || (x == box2[0] && y == box2[1])|| (x == box3[0] && y == box3[1]))
	{
		
		return 1;
	}
	else
		return 0;
}
int box_near(int posx, int posy,int x,int y)
{
	if (posx == x && posy ==y)
	{
		return 1;
	}
	else
		return 0;
}

void show_goal()
{
	to_xy(goal[0][0], goal[0][1]);
	printf("@");
	to_xy(goal[1][0], goal[1][1]);
	printf("@");
	to_xy(goal[2][0], goal[2][1]);
	printf("@");
}