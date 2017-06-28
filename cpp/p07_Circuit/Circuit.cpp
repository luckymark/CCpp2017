#include"Circuit.h"
#include<iostream>

using namespace std;

void Circuit::AddUnit(int unit,int slot)
{
	switch (unit)
	{
	case 0:
		pt[slot] = new Light(unit,slot);
		count++;
		break;
	case 1:
		pt[slot] = new Motor(unit,slot);
		count++;
		break;
	}
	
}

void Circuit::show()
{
	for (int i = 0; i < count; i++)
	{

	}
}

void Unit::TurnSwitch(bool isOn)
{
	Switch = isOn;
}

int Unit::isON()
{
	return Switch == 1;
}

void Light::ChangeType(int type)
{
	this->type = type;
}

void Light::show()
{
	cout << "light type: " << type << endl;
	switch (type)
	{
	case 1:
		cout << "10W" << endl;
		break;
	case 2:
		cout << "20W" << endl;
	}

	

	switch (isON())
	{
	case 1:
		cout << " is on" << endl;
		break;
	case 0:
		cout << " is off" << endl;
	}
}

void Motor::ChangeType(int n)
{
	type = n;
}

void Motor::show()
{
	cout << "motor type: " << type << endl;
	switch (type)
	{
	case 1:
		cout << "1000r" << endl;
		break;
	case 2:
		cout << "2000r" << endl;
	}
}
