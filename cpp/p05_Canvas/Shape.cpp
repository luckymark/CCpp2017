#include"Shape.h"

void Shape::show()
{
	cout << "location:" << x << " " << y << endl;
}

void Shape::move(int x , int y)
{
	this-> x= x;
	this-> y = y;
}
void Circle::show()
{
	Shape::show();
	cout << "type:" << type << "  r=" << r << endl;
	
}

void Rect::show()
{
	Shape::show();
	cout << "type: " << type << "  a=" << a << "  b=" << b << endl; 
}

void Circle::change()
{
	this->r = 8;
}

void Rect::change()
{
	this->a = 7;
	this->b = 8;
}