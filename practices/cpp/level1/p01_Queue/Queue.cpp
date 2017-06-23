//
//  Queue.cpp
//  p01_Queue
//
//  Created by Jimmy Fan on 2017/3/30.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include "Queue.h"
#include <cstdlib>
using namespace std;

Queue::Queue(int n) {
    head = (Node *)malloc(sizeof(Node));
    head -> next = NULL;
    tail = (Node *)malloc(sizeof(Node));
    tail -> next = NULL;
    num = 0;
    maxNum = n;
}

void Queue::append(int x) {
    Node *p;
    p = (Node *)malloc(sizeof(Node));
    p -> x = x;
    p -> next = NULL;
    if (!num) {
        head -> next = p;
        tail -> next = p;
    }
    else {
        tail -> next -> next = p;
        tail -> next = p;
    }
    num ++;
}

int Queue::front() {
    return head -> next -> x;
}

int Queue::back() {
    return tail -> next -> x;
}

void Queue::pop() {
    Node *p;
    p = head -> next;
    head -> next = p -> next;
    free(p);
    p = NULL;
    num --;
}

bool Queue::isFull() {
    return num == maxNum;
}

bool Queue::isEmpty() {
    return num == 0;
}
