#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define SIZE 10             //��ͼ��С 
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
const int WALL_ = 0;
const int AIR_ = 1;
const int BOX_ = 3;
const int AIMSPACE_ = 2;
int map[SIZE + 1][SIZE + 1] = { 0 };      //��¼��ͼ������  0����ǽ  1��ʾ���� 3�������� 
int mapmap[SIZE + 1][SIZE + 1] = { 0 };		//��¼��ͼ������  0����ǽ  1��ʾ����  2��������Ŀ��λ�� 
char WALL[] = "��";
char AIR[] = "  ";
char PLAYER[] = "��";
char BOX[] = "��";
char AIMSPACE[] = "��";
void printGame(int x, int y,int score);
void gameOver(int *score,int stage, FILE *fp);
void loadMap(int *x, int *y, int *boxNums, int *score, FILE *fp);
void move(char dir, int *x, int *y, int *boxReached, int *score);

void clean(int *score, int *hisScore,int *x,int *y)
{
	
}

int main()
{
	int stage=1;  //��ǰ�ؿ� 
	
	char str[3];  
	int score;  
	int x , y ;   //�������  
	char dir;      //���ڴ������� 
	int boxNums;   //��ǰ�ؿ���������Ŀ 
	int boxReached;  //��ǰ���Ƶ������� 
	FILE *fp;       //��ͼ�ļ� 
	
	while(true)
	{
		boxReached=0;
		itoa(stage,str,10);
		fp = fopen(str, "a+");
		loadMap(&x, &y, &boxNums, &score, fp);  //���ص�ͼ 
		printGame(x, y,score);                   //��ӡ��Ϸ 
		
		while ((dir = getch()) != 'q')         
		{
			dir = getch();	
						 
			move(dir, &x, &y,&boxReached, &score);	//�ƶ�  	
			printGame(x, y,score);                 //�ƶ���ˢ�� ��Ϸ 
			if (boxReached == boxNums)            //�ж���Ϸ�Ƿ���� 
			{
				break;
			}
		}	
		gameOver(&score, stage, fp);    //��Ϸ���� 
		stage++;						//��һ�� 
		
		for(int i=1;i<=SIZE;i++)       //��յ�ͼ���� 
		{
			for(int j=1;j<=SIZE;j++)
			{
				mapmap[i][j]=0;
				map[i][j]=0;
			}
		}
		fclose(fp);
	}
	return 0;

}

void printGame(int x, int y,int score)   //��ӡ��Ϸ����ĺ��� 
{
	system("cls");
	for (int i = 1; i<SIZE + 1; i++)
	{
		for (int j = 1; j<SIZE + 1; j++)
		{
			if (mapmap[i][j] == WALL_)
				printf("%s", WALL);
			else if (map[i][j] == BOX_)   //����λ�ô洢��map[][]���� 
				printf("%s", BOX);
			else if (i == y && j == x)  
				printf("%s", PLAYER);
			else if (mapmap[i][j] == AIMSPACE_)   //����Ŀ��λ�ô洢��mapmap[][]�� 
				printf("%s", AIMSPACE);
			else if (mapmap[i][j]= AIR_)     
				printf("%s", AIR);
		}
		printf("\n");
	}
	printf("�÷�:%d\n",score);
	
}

void gameOver(int *score,int statge ,FILE *fp)   //�ؿ�����ʱִ�иú��� 
{
	system("cls");
	printf("YOU WIN!\nSCORE:%d\n",*score);
	Sleep(1000);
	if (fp != NULL)
	{
		fprintf(fp,"%d ",*score);   //д��÷� 
	}
	
	if(statge==3)
		exit(1);    //����ǵ�3��  ��ֱ����ֹ��Ϸ 
	
}

void loadMap(int *x, int *y, int *boxNums , int *score, FILE *fp)   //���ص�ͼ 
{
	
	char str[10];
	char s[2];
	int x0, y0;
	
	if (fp != NULL)
	{
		fscanf(fp, "XY:(%d,%d)\n", x, y);   //��ȡ��ҳ�ʼλ�� 
		fscanf(fp, "MAXSCORE:%d\n", score); //��ȡ������  
		fscanf(fp, "BOXNUMS:%d\n", boxNums); //��ȡ��������          
		for (int i = 1; i <= 3; i++)
		{
			fscanf(fp, "%s\n", &str);		
			fscanf(fp, "(%d,%d)", &x0, &y0);  //�ȶ�ȡһ������ 
			while (x0 != 0 || y0 != 0)
			{
				map[y0][x0] = i;         //¼��map[][]  mapmap[][] 
				mapmap[y0][x0] = i;
				fscanf(fp, "(%d,%d)", &x0, &y0);
			}
		}

	}
	
	for(int i=1;i<=SIZE+1;i++)               //��map[][]�е�Ŀ������λ��ȥ�� 
	{
		for(int j=1;j<=SIZE+1;j++)
		{
			mapmap[i][j]= mapmap[i][j]==3 ? 1:mapmap[i][j]; 
		}
	}
	for(int i=1;i<=SIZE+1;i++)          //��mapmap[][]�е�����λ��ȥ�� 
	{
		for(int j=1;j<=SIZE+1;j++)
		{
			map[i][j]= map[i][j]==2 ? 1:map[i][j]; 
		}
	}
}

void move(char dir, int *x0, int *y0, int *boxReached, int *score)   //�ƶ����� 
{
	int x = *x0;
	int y = *y0;
	switch(dir)
	{
		case 224:
			break;
		case RIGHT:
			if(map[y][x+1] == AIR_) //��ͨ�ƶ� 
			{ 
				*x0=x+1; 
				*score=*score-1;
			} 
			else if(map[y][x+1] == BOX_ && map[y][x+2] == AIR_)    //���������� 
			{
				if(mapmap[y][x+1] == AIMSPACE_)    //������ӱ�������AIMSPACE  ��ô����������Ŀ��һ 
					*boxReached=*boxReached-1;
				if(mapmap[y][x+2] == AIMSPACE_)
					*boxReached=*boxReached+1;    //������ӵ���AIMSPACE  ��ô����������Ŀ��һ 
				map[y][x+1]=AIR_;
				map[y][x+2]=BOX_;
				*x0=x+1;	
				*score=*score-1;	  //û�ƶ�һ�� �÷ּ�һ		
			}
			break;
		case DOWN:
			if(map[y+1][x] == AIR_)
			{ 
				*y0=y+1;
				*score=*score-1;
			}
			else if(map[y+1][x] == BOX_ && map[y+2][x] == AIR_)
			{
				if(mapmap[y+1][x] == AIMSPACE_)
					*boxReached=*boxReached-1;
				if(mapmap[y+2][x] == AIMSPACE_)
					*boxReached=*boxReached+1;
				map[y+1][x]=AIR_;
				map[y+2][x]=BOX_;
				*y0=y+1;	
				*score=*score-1;				
			}
			break;
		case LEFT:
			if(map[y][x-1] == AIR_) 
			{ 
				*x0=x-1;
				*score=*score-1;
			} 
			else if(map[y][x-1] == BOX_ && map[y][x-2] == AIR_)
			{
				if(mapmap[y][x-1] == AIMSPACE_)
					*boxReached=*boxReached-1;
				if(mapmap[y][x-2] == AIMSPACE_)
					*boxReached=*boxReached+1;
				map[y][x-1]=AIR_;
				map[y][x-2]=BOX_;
				*x0=x-1;
				*score=*score-1;				
			}
			break;
		case UP:
			if(map[y-1][x] == AIR_)
			{ 
			
				*y0=y-1;
				*score=*score-1;
			} 
			else if(map[y-1][x] == BOX_ && map[y-2][x] == AIR_)
			{
				if(mapmap[y-1][x] == AIMSPACE_)
					*boxReached=*boxReached-1;
				if(mapmap[y-2][x] == AIMSPACE_)
					*boxReached=*boxReached+1;
				map[y-1][x]=AIR_;
				map[y-2][x]=BOX_;
				*y0=y-1;
				*score=*score-1;					
			}
			break;
		default:
			break;							
	}		
}
