#pragma once
#ifndef Shape_H_
#define Shape_H_
#include<iostream>

class Shape
{
protected:
	double x;
	double y;
public:
	Shape(void);
	void Move();
	virtual void show(void) = 0;
	virtual ~Shape() {};
};
#endif // !Shape_H_
