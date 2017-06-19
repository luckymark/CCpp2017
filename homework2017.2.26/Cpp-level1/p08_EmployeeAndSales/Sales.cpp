#include "Sales.h"
#include <cstring>
#include <iostream>
Sales::Sales(){
	sale=0;
}

Sales::Sales(char* _name,int _age,int _level,int _sale):Employee(_name,_age,_level),sale(_sale){};

void Sales::addSale(int _Sale){
	sale+=_Sale;
}

void Sales::clearSale(){
	sale=0;
}

int Sales::getWage(){
	return Employee::getWage()+sale/5;
}
