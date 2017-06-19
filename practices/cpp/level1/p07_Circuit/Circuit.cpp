#include "Circuit.h"


Circuit::Circuit()
{

}

void Circuit::Add()
{
	cout << "Please choose a device add into the circuit:" << endl;
	cout << "1.Bulb\n2.Fan" << endl;
	Bulb* bulb = new Bulb;
	Fan* fan = new Fan;

	int x=0;
	cin >> x;
	switch (x)
	{
	case 1:

		cout << "Now you add a bulb into the circuit." << endl;
		Items.push_back(bulb);
		break;
	case 2:
		cout << "Now you add a fan into the circuit." << endl;
		Items.push_back(fan);
		break;
	default:
		break;
	}
	
}

void Circuit::Delete()
{
	auto it = Items.begin();
	/*for (; it != Items.end(); it++)
	{
		if (*it == b)
		{
			it = Items.erase(it);
		}
	}*/
	cout << "Please choose a device to delete from the circuit:" << endl;
	cout << "1.Bulb\n2.Fan" << endl;
	int x=0;
	cin >> x;
	switch (x)
	{
	case 1:
		for (; it != Items.end(); it++)
		{
			if ( ((*it))->character == 1)
			{
				it = Items.erase(it);
			}
		}
		cout << "Now you delete a bulb into the circuit." << endl;
		break;
	case 2:
		for (; it != Items.end(); it++)
		{
			if (((*it))->character == 2)
			{
				it = Items.erase(it);
			}
		}
		cout << "Now you delete a fan into the circuit." << endl;
		break;
	default:
		break;
	}
}

void Circuit::Show()
{
	cout << "The circuit has "<<Items.size()<<" devices." << endl;
}

void Circuit::Menu()
{
	cout << "Please tell me what you want to do:" << endl;
	cout << "1.Add a device" << endl;
	cout << "2.Delete a device" << endl;
	cout << "3.Show the circuit" << endl;
	int x=0;
	cin >> x;
	switch (x)
	{
	case 1:
		Add();
		break;
	case 2:
		Delete();
		break;
	case 3:
		Show();
		break;
	default:
		break;

	}
}

void Device::ON()
{
	cout << "This deveice is ON now." << endl;
	judge = 1;
}

void Device::OFF()
{
	cout << "This device is OFF now" << endl;
	judge = 0;
}

void Bulb::Show()
{
	cout << "The bulb's intence is 100" << endl;
}

Bulb::~Bulb()
{
}

void Fan::Show()
{
	cout << "The fan's speed is 100." << endl;
}

Fan::~Fan()
{ 
}
