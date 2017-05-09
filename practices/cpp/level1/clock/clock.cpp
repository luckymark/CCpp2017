#include <cstdio>

#include "clock.h"

void Clock::set_time(int h, int m, int s)
{
    this->h = h;
    this->m = m;
    this->s = s;
}

void Clock::disp_time()
{
    printf("%d:%d:%d\n", this->h, this->m, this->s);
}


void Alarm_clock::set_alarm(int h, int m, int s)
{
    this->alarm_h = h;
    this->alarm_m = m;
    this->alarm_s = s;
}