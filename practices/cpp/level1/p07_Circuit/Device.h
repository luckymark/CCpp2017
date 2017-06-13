#ifndef DEVICE_H
#define DEVICE_H

class Device
{	
	public:
		virtual void on() = 0;
		
		virtual void off() = 0;	
};
#endif 
