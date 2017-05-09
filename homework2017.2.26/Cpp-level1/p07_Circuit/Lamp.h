#ifndef LAMP_H
#define LAMP_H
#include "Device.h"
#include <cstring>

class Lamp:public Device{
	private:
		bool isOn;
		char identification[10];
		
	public:
		Lamp(char _identification[]);
		virtual void show();
};
#endif
