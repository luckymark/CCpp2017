#include"Clock.h"
#include<iostream>
#include<time.h>
#include<Windows.h>

void Clock::SetTime(int h, int m,int s)
{
	this->h = h;
	this->m = m;
	this->s = s;
}

void Clock::operate()
{


	using namespace std;

	time_t t1, t2;
	t1 = clock();

	int ds, dm, dh;
	time_t delta_t;

	while (1)
	{
		Sleep(500);
		t2 = clock();

		delta_t = (t2 - t1) / CLOCKS_PER_SEC;
		
		ps = (s + delta_t) % 60;
		pm = ((s + delta_t) / 60 + m) % 60;
		ph = ((((s + delta_t) / 60) + m) / 60 + h) % 24;

		to_xy(10, 10);

		cout.width(2);
		cout << ph << ":";
		cout.width(2); 
		cout << pm << ":";
		cout.width(2); 
		cout<< ps;

		

	}
}

void AlarmClock::SetAlarm(int h, int m, int s, bool alarm)
{
	ah = h;
	am = m;
	as = s;
	this->alarm = alarm;
}
void AlarmClock::Alarm()
{
	if ((ah == h&&am == m&&as == s) && alarm == true)
	{
		puts("AAAAAAAA");
	}
}

void to_xy(int x, int y)												//到指定坐标
{
	HANDLE hout;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}