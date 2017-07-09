#ifndef SHAPE_H_
#define SHAPE_H_
#include<iostream>

using namespace std;

class Shape
{
public:
	Shape(int x = 0,int y = 0) { this->x = x; this->y = y; }
	void move(int x, int y);
	virtual void show() = 0;
	virtual void change() = 0;
private:
	int x, y;

};

class Circle : public Shape
{
public:
	void change();
	void show();
	Circle(int x = 0, int y = 0, int r = 0) :Shape(x, y) { this->r = r; }
private:
	char* type = "Circle";
	int r;
};

class Rect : public Shape
{
public:
	void change();
	void show();
	Rect(int x, int y, int a, int b) :Shape(x, y) { this->a = a; this->b = b; }
private:
	char* type = "Rect";
	int a;
	int b;
};

#endif
