#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
class Circle
{
		Point center;
		int r;
	public:
		Circle(Point p,int R=1);
		Circle(int X,int Y,int R=1);
		void move(int X,int Y);
		void change(int delta);
		friend ostream & operator<<(ostream & os,const Circle & c);
		Circle operator+(Point p);
	protected:
};

#endif
