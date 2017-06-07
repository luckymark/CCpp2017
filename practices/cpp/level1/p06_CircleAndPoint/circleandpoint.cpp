/*
题目：Circle & Point

功能要求：

实现Point类
利用组合Point实现Circle类
通过移动圆心，来实现圆的移动
*/
#include<iostream>
using namespace std;

class Point{
	private:
		double x;
		double y;
	public:
	    Point();
		Point(double,double);
		Point(const Point&);
		void move(double,double);
};

Point::Point(){
    x=0;
    y=0;
}

Point::Point(double a,double b){
	x=a;
	y=b;
}

Point::Point(const Point& p){
    x=p.x;
    y=p.y;
}

void Point::move(double a,double b){
	this->x+=a;
	this->y+=b;
}

class Circle{
	private:
		Point centre;
		double radius;
	public:
		Circle(Point,double);
		void move(double,double);
};

Circle::Circle(Point p,double r)
{
	centre=p;
	radius=r;
}


void Circle::move(double a,double b){
	this->centre.move(a,b);
}


int main(){
    Point p(5,5);
    Circle c(p,1);
    c.move(2,3);
	return 0;
}
