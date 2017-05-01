//Äæ²¨À¼Ëã·¨ 
#include <iostream>
#include <stdio.h>
#include "Stack.h"
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a, b;
	Stack stack;
	char s[100];
	bool full;

	while(scanf("%s",s))
	{
		full = stack.isFull();
		if (full == true) {
			cout << "Õ»ÒÑÂú£¡" << endl;
			break;
		}
		
		if (s[0] == '+') {
			a = stack.pop();
			b = stack.pop();
			stack.push(a + b);
		}
		else if (s[0] == '-') {
			b = stack.pop();
			a = stack.pop();
			stack.push(a - b);
		}
		else if (s[0] == '*') {
			a = stack.pop();
			b = stack.pop();
			stack.push(a*b);
		}
		else {
			stack.push(atoi(s));
		}
	}
	full = stack.isEmpty();
	if (full == true) {
		cout << "Õ»Îª¿Õ" << endl;
	}
	cout << stack.pop() << endl;
	system("pause");
}
