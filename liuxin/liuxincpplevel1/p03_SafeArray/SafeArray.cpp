#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "SafeArray.h"

SafeArray::SafeArray(int x){
	tot=x;
	element=new int[x];
}

SafeArray::~SafeArray(){
	delete[] element;
}

int& SafeArray::operator [](int x){
	if (x<1||x>=tot) {
		std::cerr<<"RunTimeError!"<<std::endl;
		return element[0];
	}
	else return element[x];
}
