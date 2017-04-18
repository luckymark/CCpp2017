#include <vector>
#include <iostream>
#include <string>
#include "Student.h"
#include "IO.h"
#include "UI.h"
ofstream log("log");
using namespace std;
Student::Student(){
		information.clear();
		information["班级"] = "";
		information["姓名"] = "";
		information["学号"] = "";
		information["成绩"] = "";
}
Student::Student(const string &id){
		information.clear();
		information["学号"] = id;
}
Student::Student(vector <string> &need){
		information.clear();
		for(int i = 0; i < need.size(); i++){
				information[need[i]] = "";
		}
}
void Student::set(string whe, string info){
		information[whe] = info;
}
void Student::del_info(const string &whe){
		auto it = information.find(whe);
		information.erase(it);
}
bool Student::operator == (Student another){
		return information["学号"] == another.information["学号"];
}
void Student::draw_self(int x,const vector <string> &order){
		vector <string> tmp;
		for(int i = 0; i < order.size(); i++){
				tmp.push_back(information[order[i]]);
		}
		draw_stu(x,tmp);
}
void Student::save_self(const vector <string> &order){
		extern fstream data_out;
		for(int i = 0; i < order.size(); i++){
				string tmp = information[order[i]];
				//data_out << information[order[i]] << " ";
				if(tmp.length() != 0){
						data_out << tmp << " ";
				}else {
						data_out << "none" << " ";
				}
		}
		data_out << endl;
}
