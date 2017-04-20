#include <iostream>
#include "Circle.h"
#include "Point.h"

int main(int argc, char** argv) {
	Circle circle;
	Point point;
	point.setX(2);
	point.setY(2);
	circle.setCenter(point);
	circle.setR(1);
	circle.show();
	
	circle.move(3,3);
	circle.show();
	
	circle.resize(2);
	circle.show();
	return 0;
}
