#include <stdio.h>
#include <string.h>
#include <curses.h>
#define N 8
#define M 20

// *表示地图边框
// Y表示人物
// #表示箱子
// O表示目标位置
// @表示箱子到达目标位置

void mapPut();
void init();
int check(int x,int y);
void xyMove(int xx,int yy);
int checkBox(int l,int k);
void boxMove(int k);
void restart();

struct box {
	int x,y;
	int getDestination;
}boxes[M];
struct destination {
	int x,y;
	int covered;
}des[M];

char boxMap[N][N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int x,y;
int numBox = 0;
int numDes = 0;
int step = 0;
int isFinish = 0;

int main() {
	init();

	while (!isFinish) {
		int k = getch() - 258;
		if (k == -231) {
			restart();
		}
		boxMove(k);
	}
	clear();
	printw("Congratulation! You use %d steps!",step);
	refresh();
	getch();
	endwin();
	return 0;
}

void mapPut() {
    clear();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            move(i,j);
            addch(boxMap[i][j]);
        }
    }
    move(x,y);
    addch('Y');
    for (int i = 0; i < numBox; i++) {
        move(boxes[i].x,boxes[i].y);
        addch(boxes[i].getDestination?'@':'#');
    }
    isFinish = 1;
    for (int i = 0; i < numDes; i++) {
        move(des[i].x,des[i].y);
        if (!des[i].covered) {
            addch('O');
            isFinish = 0;
        }
    }
    move(N,0);
    printw("Step = %d",step);
    refresh();
}

void init() {
    initscr();
    FILE *file;
    file = fopen("boxMap","r");
    for (int i = 0; i < N; i++) {
        int end = 0;
        for (int j = 0; j < N; j++) {
            boxMap[i][j] = getc(file);
            if (boxMap[i][j] == '\n') {
                end = 1;
                break;
            }
        }
        if (end) {
            int x = N - strlen(boxMap[i]) + 1;
            for (int j = N - x - 1; j >= 0; j--) {
                boxMap[i][j + x] = boxMap[i][j];
            }
            for (int j = 0; j < x; j++) {
                boxMap[i][j] = ' ';
            }
        }
        else {
            fscanf(file,"\n");
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (boxMap[i][j] == 'Y') {
                x = i;
                y = j;
                boxMap[i][j] = ' ';
            }
            if (boxMap[i][j] == '#') {
                boxes[numBox].x = i;
                boxes[numBox].y = j;
                boxes[numBox++].getDestination = 0;
                boxMap[i][j] = ' ';
            }
            if (boxMap[i][j] == 'O') {
                des[numDes].x = i;
                des[numDes].y = j;
                des[numDes++].covered = 0;
                boxMap[i][j] = ' ';
            }
        }
    }
    
    fclose(file);
    keypad(stdscr,true);
    noecho();
    mapPut();
}

int check(int x,int y) {
    if (x < 0 || x >= N || y < 0 || y >= N) return 0;
    if (boxMap[x][y] == '*') return 0;
    return 1;
}

void xyMove(int xx,int yy) {
    for (int i = 0; i < numDes; i++) {
        if (des[i].x == xx && des[i].y == yy) {
            des[i].covered = 1;
        }
        if (des[i].x == x && des[i].y == y) {
            des[i].covered = 0;
        }
    }
    x = xx; y = yy;
    step++;
}

int checkBox(int l,int k) {
    int xx = boxes[l].x + dx[k];
    int yy = boxes[l].y + dy[k];
    if (xx < 0 || xx >= N || yy < 0 || yy >= N) return 0;
    if (boxMap[xx][yy] == '*') return 0;
    for (int i = 0; i < numBox; i++) {
        if (xx == boxes[i].x && yy == boxes[i].y) {
            return 0;
        }
    }
    for (int i = 0; i < numDes; i++) {
        if (xx == des[i].x && yy == des[i].y && !des[i].covered) {
            return 2;
        }
    }
    return 1;
}

void boxMove(int k) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    
    int isBox = 0;
    int boxIndex;
    for (int i = 0; i < numBox; i++) {
        if (boxes[i].x == xx && boxes[i].y == yy) {
            isBox = 1;
            boxIndex = i;
            break;
        }
    }
    
    if (isBox) {
        int checkBoxResult = checkBox(boxIndex,k);
        if (checkBoxResult == 1) {
            if (boxes[boxIndex].getDestination) {
                boxes[boxIndex].getDestination = 0;
            }
            boxes[boxIndex].x += dx[k];
            boxes[boxIndex].y += dy[k];
            xyMove(xx,yy);
        }
        if (checkBoxResult == 2) {
            boxes[boxIndex].x += dx[k];
            boxes[boxIndex].y += dy[k];
            boxes[boxIndex].getDestination = 1;
            for (int i = 0; i < numDes; i++) {
                if (des[i].x == boxes[boxIndex].x && des[i].y == boxes[boxIndex].y) {
                    des[i].covered = 1;
                }
            }
            xyMove(xx,yy);
        }
    }
    else {
        if (check(xx,yy)) {
            xyMove(xx,yy);
        }
    }
    mapPut();
}

void restart() {
    step = 0;
    numBox = 0; numDes = 0;
    isFinish = 0;
    memset(boxMap,0,sizeof(boxMap));
    init();
}
