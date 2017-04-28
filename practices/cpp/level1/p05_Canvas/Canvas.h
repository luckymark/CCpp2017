#ifndef CANVAS_H_
#define CANVAS_H_

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
static const double pi = cos(-1);

struct Point{
	double x,y;
	Point(double x = 0.0, double y = 0.0):x(x),y(y){}
	friend Point operator + (const Point &a, const Point &b){
		return Point(a.x + b.x, a.y + b.y);
	}
	friend Point operator - (const Point &a, const Point &b){
		return Point(a.x - b.x, a.y - b.y);
	}
	double det(Point b){
		return x*b.y - y*b.x;
	}
};

class Shape{
	public:
		virtual void show(){}
		virtual void move(Point x){}
		virtual double area(){return 0;}
		virtual ~Shape(){}
};

class Circle: public Shape{
	private:
		Point c;
		double r;
	public:
		Circle(Point a, double R){
			c = a;
			r = R;
		}
		virtual void show();
		virtual double area();
		virtual void move(Point x);
		~Circle(){}
};

class Rect: public Shape{
	private:
		Point u_l, d_r;
	public:
		Rect(Point a, Point b){
			u_l = a;
			d_r = b;
		}
		virtual void show();
		virtual double area();
		virtual void move(Point x);
		~Rect(){}
};

class Tri: public Shape{
	private:
		Point p[3];
	public:
		Tri(Point a, Point b, Point c){
			p[0] = a;
			p[1] = b;
			p[2] = c;
		}
		virtual void show();
		virtual double area();
		virtual void move(Point x);
		~Tri(){}
};

class Canvas{
	private:
		Shape *p[100];
		int cnt;
	public:
		Canvas(){
			memset(p,0,sizeof(p));
			cnt = 0;
		}
		void creat_circle(Point x, double r);
		void creat_rect(Point a, Point b);
		void creat_tri(Point a,Point b,Point c);
		void move(int whe,Point del);
		void show();
		void show(int whe);
		~Canvas();
};
#endif
