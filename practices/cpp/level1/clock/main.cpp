#include <cstdio>

#include "clock.h"

int main()
{
    Alarm_clock alarm_clock;
    alarm_clock.set_time(1, 36, 1);
    alarm_clock.disp_time();
    alarm_clock.set_alarm(1, 37);
    return 0;
}