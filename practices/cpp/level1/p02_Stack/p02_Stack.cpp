#include<iostream>
#include<malloc.h>

using namespace std;

class stack
{
	public:
		stack(int size);
		int getsizeofstack();
		int isempty();
		int isfull(int number);
		int push(int a);
		int pop();
	private:
		int max;
		int sizeofstack;
		int *stackbuffer;
};

stack::stack(int size)
{
	stackbuffer = (int *)malloc(size * sizeof(int));
	sizeofstack = 0;
	max = size;
}

int stack::getsizeofstack()
{
	return sizeofstack;
}

int stack::isempty()
{
	if(sizeofstack == 0)
		return 1;
	else
		return 0;
}

int stack::isfull(int number)
{
	if(sizeofstack == number)
		return 1;
	else
		return 0;
}

int stack::push(int a)
{
	if(sizeofstack < max)
	{
		stackbuffer[sizeofstack] = a;
		sizeofstack++;
		return 1;
	}
	else
		return 0;
}

int stack::pop()
{
	if(sizeofstack > 0)
	{
		sizeofstack--;
		return stackbuffer[sizeofstack];
	}
	else
		return 0;
}

int main(void)
{
	int datanumber;
	cout<<"Enter the number of the stack data."<<endl;
	cin>>datanumber;
	stack stack1(datanumber);
	if(stack1.isempty())
	{
		cout<<"At the beginning the stack is empty."<<endl;
	}
	cout<<"Enter every data."<<endl;
	for(int i = 0; i < datanumber; i++)
	{
		int input = 0;
		cin>>input;
		if(!stack1.push(input))
		{
			cout<<"Input error."<<endl;
			return 0;
		}
	}
	if(stack1.isfull(datanumber))
	{
		cout<<"After entering "<<datanumber<<" datas,the stack is full"<<endl;
	}
	cout<<"Then pop all the data."<<endl;
	for(int i = 0; i < datanumber; i++)
	{
		stack1.pop();
	}
	if(stack1.isempty())
	{
		cout<<"The stack become empty again."<<endl;
	}
}
