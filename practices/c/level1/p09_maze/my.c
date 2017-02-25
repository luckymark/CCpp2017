#include <string.h>
#include <stdio.h>
#include <curses.h>
#define X pos[0]+del[cur_map][0]
#define Y pos[1]+del[cur_map][1]
#define W w[cur_map][pos[0]][pos[1]]
#define maxn 105
FILE *map[2];
char w[2][maxn][maxn];
int size_data[2][2];
void get_in_map(char w[maxn][maxn],int kind){
		fscanf(map[kind],"%d%d",&size_data[kind][0],&size_data[kind][1]);
		fgets(w[0],sizeof(w[0]),map[kind]);
		for(int i = 0; i < size_data[kind][0]; i++)
				fgets((char*) w[i], sizeof(w[i]), map[kind]);
}	
int whe;
char tmp;
int cur_map;
int pos[2];
int dirx[4]={0,0,-1,1};
int diry[4]={-1,1,0,0};
int del[2][2] = {{0,0},{20,0}};
void clean(){
		for(int i = 1; i <= 4; i++){
				if(pos[1] + i < size_data[cur_map][1]) 
						mvaddch(X,Y + i,w[cur_map][pos[0]][pos[1] + i]);
				else 
						mvaddch(X,Y + i,' ');
		}
		mvaddch(X, Y, '@');
}
void change_position(int x1,int y1,int whe){
		mvaddch(X, Y, W);
		pos[0] = x1; pos[1] = y1;
		cur_map = whe;
		mvaddch(X, Y, '@');
		refresh();
}
void deal(int kind){
		int x1 = pos[0] + dirx[kind];
		int y1 = pos[1] + diry[kind];
		clean();
		if(x1 < 0 || x1 >= size_data[cur_map][0] || y1 < 0 || y1 >= size_data[cur_map][1]) return;
		if(w[cur_map][x1][y1] == '#') return; 
		change_position(x1,y1,cur_map);
}
void go(int x,int y,int whe){
		clean();
		W = ' ';
		clean();
		change_position(x,y,1);
		W = ' ';
		clean();
}
void change(){
		clean();
		switch(W){
				case'%':go(14,20,1);
						break;
				case'@':go(12,33,1);
					   	break;
				case'*':go(12,18,1);
					   	break;
				default: break;
		}
}
void Move(){
		int c = getch();
		if(c == 27){
				c = getch();
				c = getch();
				switch(c){
						case 65: deal(2);break;
						case 66: deal(3);break;
						case 67: deal(1);break;
						case 68: deal(0);break;
						default: break;
				}
		} else {
				if(c == 'x') change();
		}
}
void show_map(int x,int y,int whe){
		for(int i = 0; i < size_data[whe][0]; i++)
				for(int j = 0; j < size_data[whe][1]; j++)
						mvaddch(x + i, y + j, w[whe][i][j]);
}
void init(){
		show_map(0,0,0);
		show_map(20,0,1);
		for(int i = 0; i < size_data[0][0]; i++){
				int flag = 0;
				for(int j = 0; j < size_data[0][1]; j++)
						if(w[cur_map][i][j] == '$'){
								pos[0] = i; pos[1] = j;
								flag = 1; break;
						}
				if(flag) break;
		}
		mvaddch(pos[0],pos[1],'@');
		refresh();
}
void work(){
		init();
		while(1){
				Move();
				if(W == '^'){
						break;
				}
		}
}
char ch[205];
void win(){
		FILE *win = fopen("win","r");
		while(fgets(ch,sizeof(ch),win) != NULL){
				//puts(ch);
				printf("%s",ch);
		}
		puts("");
}
int main(){
		map[0] = fopen("map1","r");
		map[1] = fopen("map2","r");
		get_in_map(w[0],0);
		get_in_map(w[1],1);
		initscr();
		work();
		endwin();
		//puts("You win");
		win();
		return 0;
}
