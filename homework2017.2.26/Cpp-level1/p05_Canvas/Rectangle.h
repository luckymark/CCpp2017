#include "Shape.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H
class Rectangle:public Shape{
	public:
		int x,y,length,width;
		Rectangle(int _x,int _y,int _length,int _width);
		virtual void draw();
};
#endif
