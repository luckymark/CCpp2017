#include "Canvas.h"


Canvas::Canvas(void)
{
	length = 0;
	wide = 0;
	Shape * arr[10] = { NULL,NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
}
void Canvas::setShape(int i)
{
	char ch;
	std::cout << "p for point,c for circle,r for rect:";
	std::cin >> ch;
	switch (ch)
	{
	case 'p': arr[i] = new Point; break;
	case 'c': arr[i] = new Circle; break;
	case 'r': arr[i] = new Rect; break;
	default:
		std::cout << "error,please input choose again" << std::endl;
		Canvas::setShape(i);
	}
}

void Canvas::show(void)
{
	for (int i = 0; i < 10; i++)
	{
		arr[i]->show();
	}
}

std::istream & operator>>(std::istream & is, Canvas & a)
{
	std::cout << "please input the length: ";
	is >> a.length;
	std::cout << "please input the wide: ";
	is >> a.wide;
	return is;
	// TODO: insert return statement here
}

std::ostream & operator<<(std::ostream & os, Canvas & a)
{
	os << "the canvas' length is " << a.length << ",the canvas' wide is " << a.wide << std::endl;
	return os;
	// TODO: insert return statement here
}

