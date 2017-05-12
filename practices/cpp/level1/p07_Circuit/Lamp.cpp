#include "Lamp.h"
int Device::number = 0;
Lamp::Lamp()
{
	number++;
	num = number;
}

void Lamp::on()
{
	std::cout << "Lamp "<<num<<" on" << std::endl;
}

void Lamp::off()
{
	std::cout << "Lamp "<<num<<" off" << std::endl;
}
