#include"employ.h"
employ::employ() { list.clear(); }

void employ::insert(string s1, int rank, int age)
{
	mess temp;
	temp.age = age;
	temp.rank = rank;
	list.insert(pair<string, mess>(s1, temp));
}

int employ::getSalary(string s1)
{
	map<string, mess>::iterator it = list.find(s1);
	return it->second.rank * 1000;
}

void sales::pushSaleNum(int i) { saleNum = i; }

sales::sales():employ(){}

int sales::getSalary(string s1) { return employ::getSalary(s1) + saleNum*0.2; }

void employ::show(string s1)
{
	map<string, mess>::iterator it = list.find(s1);
	cout <<"name: "<<s1<< "  Salary: " << getSalary(s1) << endl;
}

void sales::show(string s1)
{
	cout << "name: " << s1 << "  Salary: " << getSalary(s1) + saleNum*0.2 << endl;
}