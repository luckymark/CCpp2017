#include "Point.h"

Point::Point()
{
    //ctor
}

Point::~Point()
{
    //dtor
}

void Point::SetX(int x)
{
    this->x=x;
}

void Point::SetY(int y)
{
    this->y=y;
}

int Point::GetX()
{
    return x;
}

int Point::GetY()
{
    return y;
}
