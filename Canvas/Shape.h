#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape{
	protected:
		int x,y;
	public:
		Shape(int x,int y);
		~Shape(){}
		virtual void draw() = 0;
};
#endif
