#ifndef LOADINGSTATE_H_
#define LOADINGSTATE_H_

#include "State.h"
#include"YOUneedTHIS.h"

#include "ParallelTask.h"


class LoadingState : public State
{
public:
	LoadingState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

	void setCompletion(float percent);

private:
	sf::Text mLoadingText;
	sf::RectangleShape mProgressBarBackground;
	sf::RectangleShape mProgressBar;

	ParallelTask mLoadingTask;
};

#endif // LOADINGSTATE_H_
