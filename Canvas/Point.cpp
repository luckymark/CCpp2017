#include "Point.h"
#include <cstdio>

Point::Point(int x,int y): Shape(x,y){}

Point::~Point(){}

void Point::draw(){
	printf("Point:");
	drawPoint();
	puts("");
}
