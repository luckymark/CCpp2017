#include <iostream>
#include "Employee.h"
#include "Sales.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Employee employee;
	employee.setName("A");
	employee.setAge(29);
	employee.setLevel(2);
	cout<<employee.getWage()<<endl;
	
	Sales sales;
	sales.setName("B");
	sales.setAge(29);
	sales.setLevel(2);
	sales.addSale(500);
	cout<<sales.getWage()<<endl;
	return 0;
}
