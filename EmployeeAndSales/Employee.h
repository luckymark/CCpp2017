#include <string>
using namespace std;

class Employee{
	private:
		string name;
		int age;
	protected:
		int rank;
	public:
		Employee(string name,int age,int rank);
		virtual int GetSalary(){
			return rank*1000;
		};
};
