#ifndef CIRCLE_H_
#define CIRCLE_H_
#include "shape.h"
#include "point.h"

class circle: public shape
{
    public:
        circle(point p = point(), double radius = 0.0): p(p), radius(radius){}
        circle(double x, double y, double z);
        double get_radius();
        void draw();
    private:
        point p;
        double radius;
};

#endif 
