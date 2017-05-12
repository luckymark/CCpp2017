#include "Game.h"

void Game::processEvent()
{
	sf::Event event;
	while (window.pollEvent(event))
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
			window.close();
			break;
		}
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::Up:
		IisUp = isPressed;
		break;
	case sf::Keyboard::Down:
		IisDown = isPressed;
		break;
	case sf::Keyboard::Left:
			IisLeft = isPressed;
			break;
	case sf::Keyboard::Right:
		IisRight = isPressed;
		break;
	case sf::Keyboard::LShift:
		IisLshift = isPressed;
		break;
	}
}

void Game::update(sf::Time deltatime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (IisUp)
	{
		movement.y -= player.Speed();
	}
	if (IisDown)
	{
		movement.y += player.Speed();
	}
	if (IisLeft)
	{
		movement.x -= player.Speed();
	}
	if (IisRight)
	{
		movement.x += player.Speed();
	}
	switch (IisLshift)
	{
	case true:player.SetSpeed(500); break;
	case false:player.SetSpeed(250); break;
	}
	player.Move(movement, deltatime);
}

void Game::render()
{
	window.clear();
	window.draw(player.Sprite());
	window.display();
}

Game::Game():window(sf::VideoMode(1440,900),"Iphone War"),player()
{
	if (!music.openFromFile("C:\\Users\\q9160\\Desktop\\ÉÏº£¥¢¥ê¥¹»Ã˜·‡â - U.N.¥ª©`¥¨¥ó¤Ï±ËÅ®¤Ê¤Î¤«£¿.wav"))
	{
		//
	}

}

void Game::run()
{
	sf::Clock clock;
	music.play();
	while (window.isOpen())
	{
		sf::Time deltatime = clock.restart();
		processEvent();
		update(deltatime);
		render();
	}
}
