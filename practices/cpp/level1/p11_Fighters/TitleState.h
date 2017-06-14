#ifndef TITLESTATE_H_
#define TITLESTATE_H_

#include "State.h"
#include <SFML/Graphics.hpp>

class TitleState : public State
{
	public:
							TitleState(StateStack& stack, Context context);

		virtual void		draw();
		virtual bool		update(sf::Time dt);
		virtual bool		handleEvent(const sf::Event& event);

	private:
		sf::Sprite			mBackgroundSprite;
		sf::Text			mText;
		bool				mShowText;
		sf::Time			mTextEffectTime;
};

#endif // TITLESTATE_H_
