#include "Shape.h"
#ifndef CANVAS_H
#define CANVAS_H
class Canvas{
	private:
		int length,width,number;
		Shape* shape[1000];
	
	public:
		Canvas();
		void draw();
		void addCircle(int x,int y,int r);
		void addRectangle(int x,int y,int _length,int _width);
		void addTriangle(int x1,int y1,int x2,int y2,int x3,int y3);
		void delCircle(int x,int y,int r);
		void delRectangle(int x,int y,int _length,int _width);
		void delTriangle(int x1,int y1,int x2,int y2,int x3,int y3);
};
#endif
