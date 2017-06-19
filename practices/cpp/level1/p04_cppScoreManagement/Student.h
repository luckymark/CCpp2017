#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
using namespace std;
class Student
{
	public:
		Student(string Name, string Id, double Score){
			name = Name;
			id = Id;
			score = Score;
		}
		string name;
		string id;
		double score;
	protected:
		
};

#endif
