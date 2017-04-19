#include "UI.h"
#include "IO.h"
#include "List.h"
#include <curses.h>
#include <string>
using namespace std;

List core;
fstream data_in;
fstream data_out;

void open_file_in(){
	data_in.open("data",ios::in);
}
void close_file_in(){
	data_in.close();
}


void open_file_out(){
	data_out.open("data",ios::out);
}
void close_file_out(){
	data_out.close();
}

void choose_menu(){
	int c = getch();
	if(c == 27){
		c = getch();
		c = getch();
		switch(c){
			case 65: move_list(1);break;
			case 66: move_list(0);break;
			case 67: move_list(2);break;
			case 68: move_list(3);break;
			default: break;
		}
	} else {
		switch(c){
			case '1': open();break;
			case '2': save();break;
			case '3': add_stu();break;
			case '4': del_stu();break;
			case '5': add_subject();break;
			case '6': del_subject();break;
			case '7': modify_stu();break;
			case '8': quit();break;
			case '9': fresh_all();break;
		}
	}
}

void open(){
	core.add_stu_file();
	core.draw_self();
	update_content();
}
void save(){
	core.save_self();
	core.draw_self();
	update_content();
}
void add_stu(){
	core.add_stu_stdin();
	core.draw_self();
	update_content();
}
void del_stu(){
	core.del_stu_stdin();
	core.draw_self();
	update_content();
}
void add_subject(){
	print_on_command("subject name: ");
	string tmp = get_user_input();
	clear_command();
	print_on_command("place it in which col: ");
	string num = get_user_input();
	clear_command();
	core.add_info(tmp,stoi(num));
	core.draw_self();
	update_content();
}
void del_subject(){
	print_on_command("subject name: ");
	string tmp = get_user_input();
	clear_command();
	core.del_info(tmp);
	core.draw_self();
	update_content();
}
void modify_stu(){
	print_on_command("student name: ");
	string id = get_user_input();
	clear_command();
	print_on_command("subject name: ");
	string kind = get_user_input();
	clear_command();
	print_on_command("score: ");
	string cur = get_user_input();
	clear_command();
	core.modify_stu(id,kind,cur);
	core.draw_self();
	update_content();
}
void quit(){
	finish();
	exit(0);
}
void fresh_all(){
	fresh_all_ui();
}
void show_begin(){
	core.draw_self();
	update_content();
}
