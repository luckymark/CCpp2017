#ifndef FAN_H
#define FAN_H
#include "Device.h"
#include <cstring>

class Fan:public Device{
	private:
		bool isOn;
		char identification[10];
		
	public:
		Fan(char _identification[]);
		virtual void show();
};
#endif
