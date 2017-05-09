#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"
#define PI 3.14159
class Circle {
private:
	Point center;
	double radius;
public:
	Circle(Point p, double R);
	void resize(int a);
	double area(); 
	void Circle::showCircle(void);
	void move(int OFFX, int OFFY);
protected:
};
#endif