# include<stdio.h>
# include<stdlib.h>
#include <conio.h>
# define SIZE 8

int cnt;
int MAP[SIZE][SIZE] = {
	{ 0,0,1,1,1,0,0,0 },
	{ 0,0,1,4,1,0,0,0 },
	{ 0,0,1,2,1,1,1,1 },
	{ 1,1,1,0,0,2,4,1 },
	{ 1,4,0,2,3,1,1,1 },
	{ 1,1,1,1,2,1,0,0 },
	{ 0,0,0,1,4,1,0,0 },
	{ 0,0,0,1,1,1,0,0 }
};

int init()
{
	printf("This is a small push boxes game,\nPlease enter any key to continue...\n");
	for (int i = 0; i < 30; i++) {
		printf("please waiting for a second...\n");
		system("cls");
	}
}
int show_map()
{
	system("cls");
	int  i, j;
	for ( i = 0; i < SIZE ; i++) {
		for (j = 0; j < SIZE ; j++) {
			switch (MAP[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("%c%c", 0xa8, 0x80);			//代表墙壁
				break;
			case 2:
				printf("□");											//代表箱子
				break;
			case 3:
				printf("⊙");										//代表自己
				break;
			case 4:
				printf("☆");											//代表将要推往的地点
				break;
			case 5:
				printf("★");											//代表已经推到的箱子
				break;
			case 6:
				printf("◆");											//表示人和地点是在一个地方
				break;
			}
			if (j == SIZE - 1)	printf("\n");
		}
	}
}

int mod_map(int *nowx,int *nowy,int *lastx,int *lasty)
{
	if (MAP[*nowy][*nowx] == 2) {
		//如果下下一位是空地
		if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 0) {
			MAP[*nowy][*nowx] = 3;
			MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] = 2;
			MAP[*lasty][*lastx] = 0;
		}
		//如果下下一个是目的地
		else if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 4) {
			MAP[*nowy][*nowx] = 3; 
			MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] = 5;
			MAP[*lasty][*lastx] = 0; cnt++;
		}
		//如果下下一个是墙
		else if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 1) {
			*nowx = *lastx;  *nowy = *lasty;
		}
	}
	else if(MAP[*nowy][*nowx] == 0){					//如果什么都没有，就换位
		MAP[*nowy][*nowx] = 3; 
		MAP[*lasty][*lastx] = 0;
	}
	//如果是撞到墙了，修改nowx，nowy的值
	else if (MAP[*nowy][*nowx] == 1) {
		*nowx = *lastx;  
		*nowy = *lasty;
	}				
	//如果下一个位置是目的地
	else if (MAP[*nowy][*nowx] == 4) {
		MAP[*nowy][*nowx] = 6; 
		MAP[*lasty][*lastx] = 0;
	}
	//如果下一个地方是已经到达目的地的箱子
	else if (MAP[*nowy][*nowx] == 5) {
			//如果箱子的下一个位置是空地
			if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 0) {
				MAP[*nowy][*nowx] = 6;
				MAP[*lasty][*lastx] = 0; 
				MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] = 2;
				cnt--;
			}
			//如果下下一个是目的地
			else if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 4) {
				MAP[*nowy][*nowx] = 6; 
				MAP[*lasty][*lastx] = 0;
				MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] = 5;
			}
			//如果下下一个是墙
			else if (MAP[*nowy + *nowy - *lasty][*nowx + *nowx - *lastx] == 1) {
				*nowx = *lastx;  
				*nowy = *lasty;
			}
	}
	
	show_map();
	return;
}

int main()
{
	init();
	show_map();

	int nowx=4, nowy=4;
	int lastx, lasty;
	while (1) {
		lastx = nowx, lasty = nowy;
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
		mod_map(&nowx, &nowy, &lastx, &lasty);
		if (cnt == 4)	break;
	}
	printf("Congratulations!You win!");
	
	system("pause");

	return 0;
}
