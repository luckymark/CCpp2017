#include "Shape.h"

class Circle: public Shape{
	private:
		int r;
	public:
		Circle(int r,int x,int y);
		~Circle();
		virtual void draw();
};
