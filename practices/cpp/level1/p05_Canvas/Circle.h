#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "Graphics.h"

class Circle: public Graphics
{
	private:
		
		int r;
		
	public:
		Circle();
		
		void setR(int r);
		
		int getR();
		
		void showParams();
};

#endif
