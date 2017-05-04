#ifndef DEVICE_H
#define DEVICE_H

class Device{
	private:
		bool isOn;
	
	public:
		Device();
		bool gitStatus();
		void turnOn();
		void turnOff();
		virtual void show(){};
};
#endif
