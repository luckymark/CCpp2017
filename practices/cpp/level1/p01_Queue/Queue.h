#ifndef QUEUE_H
#define QUEUE_H


class queue
{
    public:
        queue();
        void append(int number);
        void pop();
        bool IsEmpty();
        bool IsFull();
        virtual ~queue();

    private:
        int data[10];
        int i;
};

#endif // QUEUE_H
