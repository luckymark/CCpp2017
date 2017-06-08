#include <iostream>
#include "Point.h"
using namespace std;

Point::Point(double xx,double yy){
	x=xx;
	y=yy;
}

void Point::move(double dx,double dy){
	x+=dx;
	y+=dy;
}

void Point::show(){
	cout<<'<'<<x<<','<<y<<'>'<<endl;
}
