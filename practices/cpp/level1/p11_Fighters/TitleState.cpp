#include "TitleState.h"
#include "Utility.h"
#include "ResourceHolder.h"




TitleState::TitleState(StateStack& stack, Context context)
: State(stack, context)
, mText()
, mShowText(true)
, mTextEffectTime(sf::Time::Zero)
{
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));

	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setString("Press any key to start");
	centerOrigin(mText);
	mText.setPosition(sf::Vector2f(context.window->getView().getSize().x / 2.f, context.window->getView().getSize().y / 5.f * 4));
}

void TitleState::draw()
{
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);

	if (mShowText)
		window.draw(mText);
}

bool TitleState::update(sf::Time dt)
{
	//mTextEffectTime += dt;

//	if (mTextEffectTime >= sf::seconds(0.5f))
//	{
		//mShowText = !mShowText;
		//mTextEffectTime = sf::Time::Zero;
//	}

	return true;
}

bool TitleState::handleEvent(const sf::Event& event)
{
	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyReleased)
	{
		requestStackPop();
		requestStackPush(States::Menu);
	}

	return true;
}