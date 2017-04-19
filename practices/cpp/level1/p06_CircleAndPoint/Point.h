#ifndef POINT_H_DEFINEDED
#define POINT_H_DEFINEDED
#include <iostream>
using namespace std;
class Point{
	private :
		double x,y;
	public:
		Point(double x = 0.0, double y = 0.0):x(x),y(y){}
		friend Point operator + (const Point &a, const Point &b){ return Point(a.x + b.x, a.y + b.y);} 
		friend Point operator - (const Point &a, const Point &b){ return Point(a.x - b.x, a.y - b.y);} 
		friend Point operator * (const Point &a, double b){ return Point(a.x * b, a.y * b);} 
		friend Point operator / (const Point &a, double b){ return Point(a.x / b, a.y / b);} 
		void show(){
			cout << x << " " << y << endl;
		}
};

#endif
