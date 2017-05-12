#pragma once
#ifndef Circle_H_
#define Circle_H_
#include<iostream>
#include"Point.h"
class Circle
{
private:
	Point p;
	double radius;
public:
	Circle(double x1 = 0, double y1 = 0, double r1 = 0);
	Circle(Point& rp, double r1);
	void setradius();
	void Move();
	void Show();
};
#endif // !Circle_H_
