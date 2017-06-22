#pragma once
#include<bits/stdc++.h>
using namespace std;
struct mess{
	int rank;
	int age;
};
class employ {
private:
	map<string, mess>list;
public:
	employ();
	~employ(){}
	void insert(string s1, int rank, int age);
	int getSalary(string s1);
	void show(string s1);
};

class sales :public employ{
private:
	int saleNum;
public:
	void pushSaleNum(int i);
	sales();
	~sales(){}
	int getSalary(string s1);
	void show(string s1);
};