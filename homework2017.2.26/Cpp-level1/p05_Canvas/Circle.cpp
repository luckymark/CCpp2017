#include <cstdio>
#include "Circle.h"
Circle::Circle(int _x,int _y,int _r){
	x=_x;
	y=_y;
	r=_r;
}

void Circle::draw(){
	printf("Բ�����꣺(%d,%d),�뾶��%d\n",x,y,r);
}
