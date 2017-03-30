#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>
#include <Windows.h>
#define N1 100
#define N2 100

int m,n,room;
char maze[N1][N2];
void Init_maze(int room);
void Create_maze(int room);
void Move(int room);

//#����ǽ��
//P�������

int main(void)
{
    int room;

    printf("������������Թ�(��100*100��Χ��)��");
    scanf("%d",&room);
    printf("��ע�⣺��������ˮƽ�������Թ������������ڵ�һ���м䣬����Ҫ��BUG����������\n�������Թ�(ֻ������0��1��������һ�����ֺ�س�һ�»��߰�һ�¿ո�1����ǽ��0����մ��������������ֺ���س���)\n��Ϸ����w��s��a��d�ֱ�����ϣ��£����ҡ�\n\n");

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
            printf("Ŀǰ��������%d��\n",step);
        }


        if(maze[0][room/2]=='P')
        {
            printf("��ϲ�����Ѿ��ɹ�������ڣ�\n�밴������˳���Ϸ\n");
            break;
        }

        if(step>=room*room)
        {
            printf("��Ǹ�����Թ��޽⣡\n");
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

































