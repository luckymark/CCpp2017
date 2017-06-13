#include "Circuit.h"

void Circuit::add(Device *device)
{
	container.push_back(device);
}

void Circuit::on()
{
	for(int i = 0;i < container.size(); i++)
	{
		container[i]->on();
	}
}

void Circuit::off()
{
	for(int i = 0;i < container.size(); i++)
	{
		container[i]->off();
	}
}
