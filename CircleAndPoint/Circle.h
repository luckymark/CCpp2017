#include "Point.h"

class Circle{
	private:
		Point p;
		int r;
	public:
		Circle(Point p,int r);
		void move(int delta_x,int delta_y);
		void print();
};
