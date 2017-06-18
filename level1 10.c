#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define length1 9*13
int judge_cho(char* judge,char**map);
int judge_star(char* judge, char**map);
void output_map();
void game();

int main()
{
# if 0
	output_map();
# endif	
	 game();
	system("pause");
	return 0;
}

int judge_cho(char* judge,char **map)
{
	if (*judge == '1'&&(map[1][5] != 'o' || map[4][4] != 'o' || map[6][5] != 'o'))
	{
		return 1;
	}
	if (*judge == '2' && (map[2][2] != 'o' || map[3][3] != 'o'))
	{
		return 1;
	}
	return 0;

}

void output_map() {

	char map1[9][13] = { "############",
		"#####* #####",
		"#####  #####",
		"### o    ###",
		"### * So ###",
		"###   o  ###",
		"#####*######",
		"##### ######",
		"############" };

	char map2[7][9] = { " ###### ",
		" #    ##",
		"##*##o #",
		"#  *o  #",
		"#  #   #",
		"#  S ###",
		"######  " };

	FILE *wmap = fopen("E:\\map.dat", "w+b");
	if (!wmap)
	{
		printf("can't open the file");
		exit(1);
	}
	rewind(wmap);
	fwrite(map1, sizeof(map1), 1, wmap);
	fwrite(map2, sizeof(map2), 1, wmap);
	fclose(wmap);

}
int judge_star(char* judge, char **map)
{
	if (*judge == '1' )
	{
		if (map[1][5] == ' ')
		    map[1][5] = '*';
		if (map[4][4] == ' ')
			map[4][4] = '*';
		if (map[6][5] == ' ')
			map[6][5] = '*';
		
	}
	if (*judge == '2') 
	{
		if (map[2][2] == ' ')
		{
		
			map[2][2] = '*';
		}
	if (map[3][3] == ' ')
		map[3][3] = '*';
		return 1;
	}
	return 0;
}
void game()
{
	FILE *rmap = fopen("E:\\map.dat", "r+b");
	if (!rmap)
	{
		printf("can't open the file");
		exit(1);
	}
	printf("Please choose the stage,1 or 2\n");
	printf("After game begin,input q to quit\n");
	printf("Use w a s d to move\n");

	char **map = NULL;
	char cho;
	int row = 0, column = 0, x, y, flag = 1;

	cho = getchar();
	switch (cho)
	{
	case '1':
	{
		row = 9; column = 13; x = 4; y = 6;
		map = (char**)calloc(row, sizeof(char*));
		map[0] = (char*)calloc(column*row, sizeof(char));
		//memset(map[0], '\0', column*row*sizeof(char));(malloc)
		for (int i = 1; i < row; i++)
			map[i] = map[i - 1] + column;
		fseek(rmap, 0L, SEEK_SET);
		fread(map[0], column * sizeof(char), row, rmap);
		flag = 0;
		for (int i = 0; i < row; i++)
			printf("%s", map[i]);
		break;
	}

	case '2':
	{
		row = 7; column = 9; x = 5; y = 3;
		map = (char**)calloc(row, sizeof(char*));
		map[0] = (char*)calloc(column*row, sizeof(char));
		//memset(map[0], '\0', column*row * sizeof(char));
		for (int i = 1; i < row; i++)
			map[i] = map[i - 1] + column;

		fseek(rmap, 1L * length1, SEEK_SET);
		fread(map[0], column * sizeof(char), row, rmap);
		flag = 0;
		break;
	}
	default:
		printf("1 or 2 haven't been chosen");
		exit(0);
	}
	fclose(rmap);

	//pushbox
	int dir[4][2] = { { -1,0, },{ 1,0 },{ 0,-1 },{ 0,1 } };
	int   change_x = 0, change_y = 0;
	char score[] = "100";
	while (judge_cho(&cho, map))
	{
		system("cls");


		for (int i = 0; i < row; i++)
		{
			printf("%s\n", map[i]);
			
		}
		printf("score:%s", score);


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
		case'q':
			exit(0);

		}
		if (map[x + change_x][y + change_y] == 'o'&&map[x + change_x * 2][y + change_y * 2] == ' ')
		{
			map[x + change_x][y + change_y] = 'S';
			map[x + change_x * 2][y + change_y * 2] = 'o';
		}
		else if (map[x + change_x][y + change_y] == ' ')
		{
			map[x + change_x][y + change_y] = 'S';
		}
		else if (map[x + change_x][y + change_y] == '*')
		{
			map[x + change_x][y + change_y] = 'S';
		}
		else if (map[x + change_x][y + change_y] == 'o'&&map[x + change_x * 2][y + change_y * 2] == '*')
		{
			map[x + change_x][y + change_y] = 'S';
			map[x + change_x * 2][y + change_y * 2] = 'o';
		}
		else
		{
			continue;
		}
		map[x][y] = ' ';
		judge_star(&cho, map);
		x = x + change_x;
		y = y + change_y;
		if (score[2] != '0')
		{
			score[2]--;
		}
		else if (score[2] == '0'&&score[1] != '0')
		{
			score[2] = '9';
			score[1]--;
		}
		else if (score[0] != '0')
		{
			score[2] = '9';
			score[1] = '9';
			score[0]--;
		}
		else
		{
			printf("game over");
			exit(0);
		}
	}
	system("cls");

	for (int i = 0; i < row; i++)
	{
		printf("%s\n", map[i]);
		
	}
	//output result and send score into document
	printf("score:%s\n", score);
	printf("you win!!");
	FILE *pmap = fopen("E:\\map.dat", "a+b");
	if (!pmap)
	{
		printf("can't open the file");
		exit(1);
	}
	fseek(pmap, 0L, SEEK_END);
	fwrite(score,sizeof(score), 1, pmap);
	fclose(pmap);
	
	free(map[0]);
	free(map);

}
