#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        virtual ~Stack();
        Stack(int size);

        void Push(int value);
        void Pop();
        int Max();
        bool IfFull();
        bool IfEmpty();
    private:
        int* a;
        int head = 0;
};

#endif // STACK_H
