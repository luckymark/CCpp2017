#include <iostream>
#include "Employee.h"
using namespace std;

int main()
{
	Sales s1 = Sales(5,6000);
	Employee e1 = Employee(6);
	double e1_salary = e1.getSalary();
	double s1_salary = s1.getSalary();
	cout<<e1_salary<<endl<<s1_salary<<endl;
}
