#include "Shape.h"

class Point: public Shape{
	public:
		Point(int x,int y);
		~Point();
		virtual void draw();
};
