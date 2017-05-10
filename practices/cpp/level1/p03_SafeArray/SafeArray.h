//
//  SafeArray.h
//  p03_SafeArray
//
//  Created by Jimmy Fan on 2017/4/24.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef SafeArray_h
#define SafeArray_h

template <class T>
struct Result {
    T data;
    bool flag;
};

template <class T>
class SafeArray {
private:
    int n;
    T *a;
public:
    SafeArray(int = 0);
    ~SafeArray();
    Result<T> getNum(int k);
    bool addNum(int k,T x);
};



#endif /* SafeArray_h */
