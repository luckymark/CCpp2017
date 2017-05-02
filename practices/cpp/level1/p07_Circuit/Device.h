#ifndef DEVICE_H
#define DEVICE_H
#include<iostream>
class Device
{
	public:
		Device();
		virtual void on(){;};
		virtual void off(){;};
		virtual void show(){;};
	protected:
		std::string name;
		bool condition;
};
class Fan:public Device
{
		int speed;
	public:
		Fan(int speed=10);
		virtual void on(){condition=1;};
		virtual void off(){condition=0;};
		virtual void show();
		
};
class Light:public Device
{
		int illumination;
	public:
		Light(int illumination=1);
		virtual void on(){condition=1;};
		virtual void off(){condition=0;};
		virtual void show();
};

#endif
