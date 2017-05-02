#include<iostream>
#include"Stack.h"
using namespace std;
int main()
{
    Stack a(10);
    cout<<a.isEmpty()<<endl;
    a.append(1);
    a.append(2);
    a.pop();
    cout<<a.isFull()<<endl;
    return 0;
}
