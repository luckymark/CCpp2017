#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_
#include"YOUneedTHIS.h"
#include"ResourseHolder.h"
class Player
{
private:
	sf::Sprite sprite;
	float speed;
public:
	Player(ResourseHolder<sf::Texture, Resourse::identifier>& resourse);
	Player() {};
	void Move(sf::Vector2f movement, sf::Time t);
	void SetSpeed(float s);
	float Speed();
	sf::Sprite & Sprite();
};
#endif // !PLAYER_H_
