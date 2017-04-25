#ifndef _SHAPE_H_
#define _SHAPE_H_

class Shape{
	private:
		int x,y;
	public:
		Shape(int x,int y);
		~Shape(){}
		void drawPoint();
};
#endif
