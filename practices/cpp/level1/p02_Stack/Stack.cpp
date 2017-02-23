#include <iostream>
using namespace std;
template <class T> class Stack
{
public:
    Stack()
    {
        default_size=100;
        top=0;
        container=new T[default_size];
    }

    Stack(int x)
    {
        default_size=x;
        top=0;
        container=new T[default_size];
    }

    void push(T x)
    {
        container[++top]=x;
    }

    void pop()
    {
        top--;
    }

    bool isFull()
    {
        return top==default_size;
    }

    bool isEmpty()
    {
        return top==0;
    }
private:
    int top,default_size;
    T *container;
};

int main()
{
    Stack<int> s;
    for(int i=1;i<=100;i++)s.push(i);
    cout<<s.isFull()<<endl;
    for(int i=1;i<=100;i++)s.pop();
    cout<<s.isEmpty()<<endl;
    return 0;
}
