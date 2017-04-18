#include "Point.h"
#include<iostream>
using std::ostream;
Point::Point(int X,int Y){
	x=X;
	y=Y;
}
void Point::move(int X,int Y){
	x+=X;
	y+=Y;
}
void Point::move(Point p){
	x+=p.x;
	y+=p.y;
}
ostream & operator<<(ostream & os,const Point & p){
	os<<"X="<<p.x<<" Y="<<p.y;
	
	return os;
}
