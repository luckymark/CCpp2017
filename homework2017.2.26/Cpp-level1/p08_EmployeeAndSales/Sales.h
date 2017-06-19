#ifndef SALES_H
#define SALES_H
#include "Employee.h"

class Sales:public Employee{
private:
	int sale;
public:
	Sales();
	Sales(char* _name,int _age,int _level,int _sale);
	void addSale(int _sale);
	void clearSale();
	int getWage();
};

#endif


