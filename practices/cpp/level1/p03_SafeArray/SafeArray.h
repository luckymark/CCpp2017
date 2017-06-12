#pragma once
#include<iostream>
using namespace std;
template <typename T> class SafeArray
{
	public:
		SafeArray(int size = 0);
		SafeArray(T x,int size = 0);
		~SafeArray();
		T operator [](int n);
		friend istream& operator >> (istream& in, T& t) 
		{
			in >> t;
			return in;
		}
	private:
		int size;
		T* pr;
};



//### 题目：SafeArray（安全数组）

//### 功能要求（一）：

//实现int型数组的基本功能，当数组下标越界时报错；

//### 功能要求（二）（学了运算符重载后再做）：

//实现下标运算操作；

//### 功能要求（三）（学了模板后再做）：

//实现类型无关的安全数组；


