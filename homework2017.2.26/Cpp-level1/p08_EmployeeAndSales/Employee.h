#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
private:
	char name[100];
	int age,level;
public:
	Employee();
	Employee(char* _name,int _age,int _level);
	void setName(char* _name);
	void setAge(int _age);
	void setLevel(int _level);
	int  getWage();
};

#endif
