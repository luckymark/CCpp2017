#pragma once
#ifndef Sales_H_
#define Sales_H_
#include"Employee.h"
class Sales :public Employee
{
private:
	int sales;
public:
	Sales(const std::string &n = "none", int a = 0, int l = 0, int s=0);
	virtual void show() const;
	virtual ~Sales() {};
};
#endif // !Sales_H_