#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#include<iostream>
using namespace std;
class Circle
{
	public:
		Circle(Point P, double R){
			p = P;
			r = R;
		}
		void move(double X, double Y){
			p.move(X, Y);
		}
		void show(){
			p.show();
			cout <<' ' << r <<endl;
		}
	protected:
		Point p;
		double r;
};

#endif
