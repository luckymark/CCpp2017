//
//  Point.h
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include "Shape.h"

class Point: public Shape{
protected:
    int x,y;
public:
    Point(int = 0, int = 0);
    double area();
    void show();
};

#endif /* Point_h */
