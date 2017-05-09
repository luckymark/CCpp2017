#include <string.h>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#define task_num 8
#define box_num 10
#define maxn 105
#define W w[pos[0]][pos[1]]
WINDOW *WIN;
FILE *map[task_num+10];
FILE *score;
FILE *score1;
int point[task_num+10];
char w[maxn][maxn]; 
char w_tmp[maxn][maxn];
int size_data[2];
int cur_map = 1;
int pos[2];
int dirx[4]={0,0,-1,1};
int diry[4]={-1,1,0,0};
int step;
void my_put(int x,int y,int ch,int kind){
	attron(COLOR_PAIR(kind));
	mvaddch(x,y,ch);
	attroff(COLOR_PAIR(kind));
}
void my_putchar(int x,int y,char ch){
	if(ch == 'B'){
		my_put(x,y,ch,1);
	}else if(ch == 'x'){
		my_put(x,y,ch,2);
	}else if(ch == '@'){
		my_put(x,y,ch,3);
	}else {
		mvaddch(x,y,ch);
	}

}
int pic[maxn][maxn];
FILE *mid;
char pic_name[maxn] = {'m','i','d'};
char pic_tmp[maxn];
void push_pic(int x){
	sprintf(pic_name+3,"%d",x);
	mid = fopen(pic_name,"r");
	clear();
	int whe = 0;
	while(fgets(pic_tmp,sizeof(pic_tmp),mid) != NULL){
		//printf("%s",pic_tmp);
		int len  = strlen(pic_tmp);
		for(int i = 0; i < len; i++){
			my_putchar(whe,i,pic_tmp[i]);
		}
		whe++;
	}
	getch();
	refresh();
}

int tar_whe[box_num][2];
int cnt_tar;
void tar_insert(int x,int y){
	tar_whe[++cnt_tar][0] = x;
	tar_whe[cnt_tar][1] = y;
}

char map_name[105] = {'m','a','p'};
char str_int[105];
void open_map(){
	for(int i = 1; i <= task_num; i++){
		sprintf(map_name+3,"%d",i);
		if(map[i] != NULL) {
			fclose(map[i]);
			map[i] = NULL;
		}
		while(map[i] == NULL)
			map[i] = fopen(map_name,"r");
	}
}
void get_in_map(int kind){
	open_map();
	fscanf(map[kind],"%d%d",&size_data[0],&size_data[1]);
	fgets(w[0],sizeof(w[0]),map[kind]); /// 
	for(int i = 0; i < size_data[0]; i++)
		fgets(w[i], sizeof(w[i]), map[kind]);
}	
void clean(){
	for(int i = 1; i <= 4; i++){
		if(pos[1] + i < size_data[1]) 
			my_putchar(pos[0],pos[1] + i,w[pos[0]][pos[1] + i]);
		else 
			my_putchar(pos[0],pos[1] + i,' ');
	}
	my_putchar(pos[0], pos[1], '@');
}
void change_position(int x,int y,int x1,int y1){
	w[x1][y1] = w[x][y];
	w[x][y] = w_tmp[x][y];
	my_putchar(x1,y1,w[x1][y1]);
	my_putchar(x,y,w[x][y]);
	if(w[x1][y1] == '@'){
		pos[0] = x1;
		pos[1] = y1;
		move(x1,y1);
	}
}
int check_access(int x1,int y1){
	if(x1 < 0 || x1 >= size_data[0] || y1 < 0 || y1 >= size_data[1]) return 0;
	if(w[x1][y1] == '#') return 0;
	return 1;
}
void move_to(int x,int y,int x1,int y1,int x2,int y2){
	if(!check_access(x1,y1)) return;
	if(w[x1][y1] != 'B'){
		change_position(pos[0],pos[1],x1,y1);
		step++;
	}else {
		if(!check_access(x2,y2)) return;
		if(w[x2][y2] == 'B') return;

		change_position(x1,y1,x2,y2);
		change_position(x,y,x1,y1);
		step++;
	}
	refresh();
} void deal(int kind){
	move_to(pos[0],pos[1],pos[0] + dirx[kind],pos[1] + diry[kind],pos[0] + 2*dirx[kind],pos[1] + 2*diry[kind]);
}
extern void new_task(int x);
void Move(){
	int c = getch();
	if(c == 27){
		c = getch();
		c = getch();

		clean();
		switch(c){
			case 65: deal(2);break;
			case 66: deal(3);break;
			case 67: deal(1);break;
			case 68: deal(0);break;
			default: break;
		}
	} else if(c == 'a'){
		if(cur_map == 1) return;
		clean();
		cur_map--;
		new_task(cur_map);
	} else if(c == 'd'){
		if(cur_map == task_num) return;
		cur_map++;
		new_task(cur_map);
	}else if(c == 'r'){
		new_task(cur_map);
	}else if(c == 'q'){
		endwin();
		exit(0);
	}
}
void show_map(int x,int y){
	for(int i = 0; i < size_data[0]; i++)
		for(int j = 0; j < size_data[1]; j++)
			my_putchar(x + i, y + j, w[i][j]);
}
void find_pos(){
	for(int i = 0; i < size_data[0]; i++)
		for(int j = 0; j < size_data[1]; j++){
			if(w[i][j] == '@'){
				pos[0] = i; pos[1] = j;
			} 
			if(w[i][j] == 'x'){
				tar_insert(i,j);
			}
			if(w[i][j] == '@' || w[i][j] == 'B') w_tmp[i][j] = ' ';
			else w_tmp[i][j] = w[i][j];
		}
}
void init(int x){
	clear();
	get_in_map(x);
	show_map(0,0);
	find_pos();
	move(pos[0],pos[1]);
	refresh();
}
void new_task(int x){
	step = 0;
	memset(tar_whe,0,sizeof(tar_whe));
	cnt_tar = 0;
	init(x);
}
int check_win(){
	for(int i = 1; i <= cnt_tar; i++){
		if(w[tar_whe[i][0]][tar_whe[i][1]] != 'B') return 0;
	}
	return 1;
}
void update_score(){
	if(point[cur_map] == -1 || point[cur_map] > step){
		point[cur_map] = step;
	}
	score1 = fopen("score","w");
	for(int i = 1; i <= task_num; i++){
		fprintf(score1,"%d\n",point[i]);
	}
}
void work(int x){
	new_task(x);
	while(1){
		move(size_data[0] + 2,0);
		printw("the step is: %d", step);
		move(size_data[0] + 3,0);
		printw("the high score is: %d", point[cur_map]);
		move(pos[0],pos[1]);
		if(check_win()){
			update_score();
			break;
		}
		Move();
	}
}
void pre_work(){
	score = fopen("score","r");
	for(int i = 1; i <= task_num; i++){
		fscanf(score,"%d",&point[i]);
	}
}

char ch[205];
void win(){
	FILE *win = fopen("win","r");
	while(fgets(ch,sizeof(ch),win) != NULL){
		printf("%s",ch);
	}
	puts("");
}
int main(){
	pre_work();
	WIN = initscr();

	start_color();
	init_pair(1,COLOR_WHITE,COLOR_GREEN);
	init_pair(2,COLOR_WHITE,COLOR_BLUE);
	init_pair(3,COLOR_WHITE,COLOR_YELLOW);
	while(cur_map <= task_num){
		push_pic(cur_map);
		work(cur_map);
		cur_map++;
	}
	endwin();
	win();
	return 0;
}
