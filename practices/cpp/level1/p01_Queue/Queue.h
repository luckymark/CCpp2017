#progma once

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
