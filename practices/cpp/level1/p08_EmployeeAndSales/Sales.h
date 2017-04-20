#ifndef SALES_H
#define SALES_H
#include "Employee.h"

class Sales: public Employee
{
	private:
		int sale;
		
	public:
		void setSale(int sale);
		
		int getSale();
		
		void calculateSalary();
		
};
#endif SALES_H
