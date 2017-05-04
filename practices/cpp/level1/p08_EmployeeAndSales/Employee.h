#pragma once
#ifndef Employee_H_
#define Employee_H_
#include<iostream>
#include<string>

class Employee
{
protected:
	std::string name;
	int age;
	int level;
	double salary;
public:
	Employee(const std::string &n = "none", int a = 0, int l = 0);
	virtual void show() const;
	virtual ~Employee() {};
};
#endif // !Employee_H_
