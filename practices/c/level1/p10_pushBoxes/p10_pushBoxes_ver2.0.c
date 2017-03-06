#include <stdbool.h> 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define SIZE 10             //地图大小 
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
const int WALL_ = 0;
const int AIR_ = 1;
const int BOX_ = 3;
const int AIMSPACE_ = 2;
int map[SIZE + 1][SIZE + 1] = { 0 };      //记录地图的数组  0代表墙  1表示空气 3代表箱子 
int mapmap[SIZE + 1][SIZE + 1] = { 0 };		//记录地图的数组  0代表墙  1表示空气  2代表箱子目标位置 
char WALL[] = "■";
char AIR[] = "  ";
char PLAYER[] = "※";
char BOX[] = "●";
char AIMSPACE[] = "○";
void printGame(int x, int y,int score);
void gameOver(int *score,int stage, FILE *fp);
void loadMap(int *x, int *y, int *boxNums, int *score, FILE *fp);
void move(char dir, int *x, int *y, int *boxReached, int *score);

void clean(int *score, int *hisScore,int *x,int *y)
{
	
}

int main()
{
	int stage=1;  //当前关卡 
	
	char str[3];  
	int score;  
	int x , y ;   //玩家坐标  
	char dir;      //用于储存输入 
	int boxNums;   //当前关卡的箱子数目 
	int boxReached;  //当前以推倒的箱子 
	FILE *fp;       //地图文件 
	
	while(true)
	{
		boxReached=0;
		itoa(stage,str,10);
		fp = fopen(str, "a+");
		loadMap(&x, &y, &boxNums, &score, fp);  //加载地图 
		printGame(x, y,score);                   //打印游戏 
		
		while ((dir = getch()) != 'q')         
		{
			dir = getch();	
						 
			move(dir, &x, &y,&boxReached, &score);	//移动  	
			printGame(x, y,score);                 //移动后刷新 游戏 
			if (boxReached == boxNums)            //判断游戏是否结束 
			{
				break;
			}
		}	
		gameOver(&score, stage, fp);    //游戏结束 
		stage++;						//下一关 
		
		for(int i=1;i<=SIZE;i++)       //清空地图数据 
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

void printGame(int x, int y,int score)   //打印游戏界面的函数 
{
	system("cls");
	for (int i = 1; i<SIZE + 1; i++)
	{
		for (int j = 1; j<SIZE + 1; j++)
		{
			if (mapmap[i][j] == WALL_)
				printf("%s", WALL);
			else if (map[i][j] == BOX_)   //箱子位置存储在map[][]里面 
				printf("%s", BOX);
			else if (i == y && j == x)  
				printf("%s", PLAYER);
			else if (mapmap[i][j] == AIMSPACE_)   //箱子目标位置存储在mapmap[][]里 
				printf("%s", AIMSPACE);
			else if (mapmap[i][j]= AIR_)     
				printf("%s", AIR);
		}
		printf("\n");
	}
	printf("得分:%d\n",score);
	
}

void gameOver(int *score,int statge ,FILE *fp)   //关卡结束时执行该函数 
{
	system("cls");
	printf("YOU WIN!\nSCORE:%d\n",*score);
	Sleep(1000);
	if (fp != NULL)
	{
		fprintf(fp,"%d ",*score);   //写入得分 
	}
	
	if(statge==3)
		exit(1);    //如果是第3关  则直接终止游戏 
	
}

void loadMap(int *x, int *y, int *boxNums , int *score, FILE *fp)   //加载地图 
{
	
	char str[10];
	char s[2];
	int x0, y0;
	
	if (fp != NULL)
	{
		fscanf(fp, "XY:(%d,%d)\n", x, y);   //读取玩家初始位置 
		fscanf(fp, "MAXSCORE:%d\n", score); //读取最大分数  
		fscanf(fp, "BOXNUMS:%d\n", boxNums); //读取箱子总数          
		for (int i = 1; i <= 3; i++)
		{
			fscanf(fp, "%s\n", &str);		
			fscanf(fp, "(%d,%d)", &x0, &y0);  //先读取一组坐标 
			while (x0 != 0 || y0 != 0)
			{
				map[y0][x0] = i;         //录入map[][]  mapmap[][] 
				mapmap[y0][x0] = i;
				fscanf(fp, "(%d,%d)", &x0, &y0);
			}
		}

	}
	
	for(int i=1;i<=SIZE+1;i++)               //将map[][]中的目标箱子位置去掉 
	{
		for(int j=1;j<=SIZE+1;j++)
		{
			mapmap[i][j]= mapmap[i][j]==3 ? 1:mapmap[i][j]; 
		}
	}
	for(int i=1;i<=SIZE+1;i++)          //将mapmap[][]中的箱子位置去掉 
	{
		for(int j=1;j<=SIZE+1;j++)
		{
			map[i][j]= map[i][j]==2 ? 1:map[i][j]; 
		}
	}
}

void move(char dir, int *x0, int *y0, int *boxReached, int *score)   //移动函数 
{
	int x = *x0;
	int y = *y0;
	switch(dir)
	{
		case 224:
			break;
		case RIGHT:
			if(map[y][x+1] == AIR_) //普通移动 
			{ 
				*x0=x+1; 
				*score=*score-1;
			} 
			else if(map[y][x+1] == BOX_ && map[y][x+2] == AIR_)    //推着箱子走 
			{
				if(mapmap[y][x+1] == AIMSPACE_)    //如果箱子本来就在AIMSPACE  那么到达箱子数目减一 
					*boxReached=*boxReached-1;
				if(mapmap[y][x+2] == AIMSPACE_)
					*boxReached=*boxReached+1;    //如果箱子到达AIMSPACE  那么到达箱子数目加一 
				map[y][x+1]=AIR_;
				map[y][x+2]=BOX_;
				*x0=x+1;	
				*score=*score-1;	  //没移动一步 得分减一		
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
