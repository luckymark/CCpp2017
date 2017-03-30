#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#define N1 100
#define N2 100

int m,n,room;
char maze[N1][N2];
void Init_maze(int room);
void Create_maze(int room);
void Move(int room);

//#代表墙；
//P代表人物；

int main(void)
{
    int room;

    printf("你想输出多大的迷宫(在100*100范围内)：");
    scanf("%d",&room);
    printf("请注意：由于作者水平不够，迷宫出口请设置在第一行中间，否则要出BUG！！！！！\n请输入迷宫(只能输入0或1并且输入一个数字后回车一下或者按一下空格，1代表墙，0代表空处，输完所有数字后请回车！)\n游戏规则：w，s，a，d分别代表上，下，左，右。\n\n");

    Init_maze(room);
    Move(room);

    return 0;
}



void Init_maze(int room)
{
    for(m=0;m<room;m++)
    {
        for(n=0;n<room;n++)
        {
            scanf("%d",&maze[m][n]);
        }
    }
    maze[0][room/2]=' ';
    printf("\n");
    Create_maze(room);
}

void Create_maze(int room)
{
    for(m=0;m<room;m++)
    {
        for(n=0;n<room;n++)
        {
            if(m==room/2&&n==room/2){maze[room/2][room/2]='P';}
            else if(maze[m][n]==0){maze[m][n]=' '; }
            else if(maze[m][n]==1){maze[m][n]='#'; }
        }

    }
}

void Move(int room)
{
   char walk;
   int step=0;
   int i=room/2,j=room/2;
   while(1){
        for(int a=0;a<room;a++)
        {
            for(int b=0;b<room;b++)
            {
                printf("%c",maze[a][b]);
            }
            printf("\n");
        }


        {
            printf("\n");
            printf("目前您共走了%d步\n",step);
        }


        if(maze[0][room/2]=='P')
        {
            printf("恭喜！您已经成功到达出口！\n请按任意键退出游戏\n");
            break;
        }

        if(step>=room*room)
        {
            printf("抱歉，该迷宫无解！\n");
            break;
        }



        walk=getch();
        if('w'==walk&&maze[i-1][j]!='#'&&i!=0)
          {
              maze[i-1][j]='P';
              maze[i][j]=' ';
              step++;
              i--;
          }

          if('s'==walk&&maze[i+1][j]!='#'&&i!=room)
          {
              maze[i+1][j]='P';
              maze[i][j]=' ';
              step++;
              i++;
          }

          if('a'==walk&&maze[i][j-1]!='#'&&j!=0)
          {
              maze[i][j-1]='P';
              maze[i][j]=' ';
              step++;
              j--;
          }

          if('d'==walk&&maze[i][j+1]!='#'&&j!=room)
          {
              maze[i][j+1]='P';
              maze[i][j]=' ';
              step++;
              j++;
          }

          system("cls");

   }

}

































