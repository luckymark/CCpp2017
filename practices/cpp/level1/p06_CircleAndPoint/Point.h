#pragma once
#ifndef Point_H_
#define Point_H_
#include<iostream>
class Point 
{
private:
	double x;
	double y;
public:
	Point(double x1 = 0, double y1 = 0);
	void Move();
	void Show() const;
};
#endif // !Point_H_
