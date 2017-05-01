#include <cstdio>
#include "Rectangle.h"

Rectangle::Rectangle(int _x,int _y,int _length,int _width){
	x=_x;
	y=_y;
	length=_length;
	width=_width;
}

void Rectangle::draw(){
	printf("左上角顶点坐标：(%d,%d),长：%d,宽：%d\n",x,y,length,width);
}
