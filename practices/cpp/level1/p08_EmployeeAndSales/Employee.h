#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
	private:
		string name;
		int age, rank, salary;
	
	public:
		Employee();
		
		void setName(string name);
		
		void setAge(int age);
		
		void setRank(int rank);
		
		void setSalary(int salary);
		
		string getName();
		
		int getAge();
		
		int getRank();
		
		virtual void calculateSalary();
		
		int getSalary();
		
		void showSalary();
		
};
#endif EMPLOYEE_H
