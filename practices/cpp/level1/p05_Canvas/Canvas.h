//
//  Canvas.h
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Canvas_h
#define Canvas_h

#include "Circle.h"
#include "Rect.h"
#define N 100

class Canvas {
private:
    Shape* shapes[N];
    int k;
    int n;
public:
    Canvas(int = 0);
    void addShape(Shape *shape);
    void show();
    void clear();
};



#endif /* Canvas_h */
