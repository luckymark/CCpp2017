/* Help the kid to go out of the maze. */

#include <stdio.h>
#define LINE 10
#define COLM 10
#define BEGINX 1
#define BEGINY 1
#define ENDX 8
#define ENDY 9

void drawMap(int kidx,int kidy,char map[LINE][COLM]);
void go(int *kidx,int *kidy,char map[LINE][COLM]);

/* 1 stands for wall,2 stands for way,and 0 stands for the kid. */
char map[LINE][COLM]={ {1,1,1,1,1,1,1,1,1,1},
                       {1,2,2,2,1,2,2,2,2,1},
                       {1,2,1,2,1,2,1,1,2,1},
                       {1,2,1,2,1,2,1,1,2,1},
                       {1,2,2,2,2,2,2,1,2,1},
                       {1,1,1,1,1,1,2,1,2,1},
                       {1,2,2,2,2,2,2,1,2,1},
                       {1,1,2,1,1,1,2,1,2,1},
                       {1,2,2,2,1,1,2,1,2,2},
                       {1,1,1,1,1,1,1,1,1,1}};


int main()
{	int kidx = BEGINX,kidy = BEGINY;
	int success=0;

	drawMap(kidx,kidy,map);
	printf("\nPress 'W' to go top,\nPrese 'S' to go down,\nPress 'A' to go left,\nPress 'D' to go right.\n");
	while (success!=1)
	{	go(&kidx,&kidy,map);
		drawMap(kidx,kidy,map);
		if (kidx== ENDX&& kidy==ENDY) success=1;}
		printf("\n ********************");
		printf("\n * Congratulations! *");
		printf("\n ********************\n");
	return 0;
}


void drawMap(int kidx,int kidy,char map[LINE][COLM])
{
	int i,j;
	putchar('\n');
	map[kidx][kidy] = 0;
	for (i=0; i<LINE; i++)
	{	for (j=0; j<COLM; j++)
		{	if (map[i][j]==1) putchar(35);
			else if(map[i][j]==0) putchar(64);
			else putchar(32);	}
		putchar('\n');  }
    map[kidx][kidy] = 2;
	putchar('\n');
}


void go(int *x,int *y,char map[LINE][COLM])
{
	char c;
	if (((c = getchar()) =='w' || c =='W') && map[*x-1][*y] == 2)	--*x;
	else if ((c =='s' || c =='S') && map[*x+1][*y] == 2)	++*x;
	else if ((c =='a' || c =='A') && map[*x][*y-1] == 2)	--*y;
	else if ((c =='d' || c =='D') && map[*x][*y+1] == 2) 	++*y;
	else puts("Invalid motion!");
}


