/*version 1.1
update at 2017-05-01
*/
#include<stdio.h>
#include<conio.h>
#include<windows.h>
void show_map(void);
void move(void);
void gotoxy(int x, int y);
void HideCursor(void);
void readin(void);
int **map;
int Het = 0;
int Wid = 0;
int t = 1;
FILE *fp;
int main(void)
{
	system("mode con cols=27 lines=15");
	move();
}
void show_map(void)
{
	int i, j;
	system("cls");
	printf("   Level %d\n",t);
	for (i = 0; i < Het; i++) {
		for (j = 0; j < Wid; j++) {
			if (map[i][j] == 0)printf("  ");
			else if (map[i][j] == 1)printf("��");//ǽ
			else if (map[i][j] == 2)printf("��");//��ǵ�
			else if (map[i][j] == 3)printf("��");//�յ��ϵ�����
			else if (map[i][j] == 4)printf("��");//��
			else if (map[i][j] == 5)printf("��");//��ǵ������
			else if (map[i][j] == 6)printf("��");//��
		}
		printf("\n");
	}
}
void move(void)
{
	int score = 0;
	gotoxy(16, 5);
	printf("score:%d", score);
	for (; t < 2; t++) {
		fp = fopen("map.txt", "r");
		readin();
		show_map();
		int x, y;
		for (int k = 0; k < Het; k++) {
			for (int m = 0; m < Wid; m++) {
				if (map[k][m] == 4) {
					x = k;
					y = m;
				}
			}
		}
		int flag = 0;
		while (1) {
			char ch = _getch();
			if (ch = -32) {
				switch (ch = getch()) {
				case 72:ch = 'w'; break;
				case 80:ch = 's'; break;
				case 75:ch = 'a'; break;
				case 77:ch = 'd'; break;
				}
			}
			if (ch == 'a') {
				if (map[x][y] == 4) {  //�����ɫ���ڵ�û�б�־��
					if (map[x][y - 1] == 3) {    //�����ɫ�����һ��������
						if (y > 1 && map[x][y - 2] == 0) {   //�����������ǿյ�
							map[x][y - 2] = 3;
							map[x][y - 1] = 4;
							map[x][y] = 0;
							score++;
							--y;
						}
						else if (y > 1 && map[x][y - 2] == 2) {   //������������һ����־��
							map[x][y - 2] = 5;       //�����ƶ���Ŀ���
							map[x][y - 1] = 4;
							map[x][y] = 0;
							score++;
							--y;
						}
					}
					else if (map[x][y - 1] == 5) {     //��ɫ�����һ��������
						if (y > 1 && map[x][y - 2] == 0) {    //�������������ǿյ�
							map[x][y - 2] = 3;
							map[x][y - 1] = 6;    //��ɫ�ƶ���Ŀ���
							map[x][y] = 0;
							score++;
							--y;
						}
						else if (y > 1 && map[x][y - 2] == 2) {    //�����������Ŀ���
							map[x][y - 2] = 5;
							map[x][y - 1] = 6;
							map[x][y] = 0;
							score++;
							--y;
						}
					}
					else if (map[x][y - 1] == 0) {   //�����ɫ����ǿյ�
						map[x][y - 1] = 4;
						map[x][y] = 0;
						score++;
						--y;
					}
					else if (map[x][y - 1] == 2) {
						map[x][y - 1] = 6;
						map[x][y] = 0;
						score++;
						--y;
					}
				}
				else if (map[x][y] == 6) {     //�����ɫλ�ڱ�ǵ�
					if (map[x][y - 1] == 5) {   //����������λ�ڱ�ǵ�
						if (y > 1 && map[x][y - 2] == 0) {      //�����������ǿյ�
							map[x][y - 2] = 3;
							map[x][y - 1] = 6;
							map[x][y] = 2;
							score++;
							--y;
						}
						else if (y > 1 && map[x][y - 2] == 2) {    //�����������Ǳ�ǵ�
							map[x][y - 2] = 5;
							map[x][y - 1] = 6;
							map[x][y] = 2;
							score++;
							--y;
						}
					}
					else if (map[x][y - 1] == 3) {   //�������Ǹ�������
						if (y > 1 && map[x][y - 2] == 0) {  //�����������Ǹ��յ�
							map[x][y - 2] = 3;
							map[x][y - 1] = 4;
							map[x][y] = 2;
							score++;
							--y;
						}
						else if (y > 1 && map[x][y - 2] == 2) {  //������������һ����־��
							map[x][y - 2] = 5;
							map[x][y - 1] = 4;
							map[x][y] = 2;
							score++;
							--y;
						}
					}
					else if (map[x][y - 1] == 0) {
						map[x][y - 1] = 4;
						map[x][y] = 2;
						score++;
						--y;
					}
					else if (map[x][y - 1] == 2) {
						map[x][y - 1] = 6;
						map[x][y] = 2;
						score++;
						--y;
					}
				}
			}
			if (ch == 'w') {
				if (map[x][y] == 4) {  //�����ɫ���ڵ�û�б�־��
					if (map[x - 1][y] == 3) {    //�����ɫ������һ��������
						if (x > 1 && map[x - 2][y] == 0) {   //������������ǿյ�
							map[x - 2][y] = 3;
							map[x - 1][y] = 4;
							map[x][y] = 0;
							score++;
							--x;
						}
						else if (x > 1 && map[x - 2][y] == 2) {   //�������������һ����־��
							map[x - 2][y] = 5;       //�����ƶ���Ŀ���
							map[x - 1][y] = 4;
							map[x][y] = 0;
							score++;
							--x;
						}
					}
					else if (map[x - 1][y] == 5) {     //��ɫ������һ��������
						if (x > 1 && map[x - 2][y] == 0) {    //��������������ǿյ�
							map[x - 2][y] = 3;
							map[x - 1][y] = 6;    //��ɫ�ƶ���Ŀ���
							map[x][y] = 0;
							score++;
							--x;
						}
						else if (x > 1 && map[x - 2][y] == 2) {    //������������Ŀ���
							map[x - 2][y] = 5;
							map[x - 1][y] = 6;
							map[x][y] = 0;
							score++;
							--x;
						}
					}
					else if (map[x - 1][y] == 0) {   //�����ɫ�����ǿյ�
						map[x - 1][y] = 4;
						map[x][y] = 0;
						score++;
						--x;
					}
					else if (map[x - 1][y] == 2) {
						map[x - 1][y] = 6;
						map[x][y] = 0;
						score++;
						--x;
					}
				}
				else if (map[x][y] == 6) {     //�����ɫλ�ڱ�ǵ�
					if (map[x - 1][y] == 5) {   //����������λ�ڱ�ǵ�
						if (x > 1 && map[x - 2][y] == 0) {      //�����������ǿյ�
							map[x - 2][y] = 3;
							map[x - 1][y] = 6;
							map[x][y] = 2;
							score++;
							--x;
						}
						if (x > 1 && map[x - 2][y] == 2) {    //�����������Ǳ�ǵ�
							map[x - 2][y] = 5;
							map[x - 1][y] = 6;
							map[x][y] = 2;
							score++;
							--x;
						}
					}
					else if (map[x - 1][y] == 3) {   //�������Ǹ�������
						if (x > 1 && map[x - 2][y] == 0) {  //�����������Ǹ��յ�
							map[x - 2][y] = 3;
							map[x - 1][y] = 4;
							map[x][y] = 2;
							score++;
							--x;
						}
						else if (x > 1 && map[x - 2][y] == 2) {  //������������һ����־��
							map[x - 2][y] = 5;
							map[x - 1][y] = 4;
							map[x][y] = 2;
							score++;
							--x;
						}
					}
					else if (map[x - 1][y] == 0) {
						map[x - 1][y] = 4;
						map[x][y] = 2;
						score++;
						--x;
					}
					else if (map[x - 1][y] == 2) {
						map[x - 1][y] = 6;
						map[x][y] = 2;
						score++;
						--x;
					}
				}
			}
			if (ch == 'd') {
				if (map[x][y] == 4) {  //�����ɫ���ڵ�û�б�־��
					if (map[x][y + 1] == 3) {    //�����ɫ�ұ���һ��������
						if (y < 6 && map[x][y + 2] == 0) {   //��������ұ��ǿյ�
							map[x][y + 2] = 3;
							map[x][y + 1] = 4;
							map[x][y] = 0;
							score++;
							++y;
						}
						else if (y < 6 && map[x][y + 2] == 2) {   //��������ұ���һ����־��
							map[x][y + 2] = 5;       //�����ƶ���Ŀ���
							map[x][y + 1] = 4;
							map[x][y] = 0;
							score++;
							++y;
						}
					}
					else if (map[x][y + 1] == 5) {     //��ɫ�ұ���һ��������
						if (y < 6 && map[x][y + 2] == 0) {    //����������ұ��ǿյ�
							map[x][y + 2] = 3;
							map[x][y + 1] = 6;    //��ɫ�ƶ���Ŀ���
							map[x][y] = 0;
							score++;
							++y;
						}
						else if (y < 6 && map[x][y + 2] == 2) {    //�������ұ���Ŀ���
							map[x][y + 2] = 5;
							map[x][y + 1] = 6;
							map[x][y] = 0;
							score++;
							++y;
						}
					}
					else if (map[x][y + 1] == 0) {   //�����ɫ�ұ��ǿյ�
						map[x][y + 1] = 4;
						map[x][y] = 0;
						score++;
						++y;
					}
					else if (map[x][y + 1] == 2) {
						map[x][y + 1] = 6;
						map[x][y] = 0;
						score++;
						++y;
					}
				}
				else if (map[x][y] == 6) {     //�����ɫλ�ڱ�ǵ�
					if (map[x][y + 1] == 5) {   //����������λ�ڱ�ǵ�
						if (y < 6 && map[x][y + 2] == 0) {      //�����������ǿյ�
							map[x][y + 2] = 3;
							map[x][y + 1] = 6;
							map[x][y] = 2;
							score++;
							++y;
						}
						else if (y < 6 && map[x][y + 2] == 2) {    //�����������Ǳ�ǵ�
							map[x][y + 2] = 5;
							map[x][y + 1] = 6;
							map[x][y] = 2;
							score++;
							++y;
						}
					}
					else if (map[x][y + 1] == 3) {   //�������Ǹ�������
						if (y < 6 && map[x][y + 2] == 0) {  //�����������Ǹ��յ�
							map[x][y + 2] = 3;
							map[x][y + 1] = 4;
							map[x][y] = 2;
							score++;
							++y;
						}
						else if (y < 6 && map[x][y + 2] == 2) {  //������������һ����־��
							map[x][y + 2] = 5;
							map[x][y + 1] = 4;
							map[x][y] = 2;
							score++;
							++y;
						}
					}
					else if (map[x][y + 1] == 0) {
						map[x][y + 1] = 4;
						map[x][y] = 2;
						++y;
						score++;

					}
					else if (map[x][y + 1] == 2) {
						map[x][y + 1] = 6;
						map[x][y] = 2;
						++y;
						score++;
					}
				}
				
			}
			if (ch == 's') {
				if (map[x][y] == 4) {  //�����ɫ���ڵ�û�б�־��
					if (map[x + 1][y] == 3) {    //�����ɫ������һ��������
						if (x < 5 && map[x + 2][y] == 0) {   //������������ǿյ�
							map[x + 2][y] = 3;
							map[x + 1][y] = 4;
							map[x][y] = 0;
							score++;
							++x;
						}
						else if (x < 5 && map[x + 2][y] == 2) {   //�������������һ����־��
							map[x + 2][y] = 5;       //�����ƶ���Ŀ���
							map[x + 1][y] = 4;
							map[x][y] = 0;
							score++;
							++x;
						}
					}
					else if (map[x + 1][y] == 5) {     //��ɫ������һ��������
						if (x < 5 && map[x + 2][y] == 0) {    //��������������ǿյ�
							map[x + 2][y] = 3;
							map[x + 1][y] = 6;    //��ɫ�ƶ���Ŀ���
							map[x][y] = 0;
							score++;
							++x;
						}
						else if (x < 5 && map[x + 2][y] == 2) {    //������������Ŀ���
							map[x + 2][y] = 5;
							map[x + 1][y] = 6;
							map[x][y] = 0;
							score++;
							++x;
						}
					}
					else if (map[x + 1][y] == 0) {   //�����ɫ�����ǿյ�
						map[x + 1][y] = 4;
						map[x][y] = 0;
						score++;
						++x;
					}
					else if (map[x + 1][y] == 2) {
						map[x + 1][y] = 6;
						map[x][y] = 0;
						score++;
						++x;
					}
				}
				else if (map[x][y] == 6) {     //�����ɫλ�ڱ�ǵ�
					if (map[x + 1][y] == 5) {   //����������λ�ڱ�ǵ�
						if (x < 5 && map[x + 2][y] == 0) {      //�����������ǿյ�
							map[x + 2][y] = 3;
							map[x + 1][y] = 6;
							map[x][y] = 2;
							score++;
							++x;
						}
						else if (x < 5 && map[x + 2][y] == 2) {    //�����������Ǳ�ǵ�
							map[x + 2][y] = 5;
							map[x + 1][y] = 6;
							map[x][y] = 2;
							score++;
							++x;
						}
					}
					else if (map[x + 1][y] == 3) {   //�������Ǹ�������
						if (x < 5 && map[x + 2][y] == 0) {  //�����������Ǹ��յ�
							map[x + 2][y] = 3;
							map[x + 1][y] = 4;
							map[x][y] = 2;
							score++;
							++x;
						}
						else if (x < 5 && map[x + 2][y] == 2) {  //������������һ����־��
							map[x + 2][y] = 5;
							map[x + 1][y] = 4;
							map[x][y] = 2;
							score++;
							++x;
						}
					}
					else if (map[x + 1][y] == 0) {
						map[x + 1][y] = 4;
						map[x][y] = 2;
						score++;
						++x;
					}
					else if (map[x + 1][y] == 2) {
						map[x + 1][y] = 6;
						map[x][y] = 2;
						score++;
						++x;
					}
				}
			}
			system("cls");
			show_map();
			flag = 0;
			for (int k = 0; k < Het; k++) {
				for (int m = 0; m < Wid; m++) {
					if (map[k][m] == 2) {
						flag = 1;
					}
				}
			}
			if (flag == 0) {
				system("cls");
				printf("You win!");
				break;
			}
			gotoxy(16, 5);
			printf("score:%d",score);
		}
		free(map);
	}
}
void gotoxy(int x, int y)//�ƶ���굽���꣨x,y) 
{
	HANDLE hwnd;    //����һ����Ϊhwnd�ľ������ 
	COORD coord;    //struct���Ͷ��� 
	coord.X = x;      //�Խṹ���б�����ֵ����Ժ����� 
	coord.Y = y;      //��Կ���̨������ 
	hwnd = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ��ǰ����̨���ھ�� 
	SetConsoleCursorPosition(hwnd, coord);//����ƶ����ô��ڵ����λ�ã�x,y) 
	HideCursor();
}
void HideCursor(void)//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void readin(void) {
	char temp[1000] = { 0 };
	while (fgets(temp, 1000, fp))Het++;
	Wid = 1;
	fseek(fp, 0L, SEEK_SET);
	for (int i = 1; temp[i] == ','; i += 2)Wid++;
	map = (int **)malloc(sizeof(int *)*Het);
	for (int i = 0; i < Het; i++) {
		map[i] = (int *)malloc(sizeof(int)*Wid);
	}
	for (int i = 0; i < Het; i++) {
		for (int j = 0; j < Wid; j++) {
			fscanf(fp, "%d,", &map[i][j]);
		}
	}
}