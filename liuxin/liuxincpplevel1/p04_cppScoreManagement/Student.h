#ifndef STUDENT_H
#define STUDENT_H

class Student{
private:
	char ID[20],name[20];
public:
	int score;
	Student();
	Student(char *a,char *b);
	void write();
	bool operator ==(const Student &x);
};

#endif
