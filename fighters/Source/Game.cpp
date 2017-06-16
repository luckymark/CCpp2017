#include"Include\Game.h"
#include "Include\StringHelpers.hpp"
#include<SFML/Graphics/Text.hpp>
#include<SFML/Graphics/Font.hpp>



Game::Game()
	: mWindow(sf::VideoMode(640, 600), "F I G H T E R S")
	, mWorld(mWindow,myScore,&myTime,&mPlayer)
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, myScore(0)
	, myTime(sf::seconds(0))
	, isPaused(false)
	, isStarted(false)
{

	mFont.loadFromFile("Media/Sansation.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(30);

	TimePerFrame = sf::seconds(1.f / 60.f);


	pauseTexture.loadFromFile("Media/Textures/pause.png");
	pauseSprite.setTexture(pauseTexture);
	pauseSprite.setPosition(210, 100);

	Intro1.loadFromFile("Media/Textures/intro1.png");
	Intro2.loadFromFile("Media/Textures/intro2.png");
	Intro3.loadFromFile("Media/Textures/intro3.png");
	Intro4.loadFromFile("Media/Textures/intro4.png");
	Intro5.loadFromFile("Media/Textures/intro5.png");

	Intro1.setRepeated(true);
	Intro2.setRepeated(true);
	Intro3.setRepeated(true);
	Intro4.setRepeated(true);

	introSprite.setTexture(Intro1);
	introSprite.setPosition(0, 0);
}
void Game::run()
{
	IntroTheme.play(Music::IntroTheme);
//	sf::Clock									clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{

		if (isStarted)
		{
			sf::Time elapsedTime = clock.restart();
			timeSinceLastUpdate += elapsedTime;

			while (timeSinceLastUpdate > TimePerFrame)
			{
				timeSinceLastUpdate -= TimePerFrame;
				if (!isPaused)
				{
					processInput();
					update(TimePerFrame);
				}
				handlePlayerOption();
			}

			updateStatistics(elapsedTime);
		}
		else
		{
			handlePlayerOption();
		}

		render();
	}
}

void Game::processInput()
{

	CommandQueue& commands = mWorld.getCommandQueue();

	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}

		mPlayer.handleEvent(event, commands);

		if (event.type == sf::Event::Closed)
			mWindow.close();
	}

	mPlayer.handleRealtimeInput(commands);
}


void Game::update(sf::Time deltaTime)
{
	mWorld.update(deltaTime);
}
void Game::render()
{		

	mWindow.clear();	
	mWorld.draw();

	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	if (isPaused)
	{
		mWindow.draw(pauseSprite);
	}
	if (!isStarted)
	{
		mWindow.draw(introSprite);
	}


	mWindow.display();


}
void Game::updateStatistics(sf::Time elapsedTime)
{
	myTime += elapsedTime;

	mStatisticsText.setString("Score: " + toString(myScore));
	
	static bool wasAlive = true;
	static bool toDefeat = true;

	if (mPlayer.isPlayerAlive()!=wasAlive)
	{
		if (toDefeat)
		{
			BattleTheme.setPaused(true);
			DefeatedTheme.play(Music::DefeatedTheme);
			toDefeat = false;
		}
		else
		{
			BattleTheme.setPaused(false);
			DefeatedTheme.stop();
			toDefeat = true;
		}

	}

	wasAlive = mPlayer.isPlayerAlive();
	
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Escape)
	{
		if (isPaused)
		{
			isPaused = false;
			BattleTheme.setPaused(false);
			PauseTheme.stop();
		}
		else
		{
			isPaused = true;
			BattleTheme.setPaused(true);
			PauseTheme.play(Music::PauseTheme);
		}
	}
	else if (key == sf::Keyboard::Q&&!isStarted)
	{
		introCount = 2;
		introSprite.setTexture(Intro2);
	}
	else if (key == sf::Keyboard::Down && !isStarted&&(introCount==2))
	{
		introCount = 3;
		introSprite.setTexture(Intro3);
	}
	else if (key == sf::Keyboard::E && !isStarted && (introCount == 3))
	{
		introCount = 4;
		introSprite.setTexture(Intro4);

	}
	else if (key == sf::Keyboard::Down && !isStarted && (introCount == 4))
	{
		introCount = 5;
		introSprite.setTexture(Intro5);
	}
	else if (key == sf::Keyboard::Up && !isStarted && (introCount == 5))
	{

		IntroTheme.stop();
		BattleTheme.play(Music::BattleTheme);
		isStarted = true;
		clock.restart();
	}
}

void Game::handlePlayerOption()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}
