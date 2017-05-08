#ifndef CANVAS_H
#define CANVAS_H

#include "Shape.h"

class Canvas
{
    private:
		Shape** shapes;
		int Can,Last
		;
	public:
		Canvas(int Can);
		~Canvas();
		void add(Shape* shape,int tag);
		void draw();
};

#endif // CANVAS_H
