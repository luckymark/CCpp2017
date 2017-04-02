#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define SIZE1 9
#define SIZE2 9

int map[SIZE1][SIZE2];
FILE *score;
void Choose();
void Printf_map();
void Push();

int main(void)
{
    Choose();
    Push();

    return 0;
}


void Choose()
{
    printf("请选择关卡:\n1.level 1;\n2.level 2;\n");
    FILE *fp;
    int n;
    scanf("%d",&n);
    system("cls");
    switch(n)
    {
    case 1:
        fp=fopen("map1.txt","r");
        for(int i=0;i<=SIZE1-1;i++)
        {
            for(int j=0;j<=SIZE2-1;j++)
            {
                 fscanf(fp,"%d",&map[i][j]);
            }
        }
        fclose(fp);
        break;
    case 2:
        fp=fopen("map2.txt","r");
        for(int i=0;i<=SIZE1-1;i++)
        {
            for(int j=0;j<=SIZE2-1;j++)
            {
                fscanf(fp,"%d",&map[i][j]);
            }
        }
        fclose(fp);
        break;
    }
}


void Printf_map()
{
    for(int i=0;i<=SIZE1-1;i++)
    {
        for(int j=0;j<=SIZE2-1;j++)
        {
            if(map[i][j]==0)
            {
                map[i][j]=' ';//空地
            }
            else if(map[i][j]==1)
            {
                map[i][j]='*';//墙
            }
            else if(map[i][j]==2)
            {
                map[i][j]='P';//人物
            }
            else if(map[i][j]==3)
            {
                map[i][j]='#';//箱子
            }
            else if(map[i][j]==4)
            {
                map[i][j]='D';//目的地
            }
        }
    }

        for(int i=0;i<=SIZE1-1;i++)
    {
        for(int j=0;j<=SIZE2-1;j++)
        {
            printf("%c",map[i][j]);
        }
        printf("\n");
    }
}


void Push()
{
   int step=0;
   int x=4,y=4;
   char walk;
   score=fopen("score.txt","w+");
   while(1)
   {
       Printf_map();
       printf("截止当前你共走了%d步。\n",step);
       if(map[1][4]!='D'&&map[4][7]!='D'&&map[4][1]!='D'&&map[7][4]!='D')
       {
           printf("恭喜！你已经成功完成推箱子。\n");
           fprintf(score,"你的成绩为%d步。",step);
           break;
       }
       walk=getch();
       if(walk=='w')
       {
           if(map[x-1][y]==' ')
           {
               map[x][y]=0;
               map[x-1][y]=2;
               --x;
               ++step;
           }
           else if(map[x-1][y]=='#' && map[x-2][y]!='*')
           {
               map[x][y]=0;
               map[x-1][y]=2;
               map[x-2][y]=3;
               --x;
               ++step;
           }
       }

       else if(walk=='s')
       {
           if(map[x+1][y]==' ')
           {
               map[x][y]=0;
               map[x+1][y]=2;
               ++x;
               ++step;
           }
           else if(map[x+1][y]=='#'&&map[x+2][y]!='*')
           {
               map[x][y]=0;
               map[x+1][y]=2;
               map[x+2][y]=3;
               ++x;
               ++step;
           }
       }

       else if(walk=='a')
       {
           if(map[x][y-1]==' ')
           {
               map[x][y]=0;
               map[x][y-1]=2;
               --y;
               ++step;
           }
           else if(map[x][y-1]=='#'&&map[x][y-2]!='*')
           {
               map[x][y]=0;
               map[x][y-1]=2;
               map[x][y-2]=3;
               --y;
               ++step;
           }
       }

       else if(walk=='d')
       {
           if(map[x][y+1]==' ')
           {
               map[x][y]=0;
               map[x][y+1]=2;
               ++y;
               ++step;
           }
           else if(map[x][y+1]=='#'&&map[x][y+2]!='*')
           {
               map[x][y]=0;
               map[x][y+1]=2;
               map[x][y+2]=3;
               ++y;
               ++step;
           }
       }
    system("cls");
   }
}
