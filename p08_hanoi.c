#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <conio.h>
#include<stdbool.h>
#include<time.h>
#define WIDTH 5		
void background();
void pole(char space[WIDTH]);
void button();
void to_xy(int x, int y);
void start(char A[WIDTH][WIDTH*2+1]);
void show_disk(char A[WIDTH][WIDTH * 2 + 1], int x, int y, int h);
void show_arrow(int x, int y);
void control_ar(char input);
void show_top();
void to_up(char A[WIDTH][WIDTH * 2 + 1], int D[WIDTH], int h);
void to_down(char A[WIDTH][WIDTH * 2 + 1], int D[WIDTH], int* h);
void to_right(char A[WIDTH][WIDTH * 2 + 1], char B[WIDTH][WIDTH * 2 + 1]);
void to_left(char A[WIDTH][WIDTH * 2 + 1], char B[WIDTH][WIDTH * 2 + 1]);
int victory();
void panel_score(double t);
void panel_main();
void reset_disk(char A[WIDTH][WIDTH * 2 + 1], int a[WIDTH]);
void reset_arrow();


int locat1[2] = { 20,6 };		//圆盘A起始
int locat2[2] = { (20 + (WIDTH * 2 + 1 + 2)),6 };	//圆盘B起始
int locat3[2] = { (20 + (WIDTH * 2 + 1 + 2) * 2),6 };		//圆盘C起始
int locat4[2] = { 20,(6 + WIDTH) };						//底座起始
int locat5[2] = { 18 + WIDTH,(8 + WIDTH) };		//箭头起始

int doc_A[WIDTH] = { 0};
int doc_B[WIDTH] = { 0 };
int doc_C[WIDTH] = { 0};
int doc_top;

int a, b, c;
int* pa = &a;
int* pb = &b;
int* pc = &c;


bool move_y = false;
int move_x = 0;
int step = 0;
int win = 1;

char top[WIDTH * 2 + 1] = { 0 };
char A[WIDTH][WIDTH * 2 + 1] = { 0 };
char B[WIDTH][WIDTH * 2 + 1] = { 0 };
char C[WIDTH][WIDTH * 2 + 1] = { 0 };

void main()
{

	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);

	clock_t t1, t2;
	char input;

	system("color 0f"); 

	start(A);
	
	while (1)
	{
		if (win)
		{
			panel_main();
			system("cls");
			win = 0;
			t1 = clock();
		}

		background();
		show_top();
		show_disk(A,locat1[0], locat1[1],a);
		show_disk(B,locat2[0], locat2[1], b);
		show_disk(C,locat3[0], locat3[1], c);
		show_arrow(locat5[0], locat5[1]);
		input = _getch();
		t2 = clock();
		control_ar(input);
		if (win=victory())
		{
			t2 = clock();
			panel_score((double)(t2-t1)/CLOCKS_PER_SEC);
			start(A);
			reset_disk(B,doc_B);
			reset_disk(C,doc_C);
			reset_arrow();
			step = 0;
			system("color 0f");
		}
		
		
		system("cls");
	}
	_getch();
}



void background()
{
	char space[WIDTH] = { 0 };

	puts("\n\n\n\n");
	pole(space);
	to_xy(locat4[0], locat4[1]);
	button();

}
void pole(char space[WIDTH])
{
	for (int i = 0; i < WIDTH+1; i++)		//杆高度
	{
		printf("                    ");
		for (int i = 0; i < 3; i++)		//杆个数
		{
			for (int i = 0; i < WIDTH; i++)
				printf("%c", space[i]);
			printf("|");
			for (int i = 0; i < WIDTH; i++)
				printf("%c", space[i]);
			printf("  ");
		}
		printf("\n");
	}
}
void button()
{
	for (int i = 0; i < 3; i++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			printf("=");
		}
		printf("|");
		for (int i = 0; i < WIDTH; i++)
		{
			printf("=");
		}
		printf("  ");
	}
}
void to_xy(int x,int y)
{
	HANDLE hout;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}

void start(char A[WIDTH][WIDTH * 2 + 1])
{
	a = WIDTH;
	b = 0;
	c = 0;

	int count = 3;
	for (int i = 0; i < WIDTH; i++)
	{
			for (int x = 0; x <count; x++)
			{
				if(WIDTH - 1 - i + x==10)
					A[i][WIDTH - 1 - i + x] = '|';
				A[i][WIDTH-1 - i + x] = 'A';
			}
			count+=2;
			doc_A[i] = i+1;
	}
}
void show_disk(char A[WIDTH][WIDTH * 2 + 1],int x,int y,int h)
{
	
	for (int i = 0;i < WIDTH; i++)
	{
		if (WIDTH - h > i)
			continue;
		else
		{
			to_xy(x, y + i);
			for (int j = 0; j < WIDTH * 2 + 1; j++)
			{
				printf("%c", A[i][j]);
			}
		}
	}
}
void show_arrow(int x,int y)
{
	char arrow[9][5] =
	{
		{ ' ', ' ', '*', ' ', ' ' },
		{ ' ', '*', '*', '*', ' ' },
		{ '*', '*', '*', '*', '*' },
		{ ' ', '|', '*', '|', ' ' },
		{ ' ', '|', '*', '|', ' ' },
		{ ' ', '|', '*', '|', ' ' },
	};
	for (int i = 0; i < 9; i++)
	{
		to_xy(x, y + i);
		for (int j = 0; j < 5; j++)
		{
			printf("%c", arrow[i][j]);
		}
	}
}
void show_top()
{
	to_xy(locat5[0]+2-WIDTH,3);
	for (int i = 0; i < WIDTH*2+1; i++)
	{
		printf("%c", top[i]);
	}
}


void control_ar(char input)
{
	switch (input)
	{
	case'a':
		if (move_x > 0)
		{
			if (move_x == 1)				//箭头在B
			{

				to_left(A, B);
				move_x--;
			}

			else if (move_x == 2)			//箭头在C
			{
				to_left(B, C);
				move_x--;
			}


		}
		else								//箭头在C
			printf("\a");
		break;
	case'd':
		if (move_x < 2)
		{
			if (move_x == 0)				//箭头在A
			{
				
				to_right(B, A);
				move_x++;
			}

			else if (move_x == 1)			//箭头在B
			{
				to_right(C, B);
				move_x++;
			}
				

		}
		else								//箭头在C
			printf("\a");
		break;
	case'w':
		if (move_y == false)
		{
			if (move_x == 1)	//箭头在B
			{
				if (b != 0)
				{
					to_up(B, doc_B,b);
					move_y = true;
					b--;
				}
			}

			else if (move_x==0)	//箭头在A
			{
				if (a != 0)
				{
					to_up(A, doc_A, a);
					move_y = true;
					a--;
				}
			}
			else			//箭头在C
			{
				if (c != 0)
				{
					to_up(C, doc_C, c);
					move_y = true;
					c--;
				}
			}
		}
		else
			printf("\a");
		break;
	case's':
		if (move_y == true)
		{
			if (move_x == 1)	//箭头在B
			{
				to_down(B, doc_B, pb);
			}
			else if (move_x==0)	//箭头在A
			{
				to_down(A, doc_A, pa);
			}
			else	//箭头在C
			{
				to_down(C,doc_C, pc);
			}
			
		}
		else
			printf("\a");
		break;
	}
}

void to_up(char A[WIDTH][WIDTH * 2 + 1],int D[WIDTH],int h)
{
		for (int i = 0; i < WIDTH; i++)
		{
			if (i < WIDTH - h)		//找到顶层
				continue;
			else
			{
				for (int j = 0; j < WIDTH * 2 + 1; j++)
				{
					if (A[i][j] != 0)
					{
						top[j] = A[i][j];
						if (j == WIDTH)
							A[i][j] = '|';
						else
							A[i][j] = 0;
					}
				}
				doc_top = D[i];		//交换数据
				D[i] = 0;
				break;
			}
		}
}

void to_down(char A[WIDTH][WIDTH * 2 + 1],int D[WIDTH], int * h)
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (i < WIDTH - *h-1 )		//找到顶层,针对行
			continue;
		
		else
		{
			if (*h == 0)	//当顶层是底座时
			{
				move_y = false;
				(*h)++;
				step++;
				D[i] = doc_top;		//交换数据
				doc_top = 0;
				for (int j = 0; j < WIDTH * 2 + 1; j++)		//针对列
				{
					if (top[j] != 0)
					{
						A[i][j] = top[j];
						top[j] = 0;
					}
				}
			}
			else if (doc_top < D[i + 1])		//判断能否放下
			{
				move_y = false;
				(*h)++;
				step++;
				D[i] = doc_top;		//交换数据
				doc_top = 0;
				for (int j = 0; j < WIDTH * 2 + 1; j++)		//针对列
				{
					if (top[j] != 0)
					{
						A[i][j] = top[j];
						top[j] = 0;
					}
				}
			}
			else
				printf("\a");
			break;
		}
	}
}
void to_right(char A[WIDTH][WIDTH * 2 + 1], char B[WIDTH][WIDTH * 2 + 1])
{
	locat5[0] += WIDTH * 2 + 3;
}
void to_left(char A[WIDTH][WIDTH * 2 + 1], char B[WIDTH][WIDTH * 2 + 1])
{
	locat5[0] -= WIDTH * 2 + 3;
}


void reset_disk(char A[WIDTH][WIDTH * 2 + 1],int a[WIDTH])
{
	for (int i = 0; i < WIDTH; i++)
	{
		for (int j = 0; j < WIDTH * 2 + 1; j++)
			A[i][j] = 0;
		a[i] = 0;
	}
}
void reset_arrow()
{
	move_x = 0;
	locat5[0] = 18 + WIDTH;
}
void panel_score(double t)
{

	int a[2] = { 20 + (WIDTH * 2 + 1 + 2) ,5 };

	printf("\a");
	to_xy(a[0], a[1]);
	printf("*******************************************\n");
	to_xy(a[0], a[1] + 1);
	printf("*                                         *\n");
	to_xy(a[0], a[1] + 2);
	printf("*             -- VICTORY --               *\n");
	to_xy(a[0], a[1] + 3);
	printf("*                                         *\n");
	to_xy(a[0], a[1] + 4);
	printf("*    level: %-10d                    *\n", WIDTH);
	to_xy(a[0], a[1] + 5);
	printf("*    step : %-10d                    *\n", step);
	to_xy(a[0], a[1] + 6);
	printf("*    time : %-10.2f                    *\n", t);
	to_xy(a[0], a[1] + 7);
	printf("*                                         *\n");
	to_xy(a[0], a[1] + 8);
	printf("*                                         *\n");
	to_xy(a[0], a[1] + 9);
	printf("*******************************************\n");

	for (int i = 0; i<3; i++)
	{
		to_xy(a[0] + 1, a[1] + 8);
		printf("        Have a rest...            ");
		Sleep(500);
		to_xy(a[0] + 1, a[1] + 8);
		printf("                                  ");
		Sleep(500);

	}
	to_xy(a[0] + 1, a[1] + 8);
	printf("        Press any key to continue...  ");
	_getch();

}
void panel_main()
{
	int a[2] = { 13 + (WIDTH * 2 + 1 + 2) ,5 };
	int go = 0;
	to_xy(a[0], a[1]);
	printf("*************************************************************************\n");
	to_xy(a[0], a[1] + 1);
	printf("*           #    #      ##         #     #      ###         #####       *\n");
	to_xy(a[0], a[1] + 2);
	printf("*          #    #     #   #       # #   #     #    #         #          *\n");
	to_xy(a[0], a[1] + 3);
	printf("*         ######     ######      #  #  #    #       #       #           *\n");
	to_xy(a[0], a[1] + 4);
	printf("*        #    #     #     #     #   # #      #     #       #            *\n");
	to_xy(a[0], a[1] + 5);
	printf("*       #    #    #       #    #    #         ###       #####           *\n");
	to_xy(a[0], a[1] + 6);
	printf("*                                                                       *\n");
	to_xy(a[0], a[1] + 7);
	printf("*                       - A Philosjay Product -                         *\n");
	to_xy(a[0], a[1] + 8);
	printf("*                                                                       *\n");
	to_xy(a[0], a[1] + 9);
	printf("*                                                                       *\n");
	to_xy(a[0], a[1] + 10);
	printf("*                                                                       *\n");
	to_xy(a[0], a[1] + 11);
	printf("*************************************************************************\n");

	for (int i = 0; i<3; i++)
	{

		to_xy(a[0] + 1, a[1] + 10);
		printf("                            Now loading...               ");
		Sleep(500);
		to_xy(a[0] + 1, a[1] + 10);
		printf("                                                                       ");
		Sleep(500);

	}
	to_xy(a[0] + 1, a[1] + 10);
	printf("                       Press any key to start...                       ");
	_getch();

}
int victory()
{
	for (int i = 0; i < WIDTH && doc_C[i] == i + 1; i++)
	{
		if (i == WIDTH - 1)
		{
			show_disk(C, locat3[0], locat3[1], c);
			show_top();
			system("color 0e");

			return 1;
		}
	}
	return 0;
}