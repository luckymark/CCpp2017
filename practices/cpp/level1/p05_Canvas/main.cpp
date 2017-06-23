//
//  main.cpp
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <iostream>
#include "Canvas.h"
using namespace std;

int main(int argc, const char * argv[]) {
    Canvas canvas;
    bool flag = 1;
    while (flag) {
        printf("请输入所需操作编号:\n 1:添加图形\n 2:展示画布\n 3:清空画布\n 0:退出程序\n");
        int k;
        scanf("%d",&k);
        switch (k) {
            case 0:
                flag = 0;
                break;
            case 1: {
                printf("请输入图形种类编号:\n 1:圆\n 2:矩形\n");
                int kk;
                scanf("%d",&kk);
                switch (kk) {
                    case 1: {
                        int x,y; double r;
                        printf("圆心: ");
                        scanf("%d %d",&x,&y);
                        printf("半径: ");
                        scanf("%lf",&r);
                        Circle circle(x,y,r);
                        canvas.addShape(&circle);
                        break;
                    }
                    case 2: {
                        int x1,y1,x2,y2;
                        printf("输入位于对角线上的两个点的坐标: ");
                        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                        Rect rect(x1,y1,x2,y2);
                        canvas.addShape(&rect);
                        break;
                    }
                }
                break;
            }
            case 2:
                canvas.show();
                break;
            case 3:
                canvas.clear();
                break;
        }
    }

    return 0;
}
