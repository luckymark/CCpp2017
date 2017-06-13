#ifndef RECT_H
#define RECT_H

#include "Graphics.h"

class Rect: public Graphics
{
	private:
		int height, width;
			
	public:
		Rect();
		
		void setHeight(int height);
		
		int getHeight();
		
		void setWidth(int width);
		
		int getWidth();			
			
		void showParams();
		
};
#endif RECT_H
