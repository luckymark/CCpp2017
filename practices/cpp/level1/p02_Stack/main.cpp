//
//  main.cpp
//  p02_Stack
//
//  Created by Jimmy Fan on 2017/3/30.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <iostream>
#include "Stack.h"
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    printf("请输入栈最大元素个数:");
    scanf("%d",&n);
    Stack<int> stack(n);
    bool flag = 1;
    while (flag) {
        int k;
        printf("请输入需要进行的操作编号:\n");
        printf(" 1:入栈\n 2:出栈\n 3:读取栈顶元素\n 4:判断栈是否为空\n 5:判断栈是否已满\n 0:退出\n");
        scanf("%d",&k);
        switch (k) {
            case 0:
                flag = 0;
                break;
            case 1: {
                printf("请输入需要入栈的元素:");
                int x;
                scanf("%d",&x);
                if (stack.isFull()) {
                    printf("Error : 栈已满，入栈失败\n");
                }
                else {
                    stack.push(x);
                }
                break;
            }
            case 2:
                if (stack.isEmpty()) {
                    printf("Erroe : 栈已空，出栈失败\n");
                }
                else {
                    stack.pop();
                }
                break;
            case 3:
                if (stack.isEmpty()) {
                    printf("Error : 栈已空，读取栈顶元素失败\n");
                }
                else {
                    printf("栈顶元素为:%d\n",stack.top());
                }
                break;
            case 4:
                if (stack.isEmpty()) {
                    printf("栈已空\n");
                }
                else {
                    printf("栈未空\n");
                }
                break;
            case 5:
                if (stack.isFull()) {
                    printf("栈已满\n");
                }
                else {
                    printf("栈未满\n");
                }
                break;
        }
    }
    
    return 0;
}
