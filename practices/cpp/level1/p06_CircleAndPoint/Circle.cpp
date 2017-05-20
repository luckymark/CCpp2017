#include "Circle.h"
#include "Point.h"
Circle::Circle(Point p,int R){
	center=p;
	r=R;
}
Circle::Circle(int X,int Y,int R){
	center.move(X,Y);
	r=R;
}
ostream & operator<<(ostream & os,const Circle & c){
	os<<"X="<<c.center.x<<" Y="<<c.center.y<<" R="<<c.r;
	
	return os;
}
void Circle::move(int X,int Y){
	center.x+=X;
	center.y+=Y;
}
void Circle::change(int delta){
	if(r>-delta){
		r+=delta;
	}
}
Circle Circle::operator+(Point p){
	center.move(p);
	return *this;
}
