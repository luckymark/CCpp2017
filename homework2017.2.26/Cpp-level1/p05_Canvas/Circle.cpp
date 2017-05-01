#include <cstdio>
#include "Circle.h"
Circle::Circle(int _x,int _y,int _r){
	x=_x;
	y=_y;
	r=_r;
}

void Circle::draw(){
	printf("Ô²ÐÄ×ø±ê£º(%d,%d),°ë¾¶£º%d\n",x,y,r);
}
