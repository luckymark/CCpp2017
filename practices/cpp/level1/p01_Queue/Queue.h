#ifndef QUEUE_H
#define QUEUE_H


class Queue
{
    public:
        Queue();
        void append(int number);
        void pop();
        bool IsEmpty();
        bool IsFull();
        virtual ~Queue();

    private:
        int data[100];
        int i;
};

#endif // QUEUE_H
