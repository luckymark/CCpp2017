#include<stdio.h>
#include<Windows.h>

struct Point
{
	int x;
	int y;
};

//Func declr
void welcome();
void loadmap();
void game();
void move();
void refreshmap();
void ending();

//Global
int level = 0;
int totalscore;
int step=0;
char map[9][9];
FILE * fmap;
Point person, box[9], target[9];
int numberofbox=0;

int main()
{
	while (true)
	{
		welcome();
		if (level == -1) break;

		totalscore = 0;
		while (true)
		{
			loadmap();
			if (level == -2) break;
			
			game();
			
			if(level== 10)
			{
				ending();
			}
		}
	}
	return 0;
}

void welcome()
{
	system("cls");
	printf("***\nGame:PushBoxes\n***\n");
	printf("Input the level you want to start (1~10,and -1 to quit)\n-> ");
	scanf("%d", &level);
}

void loadmap()
{
	
	int index_box = 0, index_target = 0;
	char mapname[10] = "pb_00.txt";
	mapname[3] = '0' + level / 10;
	mapname[4] = '0' + level % 10;

	fmap = fopen(mapname, "r");
	if (fmap == NULL)
	{
		printf("Map reading error.\n");
		Sleep(2000);
		level = -2;
		return;
	}

	system("cls");
	printf("Loading...");

	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{

			while(
			( map[i][j] = fgetc(fmap) ) && ( map[i][j]=='\r' || map[i][j]=='\n' )
			);
			
			if (map[i][j] == 'P')
			{
				person.x = j;
				person.y = i;
			}
			if (map[i][j] == 'B')
			{
				box[index_box].x = j;
				box[index_box].y = i;
				index_box++;
			}
			if (map[i][j] == 'T')
			{
				target[index_target].x = j;
				target[index_target].y = i;
				index_target++;
			}
		}
	}
	for(int i=index_box;i<9;i++)
	{
		box[i].x=0;
		box[i].y=0;
		target[i].x=0;
		target[i].y=0;
	}
	numberofbox = index_box;
	fclose(fmap);
}

void game()
{
	step = 0;
	refreshmap();
	while(true)
	{
		move();
		
	
		//win
		int counter = 0;
		int i, j;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				if (box[i].x == target[j].x && box[i].y == target[j].y && box[i].x!=0) //box.x!=0 ensure that box is inited.
				{
					counter++;
				}
			}
		}
		if (counter == numberofbox)
		{
			printf(" Pass!\n");
			if (step<100)
			{
				totalscore += 100 - step;
				printf(" You get %d points.\n", 100 - step);
			}
			else
			{
				printf(" You get 0 point.\n");
			}
			printf(" Total : %d\n", totalscore);
	
			Sleep(5000);
			level++;
			break;
		}
	}

}

void move()
{
	int ismoved=0;
	Point currentperson = person;

	if (GetKeyState(VK_UP) < 0)
	{
		if (map[person.y - 1][person.x] == ' ' || map[person.y - 1][person.x] == 'T')
		{
			person.y--;
			step++;
			ismoved=1;
		}
		else if (map[person.y - 1][person.x] == 'B' && (map[person.y - 2][person.x] == ' ' || map[person.y - 2][person.x] == 'T'))
		{
			int i;
			for (i = 0; i < 9; i++)
			{
				if (box[i].x == person.x && box[i].y == person.y - 1)
				{
					map[box[i].y][box[i].x] = ' ';
					box[i].y--;
					map[box[i].y][box[i].x] = 'B';
				}
			}
			person.y--;
			step++;
			ismoved=1;
		}


		Sleep(50);
	}
	if (GetKeyState(VK_DOWN) < 0)
	{
		if (map[person.y + 1][person.x] == ' ' || map[person.y + 1][person.x] == 'T')
		{
			person.y++;
			step++;
			ismoved=1;
		}
		else if (map[person.y + 1][person.x] == 'B' && (map[person.y + 2][person.x] == ' ' || map[person.y + 2][person.x] == 'T'))
		{
			int i;
			for (i = 0; i < 9; i++)
			{
				if (box[i].x == person.x && box[i].y == person.y + 1)
				{
					map[box[i].y][box[i].x] = ' ';
					box[i].y++;
					map[box[i].y][box[i].x] = 'B';
				}
			}
			person.y++;
			step++;
			ismoved=1;
		}
		Sleep(50);
	}
	if (GetKeyState(VK_LEFT) < 0)
	{
		if (map[person.y][person.x - 1] == ' ' || map[person.y][person.x - 1] == 'T')
		{
			person.x--;
			step++;
			ismoved=1;
		}
		else if (map[person.y][person.x - 1] == 'B' && (map[person.y][person.x - 2] == ' ' || map[person.y][person.x - 2] == 'T'))
		{
			int i;
			for (i = 0; i < 9; i++)
			{
				if (box[i].x == person.x - 1 && box[i].y == person.y)
				{
					map[box[i].y][box[i].x] = ' ';
					box[i].x--;
					map[box[i].y][box[i].x] = 'B';
				}
			}
			person.x--;
			step++;
			ismoved=1;
		}
		Sleep(50);
	}
	if (GetKeyState(VK_RIGHT) < 0)
	{
		if (map[person.y][person.x + 1] == ' ' || map[person.y][person.x + 1] == 'T')
		{
			person.x++;
			step++;
			ismoved=1;
		}
		else if (map[person.y][person.x + 1] == 'B' && (map[person.y][person.x + 2] == ' ' || map[person.y][person.x + 2] == 'T'))
		{
			int i;
			for (i = 0; i < 9; i++)
			{
				if (box[i].x == person.x + 1 && box[i].y == person.y)
				{
					map[box[i].y][box[i].x] = ' ';
					box[i].x++;
					map[box[i].y][box[i].x] = 'B';
				}
			}
			person.x++;
			step++;
			ismoved=1;
		}
		Sleep(50);
	}

	int i, istarget = 0;
	for (i = 0; i < 3; i++)
	{
		if (target[i].x == currentperson.x &&target[i].y == currentperson.y)
		{
			istarget = 1;
		}
	}
	if (istarget)
	{
		map[currentperson.y][currentperson.x] = 'T';
	}
	else
	{
		map[currentperson.y][currentperson.x] = ' ';
	}
	map[person.y][person.x] = 'P';
	if(ismoved)
	{
		refreshmap();
	}
}

void refreshmap()
{
	system("cls");
	for (int i = 0; i<9; i++)
	{
		for (int j = 0; j<9; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void ending()
{
	printf("You have passed all£¡\n");
	printf("Total:%d points.\n",totalscore) ;
}








