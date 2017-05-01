#include "Point.h"
using namespace std;

Point::Point(int X = 0, int Y = 0) {
	this->X = X, this->Y = Y;
}

void Point::move(int OffX, int OffY) {
	X += OffX;
	Y += OffY;
}

void Point::show(void) {
	cout << "(" << X << "," << Y << ")" << endl;
}
