#include "Employee.h"

class Sales: public Employee{
	private:
		int SalesValue;
	public:
		Sales(string name,int age,int rank,int SalesValue);
		virtual int GetSalary();
};
