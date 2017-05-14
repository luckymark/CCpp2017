#include<iostream>
#include "circle.h"

circle::circle(double x, double y, double z)
{
    p = point(x, y);
    radius = z;
}

double circle::get_radius()
{
    return radius;
}

void circle::draw()
{
    cout<<"the center of circle is: ";
    p.display();
    cout<<"the radius of circle is: "<<get_radius()<<endl;
}
