//
//  Point.cpp
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include "Point.h"

Point::Point(int x, int y) {
    this -> x = x;
    this -> y = y;
}

double Point::area() {
    return 0;
}

void Point::show() {
    printf("坐标为(%d,%d)\n",x,y);
}
