//
//  main.cpp
//  p03_SafeArray
//
//  Created by Jimmy Fan on 2017/4/11.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <iostream>
#include "SafeArray.h"

int main(int argc, const char * argv[]) {
    int n;
    printf("请输入数组容量:");
    scanf("%d",&n);
    SafeArray<int> safeArray(n);
    bool flag = 1;
    while (flag) {
        int k;
        printf("请输入所要进行的操作序号:\n");
        printf(" 1:读取元素\n 2:赋值元素\n 0:退出程序\n");
        scanf("%d",&k);
        int t,x;
        switch (k) {
            case 0:
                flag = 0;
                break;
            case 1: {
                printf("请输入要读取位置的下标:");
                scanf("%d",&t);
                Result<int> r = safeArray.getNum(t);
                if (!r.flag) {
                    printf("Error:数组下标越界!!\n");
                }
                else {
                    printf("元素为:%d\n",r.data);
                }
                break;
            }
            case 2: {
                printf("请输入赋值下标以及元素值:\n");
                scanf("%d %d",&t,&x);
                bool flag = safeArray.addNum(t, x);
                if (flag) {
                    printf("成功赋值!\n");
                }
                else {
                    printf("Error:数组下标越界!!\n");
                }
                break;
            }
        }
        
    }
    return 0;
}
