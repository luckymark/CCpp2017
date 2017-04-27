#ifndef CLASS_H
#define CLASS_H

#include "Student.h"
class Class{
private:
	int total=0;
	Student s[200];
	char name[40],description[1000];
public:
	Class(char *a,char *b);
	void write();
	int Add(Student x);
	int Delete(Student x);
	void ShowList();
	void InputScore();
};

#endif
