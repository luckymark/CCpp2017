#include "Stack.h"
template <class Type>
Stack<Type>::Stack(int _size):size(_size){
	top = 0;
	w = new Type[size];
}

template <class Type>
Stack<Type>::~Stack(){
	delete [] w;
}

template <class Type>
void Stack<Type>::push(Type x){
	w[top++] = x;
}

template <class Type>
Type Stack<Type>::pop(){
	return w[--top];
}

bool Stack<Type>::is_full(){
	return top == size;
}

bool Stack<Type>::is_empty(){
	return top == 0;
}
