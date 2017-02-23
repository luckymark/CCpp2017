#include <iostream>
#include <cstring>
#define MN 100
using namespace std;
class Queue
{
public:
    Queue()
    {
        head=0;tail=0;
        memset(container,0,sizeof(container));
    }

    void append(int x)
    {
        container[head++]=x;
    }

    void pop()
    {
        tail++;
    }

    bool isFull()
    {
        if(head-tail==MN)return true;
        else return false;
    }

    bool isEmpty()
    {
        if(head==tail)return true;
        else return false;
    }
private:
    int head,tail,container[1000];
};

int main()
{
    Queue Q;
    for(int i=1;i<=100;i++)Q.append(i);
    cout<<Q.isFull()<<endl;
    for(int i=1;i<=100;i++)Q.pop();
    cout<<Q.isEmpty()<<endl;
    return 0;
}
