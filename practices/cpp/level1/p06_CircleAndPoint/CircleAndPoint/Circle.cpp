#include "Circle.h"
#include <iostream>
using namespace std;

Circle::Circle(int r0)
{
	r=r0;
}
void Circle::draw()
{
	cout<<"r="<<r<<endl;
}
void Circle::resize(int r1)
{
	r=r1;
}
