#include "Circle.h"
#include <iostream>
using namespace std;

void Circle::setCenter(Point p)
{
	this->center = p;
}

Point Circle::getCenter()
{
	return center;
}

void Circle::setR(int r)
{
	this->r = r;
}

int Circle::getR()
{
	return r;
}

void Circle::move(int offx,int offy)
{
	center.setX(center.getX() + offx);
	center.setY(center.getY() + offy);
}

void Circle::resize(int r)
{
	setR(r);
}

void Circle::show()
{
	cout<<"Center Point:"<<"("<<getCenter().getX()<<","<<getCenter().getY()<<")"<<endl;
	cout<<"Radius:"<<getR()<<endl;
}
