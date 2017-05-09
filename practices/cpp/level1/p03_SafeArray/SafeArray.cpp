#include "SafeArray.h"
#include <cstring>
#include <iostream>


template <class Type>
SafeArray<Type>::SafeArray(int _size):size(_size){
	w = new Type[size+1];
	for(int i = 0; i <= size; i++)
		w[i] = Type();
}

template <class Type>
SafeArray<Type>::~SafeArray(){
	delete[] w;
}

template <class Type>
Type& SafeArray<Type>:: operator [] (int idx){
	if(idx < 0 || idx >= size){
		std::cerr << "fail to access " << idx << std::endl;
		return w[size];
	}
	return w[idx];
}
