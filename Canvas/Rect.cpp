#include "Rect.h"
#include <cstdio>

Rect::Rect(int lenx,int leny,int x,int y): Shape(x,y){
	this->lenx=lenx;
	this->leny=leny;
}

Rect::~Rect(){}

void Rect::draw(){
	printf("Rect: the Length of X: %d, the Length of Y: %d, the Lowerleft Point of the Rect: ",lenx,leny);
	drawPoint();
	puts("");
}
