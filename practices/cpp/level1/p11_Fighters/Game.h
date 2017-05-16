#pragma once
#ifndef GAME_H_
#define GAME_H_
#include"Player.h"
#include"YOUneedTHIS.h"
#include"ResourseHolder.h"
class Game
{
private:
	sf::RenderWindow window;
	sf::Music music;
	ResourseHolder<sf::Texture,Resourse::identifier> resourse;
	Player player;
	sf::Sprite bgi;
private:
	bool IisUp;
	bool IisDown;
	bool IisLeft;
	bool IisRight;
	bool IisLshift;
private:
	void processEvent();
	void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time deltatime);
	void render();
public:
	Game();
	void run();
};
#endif // !GAME_H_
