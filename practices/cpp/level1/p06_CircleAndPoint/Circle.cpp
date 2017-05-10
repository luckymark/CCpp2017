//
//  Circle.cpp
//  p06_CircleAndPoint
//
//  Created by Jimmy Fan on 2017/4/18.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include "Circle.h"
#define PI 3.1415926

Circle::Circle(double x,double y,double R) {
    this -> centrePoint = Point(x,y);
    this -> R = R;
}

void Circle::move(double xx, double yy) {
    centrePoint.move(xx, yy);
}

void Circle::showCircle() {
    printf("圆心坐标为:");
    centrePoint.showPoint();
    printf("半径为:%lf\n",this -> R);
}

double Circle::area() {
    return PI * R * R;
}

void Circle::changeR(int R) {
    this -> R = R;
}
