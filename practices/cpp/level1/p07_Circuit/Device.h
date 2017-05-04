#pragma once
#ifndef Device_H_
#define Device_H_
#include<iostream>
class Device {
protected:
	static int number;
public:
	virtual void on() {};
	virtual void off() {};
	virtual ~Device()=0 {};
};
#endif // !Device_H_
