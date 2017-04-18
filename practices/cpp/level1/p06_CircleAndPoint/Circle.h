#ifndef CIRCLE_H_DEFINDED
#define CIRCLE_H_DEFINDED
#include "Point.h"
class Circle{
		private:
				Point p;
				double r;
		public:
				Circle(Point p = Point(), double r = 0.0):p(p),r(r){}
				Circle(double x, double y, double r);
				void move(Point x);
				void show();

};

#endif
