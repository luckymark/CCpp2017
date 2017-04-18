#ifndef UI_H_DEFINDED
#define UI_H_DEFINDED
#include <string>
#include <curses.h>
#include <cstring>
#include <vector>
using namespace std;

//const int menu_width;
static const int menu_size = 9;
static const int str_max_len = 30;
static const char menu[menu_size][str_max_len] = {"|open(1)|",
										   "|save(2)|",
										   "|add stu(3)|",
										   "|del stu(4)|",
										   "|add subject(5)|",
										   "|del subject(6)|",
										   "|modify stu(7)|",
										   "|quit(8)|",
										   "|refresh(9)|"};

static WINDOW *list_window,*content,*command;
static int list_window_lines;
static int list_window_cols;
static int content_begin_x, content_end_x;
static int content_begin_y, content_end_y;
static const int content_lines = 1000, content_cols = 1000;
static const int col_width = 20;
static int col_total_width;
static int line_total_width;
static int content_p_x, content_p_y;
static int command_window_lines;
static int command_window_cols;
static int command_window_begin_x;
static int command_window_begin_y;

static const int dirx[4]={1,-1,0,0};
static const int diry[4]={0,0,1,-1};


void init();
void draw_line(int x);
void draw_interface();
void move_list(int kind);
//string get_input();
void finish();
void print_on_command(string info);
void draw_space_line();
void clear_command();
void update_content();
void draw_order(const vector<string> &order,int ss);
void draw_stu(int x,const vector<string> &order);
void clear_pad();
void fresh_all_ui();
string get_user_input();
#endif
