#include "Shape.h"

class Rect: public Shape{
	private:
		int lenx,leny;
	public:
		Rect(int lenx,int leny,int x,int y);
		~Rect();
		virtual void draw();
};
