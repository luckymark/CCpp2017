#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include <iostream>
using namespace std;
//�����޹� 
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
