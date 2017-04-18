#ifndef IO_H_DEFINDED
#define IO_H_DEFINDED

#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

//extern ofstream data_out;
//extern ifstream data_in;

string get_user_input();
void choose_menu();
void open();
void save();
void add_stu();
void del_stu();
void modify_stu();
void add_subject();
void del_subject();
void quit();
void fresh_all();
void show_begin();
void open_file_in();
void close_file_in();
void open_file_out();
void close_file_out();

#endif
