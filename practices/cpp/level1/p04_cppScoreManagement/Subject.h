#ifndef SUBJECT_H
#define SUBJECT_H
#include <list>
#include <string>
#include "Student.h"
using namespace std;
class Subject
{
	public:
		Subject(string Name){
			name = Name;
		}
		void student_in(string, string, double);
		void show();
		void student_out(string);
		void score_in(string);
		string name;
	protected:
		

		list<Student> student;
		list<Student>::iterator i;
		
};

#endif
