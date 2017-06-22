#pragma once
#include<bits/stdc++.h>
using namespace std;
#ifndef CANVAS_H_
#define CANVAS_H_

class point {
private:
	int x, y;
public:
	point(int x = 0, int y = 0);
	void move(int x, int y);
	pair<int, int> getPos();
	~point() {}
};
class Circle {
private:
	int radius;
	point pt;
public:
	Circle(int r, int x = 0, int y = 0);
	~Circle() {}
	void show();
	void move(int x, int y);
};
#endif