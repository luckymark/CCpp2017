#include "Sales.h"

void Sales::setSale(int sale)
{
	this->sale = sale;
}

int Sales::getSale()
{
	return sale;
}

void Sales::calculateSalary()
{
	setSalary(getRank() * 1000 +  sale * 0.2);
}
