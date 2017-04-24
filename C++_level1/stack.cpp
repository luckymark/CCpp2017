#include <iostream>
using namespace std;
typedef int Data_type;
class Stack
{
public:
	Stack() : i(-1) {}
	void push(Data_type data)
	{
		if(is_full())
		{
			cerr << "Fail to push, Stack is full!\n";
			return;
		}
		arr[++i] = data;
	}	
	Data_type pop()
	{
		if(is_empty())
		{
			cerr << "Fail to pop, Stack is empty\n";
			return (-1);
		}
		return arr[i--];
	}
	bool is_full() { return (i >= Size - 1); }
	bool is_empty() { return (i < 0); }
private:
	enum { Size = 100 };
	int i;
	Data_type arr[Size];
};


int main()
{
	
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	int data = s.pop();
	cout <<  noskipws      <<   data << endl;
	 data = s.pop();
	cout <<  noskipws      <<   data << endl;
	 data = s.pop();
	cout <<  noskipws      <<   data << endl;
	 data = s.pop();
	cout <<  noskipws      <<   data << endl;

	for(int i = 0; i < 100; i++)
	{
		s.push(i);
	}
	s.push(1);
	s.push(1);
	return 0;
}
	
	
