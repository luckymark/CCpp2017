#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int x0,int y0)
{
	x=x0;
	y=y0;
}
void Point::draw()
{
	cout<<"x="<<x<<' '<<"y="<<y<<' ';
	
}
void Point::move(int x1,int y1)
{
	x=x1;
	y=y1;
}

