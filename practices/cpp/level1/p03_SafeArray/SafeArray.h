#pragma once
#ifndef SafeArray_H_
#define SafeArray_H_
#include<iostream>
class safearray {
private:
	int num;
	int *arr;
public:
	safearray(void);
	safearray(int n);
	safearray(const safearray& a);
	~safearray(void);
	int& operator[](int n);
	safearray& operator=(const safearray& a);
};
#endif // !SafeArray_H_
