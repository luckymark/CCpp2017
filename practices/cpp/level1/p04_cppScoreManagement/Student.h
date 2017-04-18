#ifndef STUDENT_H_DEFINDED
#define STUDENT_H_DEFINDED
#include <string>
#include <map>
#include <vector>
using namespace std;

struct Student{
				map <string, string> information;
				Student();
				Student(const string &id);
				Student(vector <string> &need);
				void set(string whe, string info);
				void del_info(const string &whe);
				void draw_self(int x, const vector <string> &order);
				void save_self(const vector <string> &order);
				bool operator == (Student another);
				friend bool operator < (Student a, Student b){
						return a.information["学号"] < b.information["学号"];
				}
};

#endif
