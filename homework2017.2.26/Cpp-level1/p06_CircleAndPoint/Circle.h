#include "Point.h"
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle{
	private:
		Point xy;
		double r;
	
	public:
		Circle();
		Circle(Point _xy,double _r);
		Circle(double _x,double _y,double _r);
		double gitX();
		double gitY();
		double gitR();
		void changeXYR(double _x,double _y,double _r);
		void move(double _x,double _y);
		void extend(double _r);
		void show();
};
#endif

