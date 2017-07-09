#include<iostream>
#include"Clock.h"


void main()
{
	AlarmClock aclock(11, 8, 20);
	aclock.SetAlarm(12, 0, 0, 0);
	aclock.operate();
}