#pragma once
#ifndef Rect_H_
#define Rect_H_
#include"Shape.h"
class Rect :public Shape
{
private:
	double length;
	double wide;
public:
	Rect(void);
	void setRect(void);
	virtual void show(void);
};
#endif // !Rect_H_
