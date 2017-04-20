#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"

class Circle
{
	private:
		Point center;
		
		int r;
		
	public:
		void setCenter(Point p);
		
		Point getCenter();
		
		void setR(int r);
		
		int getR();
		
		void show();
		
		void resize(int r);
		
		void move(int offx,int offy);
		
};
#endif CIRCLE_H
