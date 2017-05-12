#include "Circuit.h"

Circuit::Circuit()
{
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = NULL;
	}
}

void Circuit::add(Device & ptr)
{
	int i = 0;
	while (i < 10)
	{
		if (arr[i] == NULL)
		{
			arr[i] = &ptr;
			break;
		}
		i = i + 1;
	}
}

void Circuit::on()
{
	int i = 0;
	while (i<10)
	{
		if (arr[i] != NULL)
		{
			arr[i]->on();
		}
		i = i + 1;
	}
}

void Circuit::off()
{
	int i = 0;
	while (i<10)
	{
		if (arr[i] != NULL)
		{
			arr[i]->off();
		}
		i = i + 1;
	}
}
