#include <iostream>
using namespace std;
typedef int Data_type;

struct Linked_list
{
	Data_type data;
	Linked_list * next;
};
			
class Queue
{
public:
	Queue() : head(0),tail(0),num(0) {}
	void append (Data_type date);
	Data_type pop();
	bool is_full() { return num >= Max_num; }
	bool is_empty() { return num <= 0; }
private:
	enum { Max_num = 100 };
	Linked_list *head,*tail;
	int num;
};


void Queue::append(Data_type data)
{
	if(is_full())
	{
		cerr << "Fail to append, Queue is full!\n";
		return;
	}
	if(is_empty())
	{
		head = tail = new Linked_list;
	}
	else
	{
		tail = tail->next = new Linked_list;
	}
	tail->data = data;
	tail->next = 0;
	num++;
}

Data_type Queue::pop()
{
	if(is_empty())
	{
		cerr << "Fail to pop, Queue is empty!\n"; 
		return -1;
	}
	Data_type data = head->data;
	Linked_list *tmp = head;
	head = head->next;
	delete tmp;
	num--;
	return data;
}



int main()
{
	Queue q;
	q.append(1);
	q.append(2);
	q.append(3);
	int data = q.pop();
	cout <<  noskipws      <<   data << endl;
	 data = q.pop();
	cout <<  noskipws      <<   data << endl;
	 data = q.pop();
	cout <<  noskipws      <<   data << endl;
	 data = q.pop();
	cout <<  noskipws      <<   data << endl;

	for(int i = 0; i < 100; i++)
	{
		q.append(i);
	}
	q.append(1);
	q.append(1);
	return 0;
}
	
	
