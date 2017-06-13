#include "Lamp.h"
#include <iostream>
using namespace std;

void Lamp::setLightness(int lightness)
{
	this->lightness = lightness;
}

void Lamp::on()
{
	cout<<"Lamp is on"<<endl;
}

void Lamp::off()
{
	cout<<"Lamp is off"<<endl;
}
