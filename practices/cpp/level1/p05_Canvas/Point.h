#pragma once
#ifndef Point_H_
#define Point_H_
#include"Shape.h"
class Point :public Shape
{
public:
	Point(void);
	virtual void show(void);
};
#endif // !Shape_H_