#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

class Employee
{
	public:
		Employee(int t_level);
		std::string name;
		unsigned age;
		int level;
		virtual double getSalary();
	protected:
		double salary;
};

class Sales : public Employee
{
	public:
		Sales(int t_level,double t_salesValue);
		double getSalary();
	private:
		double salesValue;
};
#endif // EMPLOYEE_H
