#ifndef LAMP_H
#define LAMP_H
#include "Device.h"

class Lamp:public Device
{
	private:
		int lightness;
		
	public:
		void setLightness(int lightness);	
		
		void on();
		
		void off();
};
#endif
