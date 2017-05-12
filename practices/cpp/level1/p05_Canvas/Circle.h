#pragma once
#ifndef Circle_H_
#define Circle_H_
#include"Shape.h"
class Circle :public Shape
{
private:
	double raduis;
public:
	Circle(void);
	void setCircle(void);
	virtual void show(void);
};
#endif // !Circle_H_
