#pragma once
#include<vector>
using namespace std; 
template<class T>class stack
{
public:
	stack(int n=0);
	~stack();
	void push(T const &a);
	void pop();
	T top() const;
	bool isEmp();//其实多余，为了完成要求
	bool isFull();
private:
	vector<T> elems;
	int n;
}; 

