
#include "Device.h"
#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	device[100]={0};
	num=0;
	status=0;
}
void Circuit::add(Device* device_0)
{
	device[num]=device_0;
	num++;
}
void Circuit::on()
{
	status=1;
	cout<<"status:"<<status<<" ,"<<"the number of working decive: "<<num<<endl;
}
void Circuit::off()
{
	status=0;
	cout<<"status:"<<status<<" ,"<<"the number of stopped device: "<<num<<endl;
}
