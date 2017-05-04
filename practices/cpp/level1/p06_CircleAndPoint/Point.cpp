#include "Point.h"

Point::Point(double x1, double y1)
{
	x = x1;
	y = y1;
}

void Point::Move()
{
	std::cout << "input the new x-val: ";
	std::cin >> x;
	std::cout << "input the new y-val: ";
	std::cin >> y;
}

void Point::Show() const
{
	std::cout << "x: " << x << " y: " << y << std::endl;
}
