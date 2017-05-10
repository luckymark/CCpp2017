//
//  Point.h
//  p06_CircleAndPoint
//
//  Created by Jimmy Fan on 2017/4/18.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Point_h
#define Point_h

class Point {
private:
    double x,y;
public:
    Point(double = 0,double = 0);
    void move(double x,double y);
    void showPoint();
};


#endif /* Point_h */
