#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define size 10
int position[size][size];
void input_map(int nn);
void print_map(int nn);
void move_position(int nn);
void main()
{
	int n;
	printf("请输入地图大小:\n");
	scanf("%d", &n);
	input_map(n);
	move_position(n);
	system("pause");
}

void input_map(int nn)
{
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			scanf("%d", &position[i][j]);
		}
	}
}

void print_map(int nn)
{
	for (int i = 0; i < nn; i++) {
		for (int j = 0; j < nn; j++) {
			if (position[i][j] == 0) {
				printf(" ");
			}
			else if (position[i][j] == 1) {
				printf("#");
			}
			else if (position[i][j] == 9) {
				printf("P");
			}
		}
		printf("\n");
	}
}

void move_position(int nn)
{
	int x, y;
	x = y = 0;
	position[x][y] = 9;
	print_map(nn);
	char walk;
	while (1) {
		walk = _getch();
		if (walk == 'w'&&(position[x-1][y]!=1)&&(x>0)) {
			position[x-1][y] = 9;
			position[x][y] = 0;
			x--;
		}
		if (walk == 's' && (position[x+1][y] != 1) && (x<nn-1)) {
			position[x+1][y] = 9;
			position[x][y] = 0;
			x++;
		}
		if (walk == 'a'&&(position[x][y-1]!=1)&&(y>0)) {
			position[x][y-1] = 9;
			position[x][y] = 0;
			y--;
		}
		if (walk == 'd'&&(position[x][y+1]!=1)&&(y<nn-1)) {
			position[x][y+1] = 9;
			position[x][y] = 0;
			y++;
		}
		if (x == nn - 1 && y == nn - 1) {
			printf("YOU WIN!\n");
			break;
		}
		system("cls");
		print_map(nn);
	}
}
