#include<iostream>
using std::cin;
using std::cout;
using std::endl;

template<class T>
class Stack
{
	public:
		Stack(int);
		~Stack();
		void push(T);
		void pop();
		bool isFull();
		bool isEmpty();
	private:
		int *data,*top,length;
};


template<class T>
Stack<T>::Stack(int len)
{
	data=new T[len];
	this->top=this->data;
	this->length=len;
}

template<class T>
Stack<T>::~Stack()
{
	delete [] this->data;
}

template<class T>
bool Stack<T>::isFull()
{
	return this->top-this->data==this->length;
}

template<class T>
bool Stack<T>::isEmpty()
{
	return this->top==this->data;
}

template<class T>
void Stack<T>::push(T value)
{
	if(!isFull())
	{
		*top++=value;
	}
	else
	{
		cout<<"error:the stack is full."<<endl;
	}
}

template<class T>
void Stack<T>::pop()
{
	if(!isEmpty())
	{
		top--;
	}
	else
	{
		cout<<"error:the stack is empty."<<endl;
	}
}

int main()
{
	Stack<int> stack(95);
	for(int i=0;i<101;i++)
	{
		stack.push(i);
	}
	cout<<stack.isFull()<<endl;
	for(int i=0;i<101;i++)
	{
		stack.pop();
	}
	cout<<stack.isEmpty();
	
	return 0;
}
