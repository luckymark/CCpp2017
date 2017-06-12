#ifndef PARALLELTASK_H_
#define PARALLELTASK_H_

#include"YOUneedTHIS.h"

class ParallelTask
{
	public:
		ParallelTask();
		void execute();
		bool isFinished();
		float getCompletion();

	private:
		void runTask();

	private:
		sf::Thread			mThread;
		bool				mFinished;
		sf::Clock			mElapsedTime;
		sf::Mutex			mMutex;
};

#endif // PARALLELTASK_H_
