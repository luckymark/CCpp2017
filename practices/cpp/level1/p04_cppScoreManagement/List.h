#ifndef LIST_H_DEFINDED
#define LIST_H_DEFINDED
#include <set>
#include <string>
#include <vector>
#include "Student.h"
using namespace std;

class List{
	private:
		set <Student> list;
		vector <string> order;
		void del_info_in_order(const string &kind);
		void add_info_in_order(const string &kind, int col);
	public:
		List();
		void add_info(const string &kind,int col);
		void del_info(const string &kind);
		void add_stu_stdin();
		void del_stu_stdin();
		void add_stu_file();
		void del_stu(const string &kind, const string &id);
		void modify_stu(const string &id, const string &kind, const string &cur);
		void draw_self();
		void save_self();
};


#endif
