#include "Sales.h"

Sales::Sales(const std::string & n, int a, int l, int s) :Employee(n, a, l)
{
	sales = s;
	salary = l * 1000 + sales*0.2;
}

void Sales::show() const
{
Employee::show();
}
