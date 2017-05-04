#ifndef CIRCUIT_H
#define CIRCUIT_H
#include <vector>
#include "Device.h"
using namespace std;
class Circuit
{
	private:
		vector<Device* > container;
	
	public:
		void add(Device *device);
		
		void on();
		
		void off();
};
#endif
