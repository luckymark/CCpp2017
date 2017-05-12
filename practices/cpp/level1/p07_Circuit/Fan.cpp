#include "Fan.h"
int Device::number;
Fan::Fan()
{
	number++;
	int num = number;
}

void Fan::on()
{
	std::cout << "Fan "<<num<<" on" << std::endl;
}

void Fan::off()
{
	std::cout << "Fan "<<num<<" off" << std::endl;
}
