#include <iostream>
#include"Stack.h"

using namespace std;

int main()
{
    Stack stack;
    stack.Push(1);
    cout<<stack.Max()<<endl;
    stack.Pop();
    cout<<stack.IfEmpty()<<endl;

    return 0;
}
