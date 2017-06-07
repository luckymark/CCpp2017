#include "Employee.h"

Employee::Employee(int t_level=1)
{
	level = t_level;
}

double Employee::getSalary()
{
	salary = level * 1000;
	return salary;
}

Sales::Sales(int t_level = 1,double t_salesValue = 6000)
{
	level = t_level;
	salesValue = t_salesValue;
}

double Sales::getSalary()
{
	salary = salesValue*0.2 + level * 1000.0;
	return salary;
}
