#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#define sub LINES-3
#define menu_size 6
#define ins_num 4
#define str_len 105 
#define data_area LINES-6
#define data_begin 3
#define maxn 105
char menu[menu_size][str_len] = {"|open(1)|","|save(2)|","|put in(3)|","|put out(4)|","|quit(5)|","|refresh(6)|"};
char title[2][str_len] = {"type", "number"};
int cur_line;
int data[maxn][2];
int data_tot;
int flag[maxn];
char input[maxn];
FILE *file;
void print_line(int whe){
		for(int i = 1; i < COLS-1; i++)
				mvaddch(whe,i,'-');
}
void print_mid_line(){
		for(int i = 1; i < sub; i++)
				mvaddch(i,COLS/2-1,'|');
}
void init(){
		clear();
		attron(A_REVERSE);
		box(stdscr,' ',' ');
		for(int i = 0; i < COLS; i++)
				mvaddch(sub,i,' ');
		int cur = 2;
		for(int i = 0; i < menu_size; i++){
				int len = strlen(menu[i]);
				for(int j = 0; j < len; j++){
						mvaddch(0,cur,menu[i][j]);
						cur++;
				}
				cur++;
		}
		attroff(A_REVERSE);
		cur = 1;
		int len = strlen(title[0]);
		for(int j = 0; j < len; j++){
				mvaddch(1,cur,title[0][j]);
				cur++;
		}

		cur = COLS/2;
		len = strlen(title[1]);
		for(int j = 0; j < len; j++){
				mvaddch(1,cur,title[1][j]);
				cur++;
		}

		print_mid_line();
		print_line(2);
		for(int i = data_begin + 1; i < data_begin + data_area; i+=2){
				print_line(i);
		}

		refresh();
}
void print_on_the_botton(char s[]){
		mvprintw(LINES-1,2,"%s",s);
}
void print_data(){
		int cnt = cur_line;
		for(int i = data_begin; i < data_begin + data_area; i += 2){
				mvprintw(i,1,"           ");
				mvprintw(i,COLS/2,"             ");
		}
		for(int i = data_begin; i < data_begin + data_area && cnt < data_tot; i += 2,cnt++){
				mvprintw(i,1,"%d",data[cnt][0]);
				mvprintw(i,COLS/2,"%d",data[cnt][1]);
		}
}
void open_the_data(char name[]){
		file = fopen(name,"r");
		if(file == NULL){
				attron(A_REVERSE);
				print_on_the_botton("fail to open, you need to start a new file");
				attroff(A_REVERSE);
		}

		int cur = 0;
		while(fscanf(file," %d%d",&data[cur][0],&data[cur][1]) != EOF){
				cur++;
		}
		data_tot = cur;

		cur_line = 0;
		print_data();
		fclose(file);
}
void save_the_data(char name[]){
		file = fopen(name,"w");

		int cur = 0;
		for(int i = 0; i < data_tot; i++){
				fprintf(file,"%d %d\n",data[i][0],data[i][1]);
		}
		if(name[0] == 'd'){
				attron(A_REVERSE);
				print_on_the_botton("save completed");
				attroff(A_REVERSE);
		}

		fclose(file);
}
char instruction[ins_num][str_len] = {" please input the type of the goods: ", " please input the number of the goods: "};
void print_on_sub(char s[str_len]){
		mvprintw(LINES-3,1,"%s",s);
}
int get_num(char s[str_len]){
		int len = strlen(s);
		int ans = 0;
		for(int i = 0; i < len; i++){
				if(s[i] == '\n') break;
				ans *= 10;
				ans += s[i] - '0';
		}
		return ans;
}
void swap(int *a,int *b){
		int t = *a;
		*a = *b;
		*b = t;
}
void deal(int x,int y){
		attron(A_REVERSE);
		if(y == 0) return;
		for(int i = 0; i < data_tot; i++){
				if(data[i][0] == x){
						data[i][1] += y;
						if(y < 0 && data[i][1] < 0){
								print_on_the_botton("you don't have enough goods");
								data[i][1] -= y;
								attroff(A_REVERSE);
								return;
						}
						if(y < 0 && data[i][1] == 0){
								print_on_the_botton("the 0 number good will be removed");
								swap(&data[i][0],&data[data_tot][0]);
								swap(&data[i][1],&data[data_tot][1]);
								data_tot--;
								attroff(A_REVERSE);
								return;
						}
						attroff(A_REVERSE);
						return;
				}
		}
		if(y < 0) 
				print_on_the_botton("you don't have this kind of good");
		else if(y > 0){
				data[data_tot][0] = x;
				data[data_tot][1] = y;
				data_tot++;
				cur_line = data_tot-1;
				save_the_data("tmp");
				open_the_data("tmp");
		}
		attroff(A_REVERSE);

}
void put_in_out(int kind){
		echo();
		attron(A_REVERSE);
		print_on_sub(instruction[0]);
		attroff(A_REVERSE);
		move(LINES-2,1);
		memset(input,0,sizeof(input));
		getstr(input);
		int first = get_num(input);

		attron(A_REVERSE);
		for(int i = 1; i < COLS-1; i++){
				mvaddch(LINES-3,i,' ');
		}
		print_on_sub(instruction[1]);
		attroff(A_REVERSE);
		for(int i = 1; i < COLS-1; i++){
				mvaddch(LINES-2,i,' ');
		}

		move(LINES-2,1);
		memset(input,0,sizeof(input));
		getstr(input);
		int second = get_num(input);
		deal(first,second*kind);
		noecho();
		save_the_data("tmp");
		open_the_data("tmp");
}
void get_input(){
		noecho();
		int c = getch();
		if(c == 27){
				c = getch();
				c = getch();

				switch(c){
						case 65: if(cur_line < data_tot - 1) 
										 cur_line++;
								 print_data();
								 break;
						case 66: if(cur_line > 0)
										 cur_line--;
								 print_data();
								 break;
						default: break;
				}
		} else if(c == '1'){
				open_the_data("data");
		} else if(c == '2'){
				save_the_data("data");
		}else if(c == '3'){
				put_in_out(1);
		}else if(c == '4'){
				put_in_out(-1);
		}else if(c == '5'){
				open_the_data("tmp");
				save_the_data("data");
				endwin();
				system("rm -r tmp");
				exit(0);
		}else if(c == '6'){
				save_the_data("tmp");
				init();
				open_the_data("tmp");
		}
}
void work(){
		while(1){
				get_input();
		}
}
int main(){
		initscr();
		init();
		work();
		getch();
		endwin();
		return 0;

}
