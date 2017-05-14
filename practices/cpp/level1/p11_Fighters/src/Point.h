#ifndef POINT_H_
#define POINT_H_

struct Point{
	float x,y;
	Point(float x = 0.0, float y = 0.0):x(x),y(y){};
	friend Point operator + (const Point &a, const Point &b){ return Point(a.x+b.x, a.y+b.y);}
	friend Point operator - (const Point &a, const Point &b){ return Point(a.x-b.x, a.y-b.y);}
	friend Point operator * (const Point &a, float b){ return Point(a.x*b, a.y*b);}
	friend Point operator / (const Point &a, float b){ return Point(a.x/b, a.y/b);}
};

#endif
