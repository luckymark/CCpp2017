#include "Rect.h"
#include <cstdio>


Rect::Rect(int x1,int y1,int x,int y): Shape(x,y){
	this->x1=x1;
	this->y1=y1;
}

Rect::~Rect(){}

void Rect::draw(){
	printf("Rect:  the diagonal Point of the Rect: (%d,%d),the other diagonal Point of the Rect: (%d,%d)\n",x1,y1,x,y);
}
