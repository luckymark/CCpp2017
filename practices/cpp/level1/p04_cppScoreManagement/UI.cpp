#include "UI.h"
#include "IO.h"
using namespace std;

void get_size(){
	list_window_lines = LINES/4*3;
	list_window_cols = COLS-2;
	command_window_lines = LINES - list_window_lines - 2;
	command_window_cols = list_window_cols;
	command_window_begin_x = 1 + list_window_lines;
	command_window_begin_y = 1;

	content_begin_x = content_begin_y = 2;
	content_end_x = list_window_lines - 1;
	content_end_y = list_window_cols - 1;
}
void init(){
	initscr();
	noecho();
	get_size();
	curs_set(0);
}
void draw_interface(){
	attron(A_REVERSE);
	box(stdscr,'|','-');
	int y = 3;
	for(int i = 0; i < menu_size; i++){
		mvprintw(0,y,"%s",menu[i]);
		y += strlen(menu[i]) + 1;
	}
	list_window = subwin(stdscr,
			list_window_lines,
			list_window_cols,
			1,
			1);
	box(list_window,' ',' ');
	attroff(A_REVERSE);
	command = subwin(stdscr,
			command_window_lines,
			command_window_cols,
			command_window_begin_x,
			command_window_begin_y);
	content = newpad(content_lines,content_cols);
	touchwin(stdscr);
	wrefresh(list_window);
	wrefresh(command);
}

void draw_line(int x){
	int len = col_total_width;
	for(int i = 0; i < len; i++){
		mvwaddch(content,x,i,'-');
	}
}
void draw_space_line(int x,int len){
	for(int i = 0; i < len; i++){
		mvwaddch(command,x,i,' ');
	}
}
void move_list(int kind){
	int tmp = content_p_x + dirx[kind];
	if(tmp >= 0 && tmp < line_total_width)
		content_p_x += dirx[kind];

	tmp = content_p_y + diry[kind];
	if(tmp >= 0 && tmp < col_total_width)
		content_p_y += diry[kind];

	update_content();
}
void update_content(){
	prefresh(content,
			content_p_x,
			content_p_y,
			content_begin_x,
			content_begin_y, content_end_x, 
			content_end_y);
	//touchwin(stdscr);
	refresh();
}
void print_on_command(string s){
	//		clear_command();
	touchwin(stdscr);
	mvwprintw(command,0,0,"%s",s.c_str());
	wrefresh(command);
}
void clear_command(){
	draw_space_line(0,command_window_cols);
}
void finish(){
	delwin(content);
	delwin(list_window);
	endwin();
}

string get_user_input(){
	echo();
	curs_set(1);
	touchwin(stdscr);
	wrefresh(command);
	char tmp[1005];
	memset(tmp,0,sizeof(tmp));
	wgetstr(command,tmp);
	noecho();
	curs_set(0);
	clear_command();
	return string(tmp);
}
void draw_order(const vector<string> &order,int ss){
	col_total_width = order.size() * (col_width+1) + 1;
	line_total_width = (ss+1) * 2 + 1;
	draw_line(0);
	mvwaddch(content,1,0,'|');
	for(int i = 0; i < order.size(); i++){
		mvwprintw(content,1,i*col_width + i + 1, "%s", order[i].c_str());
		mvwaddch(content,1,(i+1)*(col_width+1),'|');
	}
}
void draw_stu(int x,const vector<string> &order){
	mvwaddch(content,x,0,'|');
	for(int i = 0; i < order.size(); i++){
		mvwprintw(content,x,i*col_width + i + 1, "%s", order[i].c_str());
		mvwaddch(content,x,(i+1)*(col_width+1),'|');
	}
}
void clear_pad(){
	wclear(content);
}
void fresh_all_ui(){
	get_size();
	delwin(content);
	delwin(list_window);
	delwin(command);
	draw_interface();
	clear_command();
	update_content();
	show_begin();
}
