#include"Stack.h"

using namespace std;
void Stack::show()
{
	cout << "Here are the datas in the stack:";

	for (int i = 0;i < cur;i++) {
		cout << data[i] << "  ";
	}
}

void Stack::append(int num) {
	data[cur] = num;
	cur += 1;
}

int Stack::pop() {
	cur -= 1;
	return data[cur+1];
}

bool Stack::isFull() {
	return(cur == 100);
}

bool Stack::isEmpty() {
	return(cur == 0);
}