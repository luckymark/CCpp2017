#include "Stack.h"
#define MAX 100
Stack::Stack()
{
    //ctor
    a = new int[MAX];
}

Stack::~Stack()
{
    //dtor
    delete[] a;
}

Stack::Stack(int size)
{
    a = new int[size];
}

void Stack::Push(int value)
{
    a[head ++] = value;
}

void Stack::Pop()
{
    head --;
}

int Stack::Max()
{
    if(head - 1 < 0){
        return -1;
    }else{
        return a[head - 1];
    }
}

bool Stack::IfEmpty()
{
    return head == 0;
}

bool Stack::IfFull()
{
    return head == MAX;
}
