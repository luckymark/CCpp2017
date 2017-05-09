#include "Device.h"

Device::Device(){
	isOn=false;
}

bool Device::gitStatus(){
	return isOn;
}

void Device::turnOn(){
	isOn=true;
}

void Device::turnOff(){
	isOn=false;
}
