/*
题目：Employee & Sales（员工 与 销售员）

功能要求：

实现一个雇员类： 2. 记录员工的姓名、年龄、级别等属性 3. 可计算员工的工资（按每个级别1000元计算）
实现一个销售员类： 3. 记录sales的销售额 4. 计算工资时需要在级别工资基础上，加上销售提成（按20%核算）
*/
#include<iostream>
#include<string>
using namespace std;

class Employee{
	protected:
		string name;
		int age;
		int level;
	public:
		Employee(string,int,int);
		virtual void salary();
};

class Sales :public Employee{
	private:
		int sales;
	public:
		Sales(string,int,int,int);
		void salary();
};

Employee::Employee(string n,int a,int l){
	name=n;
	age=a;
	level=l;
}

void Employee::salary(){
	cout<<this->name<<"'s salary is"<<this->level*1000<<"yuan ."<<endl;
}

Sales::Sales(string n,int a,int l,int s)
:Employee(n,a,l)
{
    sales=s;
}

void Sales::salary(){
	cout<<this->name<<"'s salary is"<<this->level*1000+sales*0.2<<"yuan ."<<endl;
}

int main(){
    Employee *e=new Employee("Helen",25,7);
    e->salary();
    e=new Sales("Bob",27,5,3600);
    e->salary();
	return 0;
}
