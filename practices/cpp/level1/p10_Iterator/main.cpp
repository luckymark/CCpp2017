#include<iostream>
#include"Queue.h"
#include"Iterator.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
	Queue queue;
	for(int i=0;i<50;i++)
	{
		queue.append(i);
	}
	for(Iterator it=queue.begin();it!=queue.end();++it)
	{
		cout<<*it<<endl;
	}
	return 0;
}
