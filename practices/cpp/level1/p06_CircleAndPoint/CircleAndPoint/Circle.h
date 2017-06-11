#include "Point.h"
#ifndef CIRCLE_H
#define CIRCLE_H

struct Circle{
private:
    Point circle_point;
    double r;
public:
    Circle();
    Circle(double x_input,double y_input,double r_input);
    Circle(Point Point_input,double r_input);
    void move(double aim_x,double aim_y);
    void extend(double aim_r);
    void show();
};

#endif // CIRCLE_H
