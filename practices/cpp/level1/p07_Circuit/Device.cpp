#include "Device.h"

void Device::on()
{
	this->status = 1;
}

void Device::off()
{
	this->status = 0;
}
