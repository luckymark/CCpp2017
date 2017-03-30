#include <iostream>
#include "Stack.h"
using namespace std;
int main(){
		int size = 1000;
		Stack  my_stack(size);
		cout << my_stack.is_empty() << endl;
		for(int i = 1; i <= size; i++){
				if(!my_stack.is_full())
						my_stack.push(i);
		}
		cout << my_stack.is_full() << endl;
		for(int i = 1; i <= size; i++){
				if(!my_stack.is_empty())
						cout << my_stack.pop() << endl;
		}
		return 0;
}
