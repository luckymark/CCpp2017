#include "Circle.h"
#include <cstdio>

Circle::Circle(int r,int x,int y): Shape(x,y){
	this->r=r;
}

Circle::~Circle(){}

void Circle::draw(){
	printf("Circle: Radius: %d, the Centre of the Circle: (%d,%d)\n",r,x,y);
}
