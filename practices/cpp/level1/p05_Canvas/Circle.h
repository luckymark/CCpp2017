#ifndef CIRCLE_H
#define CIRCLE_H
#include "Shape.h"
class Circle:public Shape
{
	public:
		//Circle(double X=0, double Y=0, double R=0):x(X), y(Y), r(R){}
		Circle(double X=0, double Y=0, double R=0){
			x = X;
			y = Y;
			r = R;
		}
		void show();
	protected:
		double x, y, r;
};

#endif
