//
//  Circle.h
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include "Point.h"
#define PI 3.1415926

class Circle: public Point {
private:
    double r;
public:
    Circle(int = 0, int y = 0, double = 0);
    double area();
    void show();
};


#endif /* Circle_h */
