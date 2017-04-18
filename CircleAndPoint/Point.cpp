#include "Point.h"

Point::Point(int x,int y){
	this->x=x;
	this->y=y;
}

void Point::move(int delta_x,int delta_y){
	x+=delta_x;
	y+=delta_y;
}

void Point::print(){
	printf("Ô²ÐÄ:(%d,%d)",x,y);
}
