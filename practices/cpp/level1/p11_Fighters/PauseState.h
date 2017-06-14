#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include "State.h"
#include "Container.h"
#include <SFML/Graphics.hpp>

class PauseState : public State
{
	public:
							PauseState(StateStack& stack, Context context);
							~PauseState();

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);

	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mPausedText;
		GUI::Container 		mGUIContainer;
};

#endif // PAUSESTATE_H_
