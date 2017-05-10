//
//  Circle.h
//  p06_CircleAndPoint
//
//  Created by Jimmy Fan on 2017/4/18.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Circle_h
#define Circle_h

#include "Point.h"

class Circle {
private:
    Point centrePoint;
    double R;
public:
    Circle(double = 0,double = 0,double = 0);
    void move(double xx,double yy);
    void showCircle();
    double area();
    void changeR(int R);
};


#endif /* Circle_h */
