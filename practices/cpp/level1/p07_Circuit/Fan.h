#pragma once
#ifndef Fan_H_
#define Fan_H_
#include"Device.h"
class Fan:public Device
{
private:
	int num;
public:
	Fan();
	virtual void on();
	virtual void off();
};
#endif // !Fan_H_
