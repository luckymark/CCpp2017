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
    printf("��ѡ��ؿ�:\n1.level 1;\n2.level 2;\n");
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
                map[i][j]=' ';//�յ�
            }
            else if(map[i][j]==1)
            {
                map[i][j]='*';//ǽ
            }
            else if(map[i][j]==2)
            {
                map[i][j]='P';//����
            }
            else if(map[i][j]==3)
            {
                map[i][j]='#';//����
            }
            else if(map[i][j]==4)
            {
                map[i][j]='D';//Ŀ�ĵ�
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
       printf("��ֹ��ǰ�㹲����%d����\n",step);
       if(map[1][4]!='D'&&map[4][7]!='D'&&map[4][1]!='D'&&map[7][4]!='D')
       {
           printf("��ϲ�����Ѿ��ɹ���������ӡ�\n");
           fprintf(score,"��ĳɼ�Ϊ%d����",step);
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
