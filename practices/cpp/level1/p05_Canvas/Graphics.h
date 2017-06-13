#ifndef GRAPHICS_H
#define GRAPHICS_H
#include "Point.h"

class Graphics
{
	private:
		Point point;
	
	public:
		void setPoint(Point point);
		
		Point getPoint();
		
		virtual void showParams() = 0;
};
#endif GRAPHICS_H
