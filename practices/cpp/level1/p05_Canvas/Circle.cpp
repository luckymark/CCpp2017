//
//  Circle.cpp
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include "Circle.h"

Circle::Circle(int x,int y,double r):Point(x,y) {
    this -> r = r;
}

double Circle::area() {
    return PI * r * r;
}

void Circle::show() {
    printf("圆心(%d,%d)\n",x,y);
    printf("半径为:%.3lf\n",r);
}
