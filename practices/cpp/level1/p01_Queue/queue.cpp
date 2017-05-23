#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Queue
{
    public:
        Queue();
        ~Queue();
        void append(int);
        void pop();
        bool isFull();
        bool isEmpty();
    private:
        int *data,*head,*tail;
};

Queue::Queue()
{
    data=new int[100];
    head=data;
    tail=data;
}

Queue::~Queue()
{
    delete[] data;
}

bool Queue::isFull()
{
    return this->head+1==this->tail||this->head-this->tail==100?true:false;
}

bool Queue::isEmpty()
{
    return this->head==this->tail?true:false;
}

void Queue::append(int n)
{
    if(!this->isFull())
    {
        head++;
        if(this->head-this->data==100)
        {
            this->head=this->data;
        }
        *(this->head)=n;
    }
    else
    {
        cout<<"error:The queue is full."<<endl;
    }
}

void Queue::pop()
{
    if(!this->isEmpty())
    {
        tail++;
        if(this->tail-this->data==100)
        {
            this->tail=this->data;
        }
    }
    else
    {
        cout<<"error:The queue is empty."<<endl;
    }
}

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