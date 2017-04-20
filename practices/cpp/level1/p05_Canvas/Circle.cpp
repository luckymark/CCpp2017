#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle()
{
	r =  0;
}

void Circle::setR(int r)
{
	this->r = r;
}

int Circle::getR()
{
	return r;
}

void Circle::showParams()
{
	cout<<"the central of circle is "<<"("<<getPoint().getX()<<","<<getPoint().getY()<<")"<<", raduis is : "<<r<<endl;
}

