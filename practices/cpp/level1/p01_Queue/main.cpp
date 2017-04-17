#include<iostream>
#include"Queue.h"

using namespace std;

int main(int argc, char** argv)
{
    Queue q;
    if(q.empty())
    {
        cout<<"queue is empty"<<endl;
    }
    cout<<endl<<"append data"<<endl;
    for(int i = 0; i < 100; i++)
    {
        q.append(i);
    }
    cout<<"display:"<<endl;
    q.display();
    if(q.full())
    {
        cout<<endl<<"queue is full"<<endl;
    }
    cout<<endl<<"pop data"<<endl;
    for(int i = 0; i < 100; i++)
    {
        q.pop(i);
    }
    q.display();
    if(q.empty())
    {
        cout<<endl<<"queue is empty"<<endl;
    }
	return 0;
}
