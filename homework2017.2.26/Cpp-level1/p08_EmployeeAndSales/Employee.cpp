#include "Employee.h"
#include <cstring>
#include <iostream>
using namespace std;
Employee::Employee(){
	memset(name,0,sizeof(0));
	age=level=-1;
}

Employee::Employee(char* _name,int _age,int _level){
	if (strlen(_name)>=100){
		cout<<"Fail!Name's length it overlength!"<<endl;
	}
	else{
		strcpy(name,_name);
	}
	age=_age;
	level=_level;
}

void Employee::setName(char* _name){
	if (strlen(_name)>=100){
		cout<<"Fail!Name's length it overlength!"<<endl;
	}
	else{
		strcpy(name,_name);
	}
}

void Employee::setAge(int _age){
	age=_age;
}

void Employee::setLevel(int _level){
	level=_level;
}

int Employee::getWage(){
	return level*1000;
}
