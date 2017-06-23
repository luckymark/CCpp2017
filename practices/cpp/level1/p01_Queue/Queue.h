//
//  Queue.h
//  p01_Queue
//
//  Created by Jimmy Fan on 2017/3/30.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

struct Node {
    int x;
    Node *next;
};

class Queue {
private:
    Node *head, *tail;
    int num;
    int maxNum;
public:
    Queue(int n);
    void append(int x);
    int front();
    int back();
    void pop();
    bool isFull();
    bool isEmpty();
};



#endif /* Queue_h */
