#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect()
{
	height = width = 0;
}

void Rect::setHeight(int height)
{
	this->height = height;
}

int Rect::getHeight()
{
	return height;
}

void Rect::setWidth(int width)
{
	this->width = width;
}

int Rect::getWidth()
{
	return width;
}

void Rect::showParams()
{
	cout<<"the four corner of the rect is ";
	cout<<"("<<getPoint().getX()<<","<<getPoint().getY()<<")"<<", ";
	cout<<"("<<getPoint().getX()+getWidth()<<","<<getPoint().getY()<<")"<<", ";
	cout<<"("<<getPoint().getX()<<","<<getPoint().getY() + getHeight()<<")"<<", ";
	cout<<"("<<getPoint().getX() + getWidth()<<","<<getPoint().getY() + getHeight()<<")"<<", "<<endl;
}
