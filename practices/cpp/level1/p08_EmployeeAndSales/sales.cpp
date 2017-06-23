#include "sales.h"
#include <string.h>
Sales::Sales(char* salesName, int salesLevel)
{
	strncpy(name, salesName);
	level = employeeLevel;
}

void Sales::setSaleCount(int Count)
{
	saleCount = Count;
}

virtual int Sales::getSalary()
{
	return level*1000 + saleCount/5;
}
