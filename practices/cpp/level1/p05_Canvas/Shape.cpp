#include "Shape.h"
Shape::Shape(void)
{
	x = 0;
	y = 0;
}

void Shape::Move()
{
	std::cout << "please input new x-val: ";
	std::cin >> x;
	std::cout << "please input new y-val: ";
	std::cin >> y;
}
