#include<iostream>
#include"Shape.h"

void main()
{
	Shape* pt[2];

	Circle c(5, 5, 2);
	pt[0] = &c;
	pt[0]->change();
	pt[0]->move(8, 7);
	pt[0]->show();

	Rect r(5, 5, 6, 10);
	pt[1] = &r;
	pt[1]->change();
	pt[1]->move(6, 7);
	pt[1]->show();

} 