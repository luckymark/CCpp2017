#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
class Circle{
private:
	Point O;
	double R;
public:
	Circle(Point oo,double rr);
	Circle(double xx,double yy,double rr);
	void change(double r);
	void move(double dx,double dy);
	void show();
};

#endif
