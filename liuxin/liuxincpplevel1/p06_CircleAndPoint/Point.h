#ifndef POINT_H
#define POINT_H

class Point{
private:
	double x,y;
public:
	Point(double xx=0,double yy=0);
	void move(double dx,double dy);
	void show();
};

#endif
