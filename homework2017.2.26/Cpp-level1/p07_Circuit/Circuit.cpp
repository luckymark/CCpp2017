#include "Circuit.h"
#include <cstdio>
#include "Device.h"

Circuit::Circuit(){
	for (int i=0;i<100;i++){
		device[i]=NULL;
	}
}

void Circuit::add(Device* _device){
	for (int i=0;i<100;i++){
		if (device[i]==NULL){
			device[i]=_device;
			return;
		}
	}
	printf("设备已满，无法添加\n");
}

void Circuit::del(int index){
	device[index]=NULL;
}

void Circuit::turnOnAll(){
	for (int i=0;i<100;i++){
		if (device[i]!=NULL){
			device[i]->turnOn();
		}
	}
}

void Circuit::turnOn(int index){
	if (device[index]!=NULL){
		device[index]->turnOn();
	}
	else {
		printf("该设备不存在"); 
	}
}

void Circuit::turnOffAll(){
	for (int i=0;i<100;i++){
		if (device[i]!=NULL){
			device[i]->turnOff();
		}
	}
}

void Circuit::turnOff(int index){
	if (device[index]!=NULL){
		device[index]->turnOff();
	}
	else {
		printf("该设备不存在"); 
	}
}

void Circuit::showAll(){
	for (int i=0;i<100;i++){
		if (device[i]!=NULL){
			printf("设备%d：",i);
			device[i]->show();
		}
		else {
			printf("设备%d：空\n",i);
		}
	}
}

void Circuit::showOn(){
	for (int i=0;i<100;i++){
		if (device[i]!=NULL){
			if(device[i]->gitStatus()==true){
				printf("设备%d：",i);
				device[i]->show();			
			}
		}
	}
}
