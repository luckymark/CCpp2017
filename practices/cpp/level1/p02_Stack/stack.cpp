#include"stack.h"
int Stack::pop()
{
	if (isEmpty())return false;
	else{
		top--;
		return stack1[top+1];
	}
}
bool Stack::isEmpty()
{
	return top == 0 ? true : false;
}
bool Stack::isFull()
{
	return top == 99 ? true : false;
}
void Stack::push(int x)
{
	if (!isFull())stack1[++top] = x;
}