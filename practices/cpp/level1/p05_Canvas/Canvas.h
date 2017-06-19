#ifndef CANVAS_H
#define CANVAS_H
#include <list>
#include "Shape.h"
using namespace std;
class Canvas
{
	public:
		list<Shape*> canvas;
		void add(Shape*);
		void draw();
	protected:
		list<Shape*>::iterator i;
};

#endif
