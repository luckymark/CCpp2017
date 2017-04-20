#include "circle.h"
Point::Point(const double &x, const double &y)
{
    this->x = x;
    this->y = y;
}

void Circle::move(const Point &p)
{
    this->centre_point = p;
}