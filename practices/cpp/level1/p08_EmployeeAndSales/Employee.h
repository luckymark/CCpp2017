#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
using std::string;
class Employee
{
	public:
		Employee(string name="NULL",int age=0,int rank=1);
		virtual void change(string name,int age,int rank);
		virtual void show();
	protected:
		string name;
		int age;
		int rank;
		int salary;
};
class Sale:public Employee
{
		int sales;
	public:
		Sale(string name="NULL",int age=0,int rank=1,int sales=0);
		virtual void change(string name,int age,int rank);
		void setSales(int sales);
		virtual void show();
		
};

#endif
