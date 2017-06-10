#ifndef _TIME_MANAGER_H_
#define _TIME_MANAGER_H_

#include <vector>

class TimeManager
{
public:
	void timeIncreased();

	int getTime();

	bool JudgeTimeArray(std::vector<long long> times);

	bool JudgeTime(long long time);

	static TimeManager* getInstance();
private:
	static TimeManager* instance;

	long long tot_time = 0;
};
#endif // !_TIME_MANAGER_H_

