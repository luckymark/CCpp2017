#include <cstdio>
#include "Rectangle.h"

Rectangle::Rectangle(int _x,int _y,int _length,int _width){
	x=_x;
	y=_y;
	length=_length;
	width=_width;
}

void Rectangle::draw(){
	printf("���ϽǶ������꣺(%d,%d),����%d,��%d\n",x,y,length,width);
}
