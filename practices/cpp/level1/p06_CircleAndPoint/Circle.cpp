#include "Circle.h"
#include "Point.h"
#include <iostream>

using namespace std;

Circle::Circle()
{
    //ctor
}

Circle::~Circle()
{
    //dtor
}

void Circle:: SetCenter(Point O)
{
    this->center=O;
}

Point Circle::GetCenter()
{
	return center;
}

void Circle::SetR(int r)
{
	this->r = r;
}

int Circle::GetR()
{
	return r;
}

void Circle::Move(int x,int y)
{
	center.SetX(center.GetX() + x);
	center.SetY(center.GetY() + y);
}

void Circle::ChangeSize(int r)
{
	SetR(r);
}

void Circle::Show()
{
	cout<<"Ô²ÐÄ:"<<"("<<GetCenter().GetX()<<","<<GetCenter().GetY()<<")"<<endl;
	cout<<"°ë¾¶:"<<GetR()<<endl;
}
