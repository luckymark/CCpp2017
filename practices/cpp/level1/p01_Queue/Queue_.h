#pragma once
#define length 5
class Queue_
{
private:
	int one[length];
	int * array[length];
	int i;
	int o;
	int num;
public:
	Queue_();
	~Queue_();
	void one_first();
	void one_append();
	void one_pop();
	bool one_isFull();
	bool one_isEmp();
};

