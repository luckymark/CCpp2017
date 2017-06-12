#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include "State.h"
#include"YOUneedTHIS.h"
#include"Container.h"
#include"Button.h"

class PauseState : public State
{
public:
	PauseState(StateStack& stack, Context context);
	~PauseState()
	{
		getContext().music->setPaused(false);
	}
	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);


private:
	sf::Sprite mBackgroundSprite;
	sf::Text mPausedText;
	GUI::Container mGUIContainer;
};

#endif // !PAUSESTATE_H_
