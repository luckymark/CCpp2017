#include <cstdio>
#include "Point.h"

Point::Point(){
	x=0;
	y=0;
}

Point::Point(double _x,double _y){
	x=_x;
	y=_y;
}

double Point::gitX(){
	return x;
}

double Point::gitY(){
	return y;
}

void Point::changeXY(double _x,double _y){
	x=_x;
	y=_y;
}

void Point::show(){
	printf("x=%.2lf y=%.2lf ",x,y);
}

