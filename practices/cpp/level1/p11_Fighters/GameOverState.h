
#include "State.h"
#include "Container.h"

#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Graphics\Text.hpp>


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

