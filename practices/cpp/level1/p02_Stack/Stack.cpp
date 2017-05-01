#include "Stack.h"
bool Stack::isFull() {
	return top == 99 ? true : false;
}

void Stack::push(int a) {
	top++;
	data[top] = a;
}

int Stack::pop(void) {
	top--;
	return data[top + 1];
}

bool Stack::isEmpty(void) {
	return top == 0 ? true : false;
}