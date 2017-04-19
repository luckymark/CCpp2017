//tips 尝试优化掉无效移动 ！！！
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <curses.h>
#include <string.h>
#define maxn 10005
#define max_size 105
#define flip_ratio 0.0001
#define exchange_ratio 0.5
#define sample_num 100
#define genome_len 10000
#define q_len maxn*maxn*2
double length_ratio;
char map[max_size][max_size];
int map_size[2];

int st_pos[2];
int ed_pos[2];

int best_ans;
int dis[maxn][maxn];
struct Point{
	int x,y;
};
struct Point q[maxn * maxn * 2];
int q_front, q_end;
int q_tot;

int dirx[4]={0,0,1,-1};
int diry[4]={1,-1,0,0};
int rand_int(int l,int r){
	int del = r - l + 1;
	int now = rand() % del;
	return l + now;
}
struct Sample{
	int w[maxn]; // start from 0
	int length;
	double ratio;
	int flag;
	int step;
}sample[2][sample_num];
int epoch_num;
int cur_epoch;

void flip(struct Sample *a,int whe){
	if(whe > a->length) return;
	a->w[whe] ^= 1;
}
void append(struct Sample *a,int val){
	if(a->length == maxn - 1) return;
	a->w[ a->length ++] = val;
}
void exchange(struct Sample *a, int whe_a, struct Sample *b, int whe_b, struct Sample *c){
	c -> length = 0;
	for(int i = 0; i <= whe_a; i++){
		c->w[ c->length++ ] = a->w[i];
		if(c->length >= genome_len) return;
	}
	for(int i = whe_b; i < b -> length; i++){
		c->w[ c->length++ ] = b->w[i];
		if(c->length >= genome_len) return;
	}
}

void set_genome(struct Sample *a, int len){
	a -> length = len;
	for(int i = 0; i < len; i++){
		a -> w[i] = rand_int(0,3);
	}
}
void init_sample(){
	for(int i = 0; i < sample_num; i++){
		set_genome( &sample[cur_epoch][i], genome_len );
	}
}
int check(int x,int y){
	if( x < 0 || x >= map_size[0] || y < 0 || y >= map_size[1] ) return 0;
	if( map[x][y] == '#' ) return 0;
	return 1;
}
double my_abs(int a){
	double ans = a;
	return ans > 0 ? ans : -ans;
}
void get_point(struct Sample *cur){
	int x = st_pos[0], y = st_pos[1];
	cur -> step = 0;
	int tmp = cur -> length;
	for(int i = 0; i < tmp; i++){
		int x1 = x + dirx[ cur -> w[i] ];
		int y1 = y + diry[ cur -> w[i] ];
		if( !check(x1,y1) )
			continue;
		x = x1; y = y1;
		//cur -> w[cur->step++] = cur -> w[i];
		cur -> step ++;
	}
	if(x == ed_pos[0] && y == ed_pos[1])
		cur -> flag = 1;
	else 
		cur -> flag = 0;
	//cur -> length = cur -> step;
	cur -> ratio = 1.0 / ( my_abs( ed_pos[0] - x ) + my_abs( ed_pos[1] - y ) + 1 + cur->step/length_ratio ); // 
}
double rand_double(double l, double r){
	double ratio = rand() / (double)RAND_MAX;
	return l + (r - l) * ratio;
}
struct Sample* select_a_sample(){// roll panel
	double sum = 0.0;
	for(int i = 0; i < sample_num; i++)
		sum += sample[cur_epoch][i].ratio;
	double whe = rand_double(0.0,sum);

	sum = 0.0;
	for(int i = 0; i < sample_num; i++){
		sum += sample[cur_epoch][i].ratio;
		if(sum >= whe)
			return &sample[cur_epoch][i];
	}
	return NULL; // 
}
void creat_next_generation(){
	for(int i = 0; i < sample_num; i++){
		if( rand_double(0.0,1.0) < exchange_ratio ){
			struct Sample *a = select_a_sample();
			struct Sample *b = select_a_sample();
			exchange( a, rand_int( 0, a->length - 1 ), b, rand_int( 0, b->length - 1 ), &sample[cur_epoch ^ 1][i] );
		}else {
			struct Sample *a = select_a_sample();
			sample[cur_epoch ^ 1][i] = *a;
		}

		for(int j = 0; j < sample[cur_epoch ^ 1][i].length; j++){
			if( rand_double(0.0,1.0) < flip_ratio ){
				flip( &sample[cur_epoch ^ 1][i], j );
			}
		}
		//append//
	}
}
void change_cur_generation(){
	cur_epoch ^= 1;
}
void epoch(){
	creat_next_generation();
	change_cur_generation();
}
void draw_the_map(){
	for(int i = 0; i < map_size[0]; i++)
		for(int j = 0; j < map_size[1]; j++){
			mvaddch(i,j,map[i][j]);
		}
	refresh();
}
void draw_the_route(struct Sample *a){
	attron(COLOR_PAIR(1));
	mvaddch(st_pos[0],st_pos[1],'.');
	int x = st_pos[0], y = st_pos[1];
	for(int i = 0; i < a->length; i++){
		int x1 = x + dirx[a->w[i]];
		int y1 = y + diry[a->w[i]];
		if(!check(x1,y1)){
			continue;
		}
		x = x1, y = y1;
		mvaddch(x,y,'.');
	}
	attroff(COLOR_PAIR(1));
	mvprintw(map_size[0]+4, 0, "end position: %d %d", x,y);

	refresh();
}
void draw_the_best_one(){
	int whe = 0;
	double maxx = 0.0;
	int min_len = 0x3f3f3f3f;
	int ff = 0;
	for(int i = 0; i < sample_num; i++){
		if(sample[cur_epoch][i].flag > ff){
			whe = i;
			maxx = sample[cur_epoch][i].ratio;
			ff = sample[cur_epoch][i].flag;
		} else if(sample[cur_epoch][i].ratio > maxx){
			whe = i;
			maxx = sample[cur_epoch][i].ratio;
		}else if(sample[cur_epoch][i].ratio == maxx && min_len > sample[cur_epoch][i].length){
			whe = i;
			min_len = sample[cur_epoch][i].length;
		}
	}
	draw_the_map();
	draw_the_route( &sample[cur_epoch][whe] );
	mvprintw(map_size[0]+2, 0, "the length of the genome is: %d                         ", sample[cur_epoch][whe].length);
	mvprintw(map_size[0] + 3,0, "DNA: ");
	for(int j = 0; j < sample[cur_epoch][whe].length; j++)
		mvprintw(map_size[0]+3, j + 5, "%c", sample[cur_epoch][whe].w[j]+'0');
	mvaddch(map_size[0]+3,sample[cur_epoch][whe].length,' ');
	mvprintw(map_size[0]+5, 0, "point_ratio: %f", sample[cur_epoch][whe].ratio);
	mvprintw(map_size[0]+7, 0, "step: %d       ", sample[cur_epoch][whe].step);
	//getch();
}
int is_get_the_answer(){
	for(int i = 0; i < sample_num; i++){
		if(sample[cur_epoch][i].flag == 1 && sample[cur_epoch][i].step - best_ans <= 1000){
			return 1;
		}
	}
	return 0;
}
int is_ok(){
	for(int i = 0; i < sample_num; i++){
		if(sample[cur_epoch][i].flag == 1){
			return 1;
		}
	}
	return 0;
}
void show_epoch_num(){
	mvprintw(map_size[0] + 1, 0, "the epoch num is: %d", epoch_num);
	refresh();
}
void main_loop(){
	length_ratio = 100;
	init_sample();
	show_epoch_num();
	while(1){
		for(int i = 0; i < sample_num; i++){
			get_point( &sample[cur_epoch][i] );
		}
		if(epoch_num % 10 == 0)
			draw_the_best_one();
		if(is_get_the_answer()){
			//	clear();
			draw_the_best_one();
			break;
		}
		if(is_ok()){
			length_ratio -= 0.1;
			length_ratio = length_ratio <= 0 ? 0.01 : length_ratio;
		} else{
			length_ratio += 0.5;
		}
		mvprintw(map_size[0]+6,0,"length_ratio: %f ",length_ratio);
		epoch();
		epoch_num++;
		show_epoch_num();
	}
	//print_ans;
}

void find_door_in_map(){
	for(int i = 0; i < map_size[0]; i++)
		for(int j = 0; j < map_size[1]; j++){
			if(map[i][j] == '$'){
				st_pos[0] = i;
				st_pos[1] = j;
			}
			if(map[i][j] == 'X'){
				ed_pos[0] = i;
				ed_pos[1] = j;
			}
		}
}
//手动实现队列
void q_push(struct Point a){
	q[q_end++] = a;
	q_end %= q_len;
	q_tot++;
}
void q_pop(){
	q_front++;
	q_front %= q_len;
	q_tot--;
}
int q_empty(){
	return q_tot == 0;
}
struct Point q_get_front(){
	return q[q_front];
}
////没有stl，感觉想死
void bfs(){
	struct Point tmp;
	tmp.x = st_pos[0], tmp.y = st_pos[1];
	q_push(tmp);
	memset(dis,0x3f,sizeof(dis));
	dis[st_pos[0]][st_pos[1]] = 0;
	while(!q_empty()){
		tmp = q_get_front();
		q_pop();
		for(int i = 0; i < 4; i++){
			int x1 = tmp.x + dirx[i];
			int y1 = tmp.y + diry[i];
			if(check(x1,y1)){
				if(dis[tmp.x][tmp.y] + 1 < dis[x1][y1]){
					dis[x1][y1] = dis[tmp.x][tmp.y] + 1;

					struct Point tt;
					tt.x = x1; tt.y = y1;

					q_push(tt);
				}
			}
		}
	}
	best_ans = dis[ed_pos[0]][ed_pos[1]];
	mvprintw(map_size[0],0,"best_ans: %d",dis[ed_pos[0]][ed_pos[1]]);

}
void pre_work_with_map(){
	find_door_in_map();
	bfs();//find the best answer with bfs
}
void get_in_map(){
	FILE *now = fopen("map.in","r");
	if(now == NULL) return;
	fscanf(now, " %d%d  ", &map_size[0], &map_size[1]);
	for(int i = 0; i < map_size[0]; i++)
		fgets(map[i], sizeof(map[i]), now);
	fclose(now);
	pre_work_with_map();
}
void init_win(){
	initscr();
	clear();
	refresh();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_GREEN);
	init_pair(2,COLOR_WHITE,COLOR_BLUE);
	init_pair(3,COLOR_WHITE,COLOR_YELLOW);
}
int main(){
	srand(time(NULL));
	init_win();
	get_in_map();
	double start = clock();

	main_loop();

	double end = clock();
	mvprintw(map_size[0] + 8, 0, "the used time is: %f", (end - start)/CLOCKS_PER_SEC);
	getch();
	endwin();
	return 0;
}
