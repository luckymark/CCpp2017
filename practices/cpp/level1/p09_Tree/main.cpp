//
//  main.cpp
//  p09_Tree
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Tree.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Tree mytree;
    bool flag = 1;
    while (flag) {
        printf("请输入所需操作编号:\n 1:添加结点\n 2:求节点的父节点\n 3:求节点的子节点个数\n 0:退出程序\n");
        int k;
        scanf("%d",&k);
        switch (k) {
            case 0:
                flag = 0;
                break;
            case 1: {
                printf("请输入在几号节点下添加子节点:\n");
                int kk;
                scanf("%d",&kk);
                printf("请输入子节点的data值:\n");
                int x;
                scanf("%d",&x);
                mytree.append(x, kk);
                break;
            }
            case 2: {
                printf("请输入求几号节点的父节点:\n");
                int kk;
                scanf("%d",&kk);
                printf("%d号节点的父节点编号为%d\n",kk,mytree.getParentID(kk));
                break;
            }
            case 3: {
                printf("请输入求几号节点的子节点个数:\n");
                int kk;
                scanf("%d",&kk);
                printf("%d号节点的子节点个数为%d\n",kk,mytree.getNumOfSon(kk));
                break;
            }
        }
    }
    
    return 0;
}
