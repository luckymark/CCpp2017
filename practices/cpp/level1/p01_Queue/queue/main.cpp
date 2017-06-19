#include<iostream>
#include"Queue.h"
using namespace std;
int main()
{
    Queue a(10);
    cout<<a.isEmpty()<<endl;
    a.append(1);
    a.append(2);
    a.pop();
    cout<<a.isFull()<<endl;
    return 0;
}
