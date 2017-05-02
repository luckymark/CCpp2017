#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		int x,y,r;
		Point(int x0,int y0);
		void draw();
		void move(int x1,int y1);
	protected:
};

#endif
