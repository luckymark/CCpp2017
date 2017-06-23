//
//  main.cpp
//  p06_CircleAndPoint
//
//  Created by Jimmy Fan on 2017/4/18.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <iostream>
#include "Circle.h"

int main(int argc, const char * argv[]) {
    printf("请输入圆心坐标:(以逗号隔开)\n");
    double x,y;
    scanf("%lf,%lf",&x,&y);
    printf("请输入半径: ");
    double R;
    scanf("%lf",&R);
    Circle C(x,y,R);
    
    bool flag = 1;
    while (flag) {
        printf("\n请输入要进行的操作编号:\n");
        printf(" 1:移动圆\n 2:求面积\n 3:改变半径\n 4:输出当前圆的信息\n 0:退出程序\n");
        int k;
        scanf("%d",&k);
        switch (k) {
            case 0:
                flag = 0;
                break;
            case 1: {
                printf("输入要移动的偏移量:\n");
                double xx,yy;
                scanf("%lf,%lf",&xx,&yy);
                C.move(xx, yy);
                break;
            }
            case 2:
                printf("面积大小为:%.3lf\n",C.area());
                break;
            case 3: {
                printf("请输入新的半径大小: ");
                double R;
                scanf("%lf",&R);
                C.changeR(R);
                break;
            }
            case 4:
                C.showCircle();
                break;
        }
    }
    
    return 0;
}
