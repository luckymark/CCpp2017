#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define N 19
#define M 1000000
int maze[N + 3][N + 3];
int fa[M], rk[M], cnt2, cnt, dirX[4] = {0, 1, 0, -1}, dirY[4] = {1, 0, -1, 0};
struct Pos
{
    int x, y;
} edge[N * N], node[N * N], s, t;
int Find(int x) { return x == fa[x] ? fa[x] : fa[x] = Find(fa[x]); }
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    if (rk[x] >= rk[y])
        fa[y] = x, rk[x] += rk[y];
    else
        fa[x] = y, rk[y] += rk[x];
}
void Init()
{
    //SetConsoleOutputCP(437);
    srand(time(NULL));
    for (int i = 0; i <= M; i++)
        fa[i] = i, rk[i] = 1;
    printf("This is an small maze game\n");
    printf("Please enter any key to continue");
    char t = getchar();
    system("cls");
}
void PreMaze()
{
    for (int i = 0; i < N; i++)
        maze[0][i] = 1;
    for (int i = 0; i < N; i++)
        maze[N - 1][i] = 1;
    for (int i = 0; i < N; i++)
        maze[i][0] = 1;
    for (int i = 0; i < N; i++)
        maze[i][N - 1] = 1;
    cnt = 0;
    cnt2 = 1;
    for (int i = 1; i < N - 1; i++)
    {
        for (int j = 1; j < N - 1; j++)
        {
            if ((i % 2 == 0 && j % 2) || (j % 2 == 0))
                maze[i][j] = 1;
            else
            {
                node[cnt2].x = i;
                node[cnt2++].y = j;
            }
            if ((j % 2 && i % 2 == 0) || (j % 2 == 0 && i % 2))
                edge[cnt].x = i, edge[cnt++].y = j;
        }
    }
}
int GetRandArc()
{
    return rand() % cnt;
}
int FindPos(Pos cur)
{
    for (int i = 1; i <= cnt2; i++)
    {
        if (node[i].x == cur.x && node[i].y == cur.y)
            return i;
    }
}
int JudgeCorner(Pos cur)
{
    return cur.x >= 1 && cur.y >= 1 && cur.x < N - 1 && cur.y < N - 1;
}
void ShowMaze(int x, int y, char c, char *s)
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
                if (maze[i][j])
                    printf("%c%c", 0xa8, 0x80);
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    printf("%s\n", s);
}
void GenerateRandomMaze()
{
    s.x = 1;
    s.y = 1;
    t.x = N - 2;
    t.y = N - 2;
    node[1] = s;
    node[cnt2 - 1] = t;
    PreMaze();
    while (Find(1) != Find(cnt2 - 1))
    {
        int temp = GetRandArc();
        if (edge[temp].x % 2 == 0)
        {
            Pos up;
            up.x = edge[temp].x + dirX[3];
            up.y = edge[temp].y + dirY[3];
            Pos down;
            down.x = edge[temp].x + dirX[1];
            down.y = edge[temp].y + dirY[1];
            if (JudgeCorner(up) && JudgeCorner(down))
            {
                int u = FindPos(up), d = FindPos(down);
                if (Find(u) != Find(d))
                {
                    Union(u, d);
                    maze[edge[temp].x][edge[temp].y] = 0;
                }
            }
        }
        else
        {
            Pos left;
            left.x = edge[temp].x + dirX[2];
            left.y = edge[temp].y + dirY[2];
            Pos right;
            right.x = edge[temp].x + dirX[0];
            right.y = edge[temp].y + dirY[0];

            if (JudgeCorner(left) && JudgeCorner(right))
            {
                int l = FindPos(left), r = FindPos(right);
                if (Find(l) != Find(r))
                {
                    Union(l, r);
                    maze[edge[temp].x][edge[temp].y] = 0;
                }
            }
        }
        ShowMaze(1, 1, ' ', "Generating Maze...");
    }
}
int main()
{
    int nowx = 1, nowy = 1;
    Init();
    GenerateRandomMaze();
    ShowMaze(nowx, nowy, '*', " ");
    while (1)
    {
        while (!kbhit())
            ;
        getch();
        char c = getch();
        int tx = nowx, ty = nowy;
        switch (c)
        {
        case 72:
            tx -= 1;
            break;
        case 75:
            ty -= 1;
            break;
        case 80:
            tx += 1;
            break;
        case 77:
            ty += 1;
            break;
        }
        if (maze[tx][ty])
        {
            ShowMaze(nowx, nowy, '*', "You can't head to a wall");
            continue;
        }
        else
        {
            nowx = tx;
            nowy = ty;
            ShowMaze(nowx, nowy, '*', "");
        }
        if (nowx == t.x && nowy == t.y)
        {
            ShowMaze(nowx, nowy, '*', "Congradulations!You win the game and you will get a poi!");
            break;
        }
    }
    return 0;
}
