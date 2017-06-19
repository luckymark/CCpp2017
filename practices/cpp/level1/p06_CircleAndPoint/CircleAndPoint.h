#pragma once
#include <iostream>
using namespace std;


class Point
{
private:

public:
	int		x = 0;
	int		y = 0;
};

class Circle
{
private:
	Point		point;
public:
	void		move();
	void		show();
};
