#include "Stack.h"

Stack::Stack(int _size):size(_size){
		top = 0;
		w = new int[size];
}

Stack::~Stack(){
		delete [] w;
}

void Stack::push(int x){
		w[top++] = x;
}

 int Stack::pop(){
		int x = w[--top];
		return x;
}

bool Stack::is_full(){
		return top == size;
}

bool Stack::is_empty(){
		return top == 0;
}
