#pragma once
#ifndef GAME_H_
#define GAME_H_
#include<SFML\graphics.hpp>
#include<iostream>

class Game
{
private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;
private:
	void processEvents();
	void update();
	void render();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
public:
	Game();
	void run();
};
#endif // !GAME_H_