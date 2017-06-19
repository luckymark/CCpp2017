#ifndef RECT_H
#define RECT_H
#include "Shape.h"
class Rect:public Shape
{
	public:
		Rect(double X, double Y, double L, double H){
			x = X;
			y = Y;
			length = L;
			height = H;
		}
		void show();
	protected:
		double x, y, length, height;
};

#endif
