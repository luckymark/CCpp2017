#include <iostream>
#include "Stack.h"
using namespace std;

int main(int argc, char** argv) {
	Stack stack;
	stack.Push(1);
	cout<<stack.Top()<<endl;
	stack.Pop();
	cout<<stack.IsEmpty()<<endl;
	return 0;
}
