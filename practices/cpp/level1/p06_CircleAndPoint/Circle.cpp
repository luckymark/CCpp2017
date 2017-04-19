#include <iostream>
#include "Circle.h"
using namespace std;
Circle::Circle(double x_, double y_, double r_){
	p = Point(x_,y_);
	r = r_;
}
void Circle::move(Point x){
	p = p + x;
}
void Circle::show(){
	p.show();
	cout << r << endl;
}
