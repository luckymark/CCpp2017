#ifndef	CIRCUIT_H
#define CIRCUIT_H

#include "Device.h"

class Circuit{
	private:
		Device* device[100];
	
	public:
		Circuit();
		void add(Device* _device);
		void del(int index);
		void turnOnAll();
		void turnOn(int index);
		void turnOffAll();
		void turnOff(int index);
		void showAll();
		void showOn();
};

#endif
