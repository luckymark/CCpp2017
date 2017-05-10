//
//  Stack.h
//  p02_Stack
//
//  Created by Jimmy Fan on 2017/3/30.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

template <class T>
class Stack {
private:
    int stop;
    T* s;
    int maxNum;
public:
    Stack(int n);
    ~Stack();
    void push(T x);
    T top();
    void pop();
    bool isFull();
    bool isEmpty();
};


#endif /* Stack_h */
