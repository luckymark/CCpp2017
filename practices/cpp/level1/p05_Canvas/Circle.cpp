#include "Canvas.h"

void Circle::show(){
	cout << "This is a Circle." << endl;
	cout << "center: " << c.x << " " << c.y << endl;
	cout << "Ratio: " << r << endl;
}

void Circle::move(Point x){
	c = c + x;
}

double Circle::area(){
	return r * r * pi;
}
