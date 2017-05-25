/*
题目：IntStack（堆栈）

功能要求（一）：

实现一个IntStack类（后进先出FILO），可容纳100个int数据，并实现下面的操作：

push（入栈）
pop（出栈）
判断是否满
判断是否空
功能要求（二）：

实例化堆栈对象的时候，可指定该堆栈的容量

功能要求（三）（学了模板以后再做）：

将IntStack改造为类型无关的Stack
*/
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
