
#include "World.h"
#include "Player.h"

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
	void					processInput();
	void					update(sf::Time elapsedTime);
	void					render();
	void					updateStatistics(sf::Time elapsedTime);
	void					handlePlayerInput(sf::Keyboard::Key, bool);

private:
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	World					mWorld;
	Player					mPlayer;

	sf::Font				mFont;
	sf::Text				mStatisticsText;
	sf::Time				mStatisticsUpdateTime;
	std::size_t				mStatisticsNumFrames;
};

