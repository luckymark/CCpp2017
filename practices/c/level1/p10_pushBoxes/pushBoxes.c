#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define N 9
#define M 1000000
#define WALL 1
#define BOX 2
#define TARGET 3
int mp[N + 3][N + 3], score = 0;
int dirX[4] = {0, 1, 0, -1}, dirY[4] = {1, 0, -1, 0};
void PreMap()
{
    for (int i = 0; i < N; i++)
        mp[0][i] = 1;
    for (int i = 0; i < N; i++)
        mp[N - 1][i] = 1;
    for (int i = 0; i < N; i++)
        mp[i][0] = 1;
    for (int i = 0; i < N; i++)
        mp[i][N - 1] = 1;
}
void ReadMap(int x)
{
    FILE *f;
    switch (x)
    {
    case 1:
        f = fopen("map1.txt", "rw+");
        break;
    case 2:
        f = fopen("map2.txt", "rw+");
        break;
    case 3:
        f = fopen("map3.txt", "rw+");
        break;
    }
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            fscanf(f, "%d", &mp[i][j]);
        }
    }
    fclose(f);
}
void Init()
{
    srand(time(NULL));
    PreMap();
    printf("This is an small push boxes game\n");
    printf("Please enter a number which you want play in this level:\n");
    printf("1-easy   2-normal  3-hard\n");
    int x;
    scanf("%d", &x);
    ReadMap(x);
    system("cls");
}
void ShowMap(int x, int y, char c, char *s)
{
    system("cls");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == x && j == y)
            {
                printf("%c%c", c, c);
            }
            else
            {
                if (mp[i][j] == WALL)
                    printf("%c%c", -95, -10);
                else if (mp[i][j] == BOX)
                    printf("%c%c", -95, -11);
                else if (mp[i][j] == TARGET)
                    printf("%c%c", -95, -16);
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    printf("Your score is %d\n", score);
    printf("%s\n", s);
}
int main()
{
    int nowx = 1, nowy = 1;
    Init();
    ShowMap(nowx, nowy, '*', " ");
    while (1)
    {
        while (!kbhit())
            ;
        getch();
        char c = getch();
        int tx = nowx, ty = nowy, f = 0;
        switch (c)
        {
        case 72:
            tx -= 1, f = 1;
            break; //up
        case 75:
            ty -= 1, f = 2;
            break; //left
        case 80:
            tx += 1, f = 3;
            break; //down
        case 77:
            ty += 1, f = 4;
            break; //right
        }
        if (mp[tx][ty] == BOX)
        {
            int ttx = tx, tty = ty;
            switch (f)
            {
            case 1:
                ttx -= 1;
                break; //up
            case 2:
                tty -= 1;
                break; //left
            case 3:
                ttx += 1;
                break; //down
            case 4:
                tty += 1;
                break; //right
            }
            if (mp[ttx][tty] == WALL)
            {
                ShowMap(nowx, nowy, '*', "You can't break the wall");
            }
            else if (mp[ttx][tty] == TARGET)
            {
                mp[ttx][tty] = BOX;
                ShowMap(tx, ty, '*', "Congradulations!You win!");
                break;
            }
            else
            {
                mp[tx][ty] = 0;
                mp[ttx][tty] = BOX;
                nowx = tx;
                nowy = ty;
                ShowMap(nowx, nowy, '*', " ");
            }
        }
        else if (mp[tx][ty] == WALL)
        {
            ShowMap(nowx, nowy, '*', "You are heading a wall");
        }
        else if (mp[tx][ty] == TARGET)
        {
            nowx = tx;
            nowy = ty;
            ShowMap(tx, ty, '*', "Boxes are not on the target");
        }
        else if (mp[tx][ty] == 0)
        {
            nowx = tx;
            nowy = ty;
            ShowMap(nowx, nowy, '*', " ");
        }
        score++;
    }
    return 0;
}
