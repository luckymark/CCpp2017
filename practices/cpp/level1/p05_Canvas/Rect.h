#ifndef RECT_H
#define RECT_H

#include "Shape.h"
class Rect:public Shape
{
    private:
		int x1,y1;
	public:


		Rect(int x1,int y1,int x,int y);
		~Rect();
		virtual void draw();
};

#endif // RECT_H
