#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define box_num 219
COORD man;
HANDLE handle_out;
bool bo_win = 0;
int lev;
int ans = 0;
void go(int x, int y);

const int dy[5] = {0, 0, 0, -1, 1};
const int dx[5] = {0, -1, 1, 0, 0};
int aim[100][2];
int tot_aim = 0;
COORD   box[2];


int map[10][30];

void getmap(int level) {
    char s[100];
    char sread[100] = "maze ";
    const char sux[4] = ".in";
    sprintf(sread + 4, "%d", level);
    for (int i = 5; i <= 8; i++)
        {
            sread[i] = sux[i - 5];
        }

    freopen(sread, "r", stdin);
    for (int i = 0; i < 10; i++)
    {
        gets(s);
        for (int j = 0; j < 20; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }
}


void mainpre() {
    CONSOLE_CURSOR_INFO cci;
    handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    cci.bVisible =  false;
    SetConsoleCursorInfo(handle_out, &cci);
}

void prepare() {
    go(20, 0);
    printf("level %d.\n", lev);
    go(0, 0);
    getmap(lev);
    box[0].X = 2;     box[0].Y = 4;
    box[1].X = 15;    box[1].Y = 4;
    tot_aim = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
            switch (map[i][j])
            {
            case 0:
            {
                printf("#");
                break;
            }
            case 1:
            {
                printf(" ");
                break;
            }
            case 2:
            {
                printf("%c", box_num);
                break;
            }
            case 3:
            {
                aim[++tot_aim][0] = i; aim[tot_aim][1] = j;
                printf("X");
                break;
            }
            }
        puts("");
    }
    go(1, 1); printf("%c", 2);
}

void go(int x, int y) {
    COORD pos;
    pos.X = y;
    pos.Y = x;
    SetConsoleCursorPosition(handle_out, pos);
}

int getkey() {
    if (GetKeyState(VK_UP) < 0)
    {
        return 1;
    }
    if (GetKeyState(VK_DOWN) < 0)
    {
        return 2;
    }
    if (GetKeyState(VK_LEFT) < 0)
    {
        return 3;
    }
    if (GetKeyState(VK_RIGHT) < 0)
    {
        return 4;
    }
    return 0;
}


bool check_win() {
    for (int i = 1; i <= tot_aim; i++)
    {
        if (map[aim[i][0]][aim[i][1]] != 2)
        {
            return 0;
        }
    }
    return 1;
}


int nowans = 0;
void move() {
    int tmp = getkey();
    bool bo_go;
    if (tmp)
    {
        int can = map[man.X + dx[tmp]][man.Y + dy[tmp]];
        if (!can)
        {
            return;
        }
        bo_go = 0;
        if (can == 2)
        {
            int front = map[man.X + dx[tmp] * 2][man.Y + dy[tmp] * 2];
            if ((front == 0) || (front == 2))
            {
                return;
            }
            bo_go = 1;
        }
        go(man.X, man.Y);
        putchar(' ');
        man.X += dx[tmp]; man.Y += dy[tmp];
        go(man.X, man.Y);
        printf("%c", 2);
        if (bo_go)
        {
            go(man.X + dx[tmp], man.Y + dy[tmp]);
            printf("%c", box_num);
            map[man.X + dx[tmp]][man.Y + dy[tmp]] = 2;
            map[man.X][man.Y] = 1;
        }
        for (int i = 1; i <= tot_aim; i++)
        {
            if (map[aim[i][0]][aim[i][1]] != 2)
            {
                if ((aim[i][0] != man.X) || (aim[i][1] != man.Y))
                {
                    go(aim[i][0], aim[i][1]);
                    printf("X");
                }
            }
        }
        ans++;
        if (check_win())
        {
            bo_win = 1;
            return;
        }
    }
}


int main() {
    mainpre();
    for (lev = 1; lev <= 2; lev++)
    {
        bo_win = 0;
        prepare();
        man.X = 1;
        man.Y = 1;
        go(1, 1);
        while (1)
        {
            move();
            if (bo_win)
            {
                break;
            }
            Sleep(100);
        }
    }
    go(20, 0);
    puts("You Win!!!!!!");
    printf("You have uesed %d steps\n", ans);
}