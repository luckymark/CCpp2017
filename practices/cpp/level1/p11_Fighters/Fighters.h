
#include "World.h"

#include <SFML\System\Time.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\RenderWindow.hpp>


class Game : private sf::NonCopyable
{
public:
							Game();
	void					run();


private:
	void					processEvents();
	void					update(sf::Time elapsedTime);
	void					render();

	void					updateStatistics(sf::Time elapsedTime);
	void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);


private:
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	World					mWorld;

	sf::Sprite				mPlayer;
	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;
	bool					mIsMovingUp;
	bool					mIsMovingDown;
	bool					mIsMovingRight;
	bool					mIsMovingLeft;
};

