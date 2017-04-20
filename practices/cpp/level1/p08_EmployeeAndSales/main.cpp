#include <iostream>
#include "Employee.h"
#include "Sales.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Employee employee;
	employee.setName("a");
	employee.setAge(18);
	employee.setRank(1);
	employee.calculateSalary();
	employee.showSalary();
	
	Sales sale;
	sale.setSale(20);
	sale.setName("b");
	sale.setAge(19);
	sale.setRank(2);
	Employee *sales = &sale;
	sales->calculateSalary();
	sales->showSalary();
	return 0;
}
