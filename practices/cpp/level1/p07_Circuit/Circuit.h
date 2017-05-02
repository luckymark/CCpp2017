#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Device.h"
class Circuit
{	
		Device *device[10];
		bool condition;
		int index;
	public:
		Circuit();
		void add(Device * item);
		void on();
		void off();
		void disp();
	protected:
};

#endif
