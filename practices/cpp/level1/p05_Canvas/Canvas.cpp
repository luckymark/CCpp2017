//
//  Canvas.cpp
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include "Canvas.h"

Canvas::Canvas(int n) {
    k = 0;
    this -> n = n;
}

void Canvas::addShape(Shape* shape) {
    shapes[k ++] = shape;
}

void Canvas::show() {
    for (int i = 0; i < k; i++) {
        shapes[i] -> show();
    }
}

void Canvas::clear() {
    k = 0;
}
