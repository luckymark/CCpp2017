#include"Circle.h"
Circle::Circle(void) :Shape()
{
	std::cout << "please input the raduis: ";
	std::cin >> raduis;
}

void Circle::setCircle(void)
{
	std::cout << "please input new value of raduis: ";
	std::cin >> raduis;
}

void Circle::show(void)
{
	std::cout << "Circle: x: " << x << " y: " << y << " raduis: " << raduis << std::endl;
}