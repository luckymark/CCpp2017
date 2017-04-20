#include "circle.h"

Point::Point(double nx, double ny)
{
	this->x = nx;
	this->y = ny;
}

void Point::move(double nx, double ny)
{
	this->x += nx;
	this->y += ny;
}

void Point::reset(double nx, double ny)
{
	this->x = nx;
	this->y = ny;
}

Circle::Circle(double r, double x, double y)
{
	Point p(x, y);
	this->radius = r;
	this->center = p;
}

Circle::Circle(double r, Point &p)
{
	this->radius = r;
	this->center = p;
}

void Circle::move(double cx, double cy)
{
	(this->center).move(cx, cy);
}

void Circle::moveTo(double nx, double ny)
{
	(this->center).reset(nx, ny);
}
