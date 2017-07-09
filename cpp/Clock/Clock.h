#ifndef CLOCK_H_
#define CLOCK_H_

class Clock
{
private:
	int h, m, s;	//初始时间
	int ps, pm, ph;	//当前时间
public:
	friend class AlarmClock;
	Clock(int h, int m, int s) { this->h = h; this->m = m; this->s = s; ps = s; pm = m; ph = h; }
	void SetTime(int h, int m,int s);
	void operate();
};

class AlarmClock :public Clock
{
private:
	int ah;
	int am;
	int as;
	bool alarm;
	
public:
	friend class Clock;
	AlarmClock(int h, int m, int s) :Clock(h, m, s) { alarm = false; }
	void SetAlarm(int h, int m, int s,bool alarm);
	void Alarm();
};

void to_xy(int x, int y);

#endif
