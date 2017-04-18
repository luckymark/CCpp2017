#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

Circle::Circle(Point oo,double rr){
	O=oo;
	R=rr;
}

Circle::Circle(double xx,double yy,double rr){
	O.move(xx,yy);
	R=rr;
}

void Circle::change(double r){
	R+=r;
}

void Circle::move(double xx,double yy){
	O.move(xx,yy);
}

void Circle::show(){
	O.show();
	cout<<"R="<<R<<endl;
}
