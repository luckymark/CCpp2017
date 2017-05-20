#ifndef CANVAS_H;
#define CANVAS_H
#include"Shape.h"
class Canvas
{
		int i;
		Shape *data[10];
	public:
		Canvas();
		void add(Shape & item);
		void show();
	protected:
};

#endif
