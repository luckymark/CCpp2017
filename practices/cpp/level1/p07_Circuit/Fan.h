#ifndef FAN_H
#define FAN_H
#include "Device.h"
class Fan:public Device
{
	private:
		int rotate_speed;
		
	public:
		void setRotateSpeed(int speed);
		
		void on();
		
		void off();
};
#endif 
