//
//  Point.cpp
//  p06_CircleAndPoint
//
//  Created by Jimmy Fan on 2017/4/18.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include "Point.h"

Point::Point(double x,double y) {
    this -> x = x;
    this -> y = y;
}

void Point::move(double x, double y) {
    this -> x += x;
    this -> y += y;
}

void Point::showPoint() {
    printf("%.3lf %.3lf\n",this -> x, this -> y);
}
