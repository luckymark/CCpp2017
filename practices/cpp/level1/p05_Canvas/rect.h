#ifndef RECT_H_
#define RECT_H_
#include "shape.h"
#include "point.h"

class rect: public shape, public point
{
    public:
        rect(point p = point(), double length = 0.0, double width = 0.0): p(p), length(length), width(width){}
        rect(double w, double x, double y, double z);
        double get_length();
        double get_width();
        void draw();
    private:
        double length, width;
        point p;
};

#endif
