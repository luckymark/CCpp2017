#include <iostream>
#include "Stack.h"
using namespace std;

int main(int argc, char** argv) 
{
	
	Stack stack(100);
	cout<<stack.isEmpty()<<endl;
	cout<<stack.isFull()<<endl;
	stack.append(2);
	cout<<stack.isEmpty()<<endl;
	cout<<stack.isFull()<<endl;
	stack.pop();
	cout<<stack.isEmpty()<<endl;
	cout<<stack.isFull()<<endl;
	return 0;
}
