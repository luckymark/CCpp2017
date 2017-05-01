#include "Shape.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H
class Triangle:public Shape{
	public:
		int x1,x2,x3,y1,y2,y3;
		Triangle(int _x1,int _y1,int _x2,int _y2,int _x3,int _y3);
		virtual void draw();
};
#endif
