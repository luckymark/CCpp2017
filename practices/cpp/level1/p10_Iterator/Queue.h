#pragma once
#include"Iterator.h"

class Queue
{
    public:
        Queue();
        ~Queue();
        void append(int);
        void pop();
        bool isFull();
        bool isEmpty();
		Iterator begin();
		Iterator end();
    private:
        int *data,*head,*tail;
};