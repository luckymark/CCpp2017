#include "Employee.h"
#include <iostream>

Employee::Employee()
{
	salary = age = rank = 0;
	name = "";
}

void Employee::setName(string name)
{
	this->name = name;
}

void Employee::setAge(int age)
{
	this->age = age;
}

void Employee::setRank(int rank)
{
	this->rank = rank;
}

void Employee::setSalary(int salary)
{
	this->salary = salary;
}

string Employee::getName()
{
	return name;
}

int Employee::getAge()
{
	return age;
}

int Employee::getRank()
{
	return rank;
}

void Employee::calculateSalary()
{
	this->salary = getRank() * 1000;
}

int Employee::getSalary()
{
	return salary;
}

void Employee::showSalary()
{
	cout<<getName()<<"'s salary is "<<getSalary()<<endl;
}
