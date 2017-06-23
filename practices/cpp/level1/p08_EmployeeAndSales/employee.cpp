#include "employee.h"
#include <string.h>
Employee::Employee(char *employeeName, int employeeLevel)
{
	strncpy(name, employeeName);
	level = employeeLevel;
}

virtual int Employee::getSalary()
{
	return level*1000;
}

char* Employee::getName()
{
	return name;
}

int Employee::getLevel()
 {
 	return level;
 }
 
void setLevel(int employeeLevel)
 {
 	level = employeeLevel;
 }
