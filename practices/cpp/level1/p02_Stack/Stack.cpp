//
//  Stack.cpp
//  p02_Stack
//
//  Created by Jimmy Fan on 2017/3/30.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Stack.h"
using namespace std;

template <typename T>
Stack<T>::Stack(int n) {
    stop = 0;
    maxNum = n;
    s = new T(n);
}

template <class T>
void Stack<T>::push(T x) {
    s[stop ++] = x;
}

template <class T>
T Stack<T>::top() {
    return s[stop - 1];
}

template <class T>
void Stack<T>::pop() {
    stop --;
}

template <class T>
bool Stack<T>::isFull() {
    return stop == maxNum;
}

template <class T>
bool Stack<T>::isEmpty() {
    return stop == 0;
}


template <class T>
Stack<T>::~Stack() {
    delete [] s;
}
