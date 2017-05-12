#include "Rect.h"

Rect::Rect(void) :Shape()
{
	std::cout << "please input the length: ";
	std::cin >> length;
	std::cout << "please input the wide: ";
	std::cin >> wide;
}

void Rect::setRect(void)
{
	std::cout << "please input the new value of length: ";
	std::cin >> length;
	std::cout << "please input the new value of wide: ";
	std::cin >> wide;
}

void Rect::show(void)
{
	std::cout << "Rect: x: " << x << " y: " << y << " length: " << length << " wide: " << wide << std::endl;
}

