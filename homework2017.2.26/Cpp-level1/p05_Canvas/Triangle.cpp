#include <cstdio>
#include "Triangle.h"

Triangle::Triangle(int _x1,int _y1,int _x2,int _y2,int _x3,int _y3){
	x1=_x1;
	x2=_x2;
	x3=_x3;
	y1=_y1;
	y2=_y2;
	y3=_y3;
}

void Triangle::draw(){
	printf("三个顶点坐标：(%d,%d),(%d,%d),(%d,%d)\n",x1,y1,x2,y2,x3,y3);
}
