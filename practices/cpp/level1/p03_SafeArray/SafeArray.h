#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include <iostream>
using namespace std;
//长度无关 
class SafeArray
{
	public:
		int & operator [] (int num){
			return data[num];
		}
		
	protected:
		int data[5] = {0};
};

#endif
