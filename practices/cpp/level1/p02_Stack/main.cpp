#include<iostream>
#include"stack.h"
using namespace std;
int main()
{
	Stack stack;
	int i;
    stack.push(5);
	stack.push(4);
	stack.push(3);
	cout << stack.pop() << stack.pop() << stack.pop()<<endl;
}