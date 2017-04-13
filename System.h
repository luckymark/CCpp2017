#include <iostream>
#include "Student.h"
using namespace std;
class System{
	private:
		vector<Student> students;
	public:
		System();
		~System();
		bool AddStudent(string StudentName,string StudentNum);
		bool AddScore_of(string StudentNum,string CourseName,int Score);
		bool DeleteCourse_of(string StudentNum,string CourseName);
		bool DeleteStudent(string StudentNum);
		void ShowStudents();
};
