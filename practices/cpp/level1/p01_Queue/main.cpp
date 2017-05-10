//
//  main.cpp
//  p01_Queue
//
//  Created by Jimmy Fan on 2017/3/30.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <iostream>
#include "Queue.h"
#define N 100
using namespace std;

int main(int argc, const char * argv[]) {
    Queue que(N);
    bool flag = 1;
    while (flag) {
        int k;
        printf("请输入需要进行的操作编号:\n");
        printf(" 1:入队\n 2:出队\n 3:读取队首元素\n 4:读取队尾元素\n 5:判断队列是否为空\n 6:判断队列是否已满\n 0:退出程序\n");
        scanf("%d",&k);
        switch (k) {
            case 0:
                flag = 0;
                break;
            case 1:
                printf("请输入需要入队的元素:");
                int x;
                scanf("%d",&x);
                if (que.isFull()) {
                    printf("Error : 队列已满，入队失败\n");
                }
                else {
                    que.append(x);
                }
                break;
            case 2:
                if (que.isEmpty()) {
                    printf("Erroe : 队列已空，出队失败\n");
                }
                else {
                    que.pop();
                }
                break;
            case 3:
                if (que.isEmpty()) {
                    printf("Error : 队列为空，读取队首元素失败\n");
                }
                else {
                    printf("队首元素为:%d\n",que.front());
                }
                break;
            case 4:
                if (que.isEmpty()) {
                    printf("Error : 队列为空，读取队尾元素失败\n");
                }
                else {
                    printf("队尾元素为:%d\n",que.back());
                }
                break;
            case 5:
                if (que.isEmpty()) {
                    printf("队列已空\n");
                }
                else {
                    printf("队列未空\n");
                }
                break;
            case 6:
                if (que.isFull()) {
                    printf("队列已满\n");
                }
                else {
                    printf("队列未满\n");
                }
                break;
        }
    }

    
    return 0;
}
