#include<iostream>
#include"Queue.h"
using std::cout;
using std::endl;

int main()
{
    Queue queue;
    queue.append(2);
    queue.append(4);
    queue.append(8);
    cout<<"IsFull?->"<<queue.isFull()<<endl;

    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();
    cout<<"IsEmpty?->"<<queue.isEmpty()<<endl;

    return 0;
}
