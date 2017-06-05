// c++ level1 7.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class Device
{
public:
	virtual void on() = 0;
	virtual void off() = 0;
};

class Circuit
{
private:
	Device *device[100];
	int index=0;
public:
	void add(Device* device)
	{
		this->device[index] = device;
		index++;
	}
	void on()
	{
		for (int i = 0; i < index; i++)
		{
			device[i]->on();
		}
	}

	void off()
	{
		for (int i = 0; i < index; i++)
		{
			device[i]->off();
		}
	}

};


class Fan :public Device
{
public:
	
	void on()
	{	
		cout << "fan ran" << endl;		
	}
	void off()
	{
		cout << "fan close" << endl;
	}
};
class Light:public Device
{
public:
	void on()
	{		
		cout << "light ran" << endl;		
	}
	void off()
	{
		cout << "light close" << endl;
	}
};

int main()
{
	Circuit circuit;
	Fan fan;
	Light light;
	circuit.add(&fan);
	circuit.add(&light);
	circuit.on();
	circuit.off();
    return 0;
}

