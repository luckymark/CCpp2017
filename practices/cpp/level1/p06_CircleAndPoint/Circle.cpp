#include "Circle.h"

Circle::Circle(double x1, double y1, double r1)
{
	p = { x1,y1 };
	radius = r1;
}

Circle::Circle(Point & rp, double r1)
{
	p = rp;
	radius = r1;
}


void Circle::setradius()
{
	std::cout << "int the new radius: ";
	std::cin >> radius;
}

void Circle::Move()
{
	p.Move();
}

void Circle::Show()
{
	p.Show();
	std::cout << "radius: " << radius << std::endl;
}
