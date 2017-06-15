// Safe_array.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;

template<class T>
class SafeArray
{
public:
	SafeArray(int);
	~SafeArray();
	T& operator[](int);
private:
	T * data;
	int length;
};

template<class T>
SafeArray<T>::SafeArray(int len)
{
	data = new T[len];
	length = len;
}

template<class T>
SafeArray<T>::~SafeArray()
{
	delete[] this->data;
}

template<class T>
T& SafeArray<T>::operator[](int index)
 {
    if (index >= length || index<0)
	 {
		cout << "error:index out of range,return the first element(" << *data << ")" << endl;
		return *data;
	 }
	else
	 {
		return *(data + index);
	 }
}


int main()
 {
	SafeArray<int> array(100);
	for (int i = 0; i<10; i++)
		 {
		array[i] = i;
		cout << array[i] << endl;
		}
	return 0;
}

