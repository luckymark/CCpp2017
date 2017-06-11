#include "../include/Cell.h"

Switch::Switch()
{
	isPassable = 0;
	isSwitch = 1;
}
void Switch::turnon()
{
	this->isPassable = 1;
}
void Switch::turnoff()
{
	this->isPassable = 0;
}

Fan::Fan()
{
	isPassable = 1;
	rotateSpeed = 10;
	isSwitch = 0;
}
void Fan::turnon(){
	isPassable = 1;
}
void Fan::turnoff(){
	isPassable = 0;
}

Bulb::Bulb()
{
	isPassable = 1;
	light = 10;
	isSwitch = 0;
}

void Bulb::turnon(){
	isPassable = 1;
}
void Bulb::turnoff(){
	isPassable = 0;
}
