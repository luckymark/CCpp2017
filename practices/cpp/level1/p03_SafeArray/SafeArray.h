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



//### ��Ŀ��SafeArray����ȫ���飩

//### ����Ҫ��һ����

//ʵ��int������Ļ������ܣ��������±�Խ��ʱ����

//### ����Ҫ�󣨶�����ѧ����������غ���������

//ʵ���±����������

//### ����Ҫ��������ѧ��ģ�����������

//ʵ�������޹صİ�ȫ���飻


