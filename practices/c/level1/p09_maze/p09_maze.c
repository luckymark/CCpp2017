#include <stdio.h>
#include <string.h>
#include <curses.h>
#define N 8

// *表示迷宫边框
// &表示出口
// Y表示人物

int check(int x,int y);
void mapPut();
void getDestination();
void mazeMove(int k);
void init();

char mazeMap[N][N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int x,y;
int destinationX,destinationY;
int isGet = 0;

int main() {
    init();

// down 258
// up 259
// left 260
// right 261

    while (!isGet) {
        int k = getch() - 258;
        mazeMove(k);
    }

    getch();
    endwin();
    return 0;
}

int check(int x,int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return 0;
    if (x == destinationX && y == destinationY) return 2;
    if (mazeMap[x][y] == '*') return 0;
    return 1;
}

void mapPut() {
    clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            move(i,j);
            addch(mazeMap[i][j]);
        }
    }
    refresh();
}

void getDestination() {
    clear();
    char ch[] = {"Congratulations!!!"};
    addstr(ch);
    refresh();
    isGet = 1;
}

void mazeMove(int k) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    int flag = check(xx,yy);
    if (flag == 2) {
        getDestination();
        return;
    }
    if (flag == 0) return;
    mazeMap[x][y] = ' ';
    x += dx[k];
    y += dy[k];
    mazeMap[x][y] = 'Y';
    mapPut();
}

void init() {
    FILE *file;
    initscr();
    file = fopen("mazeMap","r");
    for (int i = 0; i < N; i++) {
        int end = 0;
        for (int j = 0; j < N; j++) {
            mazeMap[i][j] = getc(file);
            if (mazeMap[i][j] == '\n') {
                end = 1;
                break;
            }
        }
        if (end) {
            int x = N - strlen(mazeMap[i]) + 1;
            for (int j = N - x - 1; j >= 0; j--) {
                mazeMap[i][j + x] = mazeMap[i][j];
            }
            for (int j = 0; j < x; j++) {
                mazeMap[i][j] = ' ';
            }
        }
        else {
            fscanf(file,"\n");
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mazeMap[i][j] == 'Y') {
                x = i;
                y = j;
            }
            if (mazeMap[i][j] == '&') {
                destinationX = i;
                destinationY = j;
            }
        }
    }
    
    
    fclose(file);
    keypad(stdscr,true);
    noecho();
    
    mapPut();
}
