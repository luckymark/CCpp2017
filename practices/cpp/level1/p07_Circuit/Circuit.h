#pragma once
#ifndef Circuit_H_
#define Circuit_H_
#include"Device.h"


class Circuit {
private:
	Device * arr[10];
public:
	Circuit();
	void add(Device &ptr);
	void on();
	void off();
};
#endif // !Circle_H_
