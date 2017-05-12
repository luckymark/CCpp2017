#include"Point.h"
Point::Point(void) :Shape()
{
}

void Point::show(void)
{
	std::cout << "Point: x: " << x << " y: " << y << std::endl;
}