#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_
#include<iostream>
#include<SFML\Graphics.hpp>
class Player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	float speed;
public:
	Player();
	void Move(sf::Vector2f movement, sf::Time t);
	void SetSpeed(float s);
	float Speed();
	sf::Sprite & Sprite();
};
#endif // !PLAYER_H_
