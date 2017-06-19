#ifndef POINT_H
#define POINT_H
#include<iostream>
using namespace std;
class Point
{
	public:
		Point(double x, double y){
			this->x = x;
			this->y = y;
		}
		Point(){};
		void move(double X, double Y){
			x += X;
			y += Y;
		}
		void show(){
			cout<<x<<' '<<y<<' ';
		}
	protected:
		double x;
		double y;
};

#endif
