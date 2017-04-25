#include "Shape.h"
#include <cstdio>

Shape::Shape(int x,int y){
	this->x=x;
	this->y=y;
}

void Shape::drawPoint(){
	printf("(%d,%d)",x,y);
}
