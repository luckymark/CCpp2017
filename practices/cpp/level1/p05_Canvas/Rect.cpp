//
//  Rect.cpp
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include "Rect.h"
using namespace std;

int __abs(int x) {
    return x < 0 ? -x:x;
}

Rect::Rect(int x1, int y1, int x2, int y2):Point(min(x1,x2),min(y1,y2)) {
    width = __abs(x1 - x2);
    height = __abs(y1 - y2);
}

double Rect::area() {
    return width * height;
}

void Rect::show() {
    printf("矩形左下角坐标为(%d,%d)\n",x,y);
    printf("宽度为%d 高度为%d\n",width,height);
}
