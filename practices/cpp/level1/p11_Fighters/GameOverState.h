#ifndef GAMEOVERSTATE_H_
#define GAMEOVERSTATE_H_

#include "State.h"
#include "Container.h"
#include <SFML/Graphics.hpp>

class GameOverState : public State
{
	public:
							GameOverState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);

	private:
		sf::Text			mGameOverText;
		sf::Time			mElapsedTime;
};

#endif // GAMEOVERSTATE_H_
