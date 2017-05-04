#include "Employee.h"

Employee::Employee(const std::string & n, int a, int l)
{
	name = n;
	age = a;
	level = l;
	if (level == 0)
	{
		salary = 0;
	}
	else
	{
		salary = level * 1000;
	}
}

void Employee::show() const
{
	std::cout << "name: " << name << std::endl << "age: " << age << std::endl << "level: " << level << std::endl << "salary: " << salary << std::endl;
}
