#pragma once
#ifndef Lamp_H_
#define Lamp_H_
#include"Device.h"
class Lamp :public Device
{
private:
	int num;
public:
	Lamp();
	virtual void on();
	virtual void off();
};
#endif // !Lamp_H_
