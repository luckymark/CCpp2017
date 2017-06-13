#include "TimeManager.h"

TimeManager* TimeManager::instance = new TimeManager;

TimeManager* TimeManager::getInstance()
{
	return instance;
}
void TimeManager::timeIncreased()
{
	tot_time++;
}

int TimeManager::getTime()
{
	return this->tot_time;
}

bool TimeManager::JudgeTimeArray(std::vector<long double> times)
{
	for (int i = 0; i < times.size(); i++)
	{
		if (getTime()  == (long long)(times[i] * 60))
		{
			return true;
		}
	}
	return false;
}

bool TimeManager::JudgeTime(long long time)
{
	return time*60 == getTime();
}
