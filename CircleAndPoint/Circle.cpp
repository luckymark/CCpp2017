#include "Circle.h"

Circle::Circle(Point p,int r){
	this->p=p;
	this->r=r;
}

void Circle::move(int delta_x,int delta_y){
	p.move(delta_x,delta_y);
}

void Circle::print(){
	p.print();
	printf(",°ë¾¶:%d\n",r);
}
