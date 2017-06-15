#include "Sales.h"

Sales::Sales(string name,int age,int rank,int SalesValue): Employee(name,age,rank){
	this->SalesValue=SalesValue;
}

int Sales::GetSalary(){
	return rank*1000+SalesValue/5;
}
