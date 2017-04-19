#include "List.h"
#include "Student.h"

#include "UI.h"
#include "IO.h"
using namespace std;

List::List(){
	order.push_back(string("学号"));
	order.push_back(string("班级"));
	order.push_back(string("姓名"));
	order.push_back(string("成绩"));
}

void List::add_info(const string &kind,int col){
	auto it = list.begin();
	if(!list.empty()){
		Student tmp = *it;
		if(tmp.information.count(kind)){
			print_on_command(string("the subject has been added"));
			getch();
			clear_command();
			return;
		}
		vector <Student> vec;
		for(it = list.begin(); it != list.end(); it++){
			tmp = *it;
			tmp.information[kind] = "";
			vec.push_back(tmp);
		}
		list.clear();
		for(int i = 0; i < vec.size(); i++){
			list.insert(vec[i]);
		}
	}
	add_info_in_order(kind,col);
}
void List::del_info(const string &kind){
	auto it = list.begin();
	if(!list.empty()){
		if(kind == "学号"){
			print_on_command(string("you can't delete the ID of a student"));
			getch();
			clear_command();
			return;
		}
		Student tmp;
		tmp = (*it);
		if(!(tmp.information.count(kind))){
			print_on_command(string("the subject dosen't exsist"));
			getch();
			clear_command();
			return;
		}
		vector <Student> vec;
		for(it = list.begin(); it != list.end(); it++){
			tmp = *it;
			auto it_stu = tmp.information.find(kind);
			tmp.information.erase(it_stu);
			vec.push_back(tmp);
		}
		list.clear();
		for(int i = 0; i < vec.size(); i++) list.insert(vec[i]);
	}
	del_info_in_order(kind);//
}
void List::del_info_in_order(const string &kind){
	for(auto it = order.begin(); it != order.end(); it++){
		if(*it == kind){
			order.erase(it);
			return;
		}
	}
}
void List::add_info_in_order(const string &kind, int col){
	auto it = order.begin() + col - 1;
	order.insert(it,kind);
}

void List::modify_stu(const string &id, const string &kind, const string &cur){
	auto it = list.find(Student(id));
	if(it == list.end()){
		print_on_command(string("we don't have this stu"));
		getch();
		clear_command();
		return;
	}
	Student tmp = *it;
	tmp.information[kind] = cur;
	list.erase(it);
	list.insert(tmp);
}
void List::draw_self(){
	clear_pad();
	draw_order(order,list.size());
	int i = 2;
	for(auto it = list.begin(); it != list.end(); it++, i++){
		draw_line(i); i++;
		Student tmp = *it;
		tmp.draw_self(i,order);
	}
	draw_line(i);
}
void List::del_stu_stdin(){
	Student tmp_stu;
	print_on_command(string("please input ID: "));
	string tmp = get_user_input();
	tmp_stu.set("学号",tmp);
	if(list.count(tmp_stu)){
		auto it = list.find(tmp_stu);
		list.erase(it);
	}else{
		print_on_command(string("We do not have this student"));
		getch();
		clear_command();
	}
}
void List::add_stu_stdin(){
	Student tmp_stu;
	for(int i = 0; i < order.size(); i++){
		//print_on_command("please in put " + order[i] + ": ");
		string pp = "please input " + order[i] + ": ";
		print_on_command(pp);
		string tmp = get_user_input();
		tmp_stu.set(order[i],tmp);
	}
	if(!list.count(tmp_stu)){
		list.insert(tmp_stu);
	}else{
		print_on_command("We already have this student");
		getch();
		clear_command();
	}
}
void List::add_stu_file(){
	open_file_in();
	extern fstream data_in; 
	extern fstream data_out;
	list.clear();
	order.clear();
	int num; data_in >> num;
	for(int i = 0; i < num; i++){
		string tmp; data_in >> tmp;
		order.push_back(tmp);
	}
	data_in >> num;
	for(int i = 1; i <= num; i++){
		Student tmp_stu;
		for(int j = 0; j < order.size(); j++){
			string tmp; data_in >> tmp;
			tmp_stu.set(order[j],tmp);
		}
		list.insert(tmp_stu);
	}
	close_file_in();
	print_on_command("open finish");
}
void List::save_self(){
	open_file_out();
	extern fstream data_in; 
	extern fstream data_out;
	data_out << order.size() << endl;
	for(int i = 0; i < order.size(); i++){
		data_out << order[i] << " ";
	}
	data_out << endl;
	data_out << list.size() << endl;
	for(auto it = list.begin(); it != list.end(); it++){
		Student tmp = *it;
		tmp.save_self(order);
	}
	close_file_out();
	print_on_command("save finish");
}
