#include "Fan.h"
#include <iostream>
using namespace std;

void Fan::setRotateSpeed(int speed)
{
	this->rotate_speed = speed;
}

void Fan::on()
{
	cout<<"Fan is on"<<endl;
}

void Fan::off()
{
	cout<<"Fan is off"<<endl;
}
