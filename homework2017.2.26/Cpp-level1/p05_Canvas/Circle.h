#include "Shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H
class Circle:public Shape{
	public:
		int x,y,r;
		Circle(int _x,int _y,int _r);
		virtual void draw();
};
#endif
