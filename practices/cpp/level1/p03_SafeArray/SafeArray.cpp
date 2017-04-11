#include "SafeArray.h"
#include <cstring>
#include <iostream>

SafeArray::SafeArray(int _size):size(_size){
		w = new int[size+1];
		//memset(w,0,sizeof(w));
		for(int i = 0; i <= size; i++)
				w[i] = 0;
}

SafeArray::~SafeArray(){
		delete[] w;
}

int& SafeArray:: operator [] (int idx){
		if(idx < 0 || idx >= size){
				std::cerr << "fail to access " << idx << std::endl;
				return w[size];
		}
		return w[idx];
}
