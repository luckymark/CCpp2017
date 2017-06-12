#include<iostream>

class Stack {

public:
	Stack(){
		data = NULL;
		cur = 0;
		size = 0;
	};
	void create(int n);
	void show();
	void append(int num);
	int pop();
	bool isFull();
	bool isEmpty();
	~Stack() {
		if (data != NULL) {
			delete[]data;
		}
	};

private:
	int *data;
	int cur;
	int size;
};