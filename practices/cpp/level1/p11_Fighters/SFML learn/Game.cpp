#include"Game.h"

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

void Game::update()
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
	{
		movement.y -= 0.3f;
	}
	if (mIsMovingDown)
	{
		movement.y += 0.3f;
	}
	if (mIsMovingLeft)
	{
		movement.x -= 0.3f;
	}
	if (mIsMovingRight)
	{
		movement.x += 0.3f;
	}
	mPlayer.move(movement);
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::W:
		mIsMovingUp = isPressed;
		break;
	case sf::Keyboard::S:
		mIsMovingDown = isPressed;
		break;
	case sf::Keyboard::A:
		mIsMovingLeft = isPressed;
		break;
	case sf::Keyboard::D:
		mIsMovingRight = isPressed;
		break;
	}

}

Game::Game():mWindow(sf::VideoMode(1440,900),"SFMl Application"),mPlayer()
{
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
}

void Game::run()
{
	processEvents();
	update();
	render();
}
