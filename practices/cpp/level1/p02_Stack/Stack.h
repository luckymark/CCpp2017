#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        void append(int number);
        void pop();
        int show();
        bool IsFull();
        bool IsEmpty();
        virtual ~Stack();

    private:
        int *container;
        int head=0;
        int TOP=100;
};

#endif // STACK_H
