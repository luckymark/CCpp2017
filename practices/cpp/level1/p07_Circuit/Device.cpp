#include "Device.h"
#include<iostream>
using std::cout;
using std::endl;
Device::Device(){
	condition=0;
}
Fan::Fan(int speed):Device(){
	name="Fan";
	this->speed=speed;
}
Light::Light(int illumination):Device(){
	name="Light";
	this->illumination=illumination;
}
void Fan::show(){
	cout<<name;
	if(condition){
		cout<<": on ";
		cout<<"speed: "<<speed<<endl;
	}
	else{
		cout<<": off ";
		cout<<"speed: 0\n";
	}
	
}
void Light::show(){
	cout<<name;
	if(condition){
		cout<<": on ";
		cout<<"illumination: "<<illumination<<endl;
	}
	else{
		cout<<": off ";
		cout<<"illumination: 0\n";
	}
	
}
