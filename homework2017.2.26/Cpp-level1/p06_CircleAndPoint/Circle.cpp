#include <cstdio>
#include "Circle.h"
#include "Point.h"

Circle::Circle(){
	r=0;
	xy.changeXY(0,0);
}

Circle::Circle(double _x,double _y,double _r){
	r=_r;
	xy.changeXY(_x,_y);
}

Circle::Circle(Point _xy,double _r){
	xy=_xy;
	r=_r;
}

double Circle::gitX(){
	return xy.gitX();
}

double Circle::gitY(){
	return xy.gitY();
}

double Circle::gitR(){
	return r;
}

void Circle::changeXYR(double _x,double _y,double _r){
	xy.changeXY(_x,_y);
	r=_r;
}

void Circle::move(double _x,double _y){
	xy.changeXY(xy.gitX()+_x,xy.gitY()+_y);
}

void Circle::show(){
	xy.show();
	printf("r=%.2lf\n",r);
}

void Circle::extend(double _r){
	r+=_r;
}
