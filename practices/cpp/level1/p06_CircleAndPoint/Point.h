#ifndef POINT_H
#define POINT_H
#include<iostream>
using std::ostream;
class Point
{
		
	public:
		int x,y;
		Point(int X=0,int Y=0);
		void move(int X,int Y);
		void move(Point p);
		friend ostream & operator<<(ostream & os,const Point & p);
	protected:
};

#endif
