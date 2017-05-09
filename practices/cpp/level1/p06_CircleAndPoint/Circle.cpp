#include "Circle.h"
#include "Point.h"
using namespace std;

Circle::Circle(Point p, double R){
	center = p;
	radius = R;
}

void Circle::resize(int a) {
	radius += a;
}

double Circle::area() {
	return PI*radius*radius;
}

void Circle::showCircle(void) {
	cout << "Center of Circle:" << endl;
	center.show();
	cout << "Radius:" << radius << endl;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.precision(2);
	cout << "area:" << area()<< endl;
}

void Circle::move(int OFFX, int OFFY) {
	center.move(OFFX, OFFY);
}