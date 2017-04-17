#include <vector>
#include <cstdio>
#include "Course.h"

class Student{
	private:
		string name,num;
	public:
		vector<Course> courses;
		Student(string name,string num);
		~Student();
		string GetStudentName();
		string GetStudentNum();
		bool AddCourse(string CourseName,int Score);
		bool DeleteCourse(string CourseName);
};
