//
//  SafeArray.cpp
//  p03_SafeArray
//
//  Created by Jimmy Fan on 2017/4/24.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include "SafeArray.h"

template <class T>
SafeArray<T>::SafeArray(int n) {
    this -> n = n;
    a = new T(n);
}

template <class T>
SafeArray<T>::~SafeArray() {
    delete [] a;
}

template <class T>
Result<T> SafeArray<T>::getNum(int k) {
    Result<T> r;
    if (k < 0 || k >= n) {
        r.flag = 0;
    }
    else {
        r.flag = 1;
        r.data = a[k];
    }
    return r;
}

template <class T>
bool SafeArray<T>::addNum(int k,T x) {
    if (k < 0 || k >= n) return 0;
    else {
        a[k] = x;
        return 1;
    }
}
