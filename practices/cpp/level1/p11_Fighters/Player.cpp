#include "Player.h"

Player::Player(ResourseHolder<sf::Texture,Resourse::identifier>& resourse)
{
	
	sprite.setTexture(resourse.get(Resourse::identifier::Airplane));
	sprite.setPosition(240.f, 582.f);
	speed = 500;
}

void Player::Move(sf::Vector2f movement, sf::Time t)
{
	sprite.move(movement * t.asSeconds());
}

void Player::SetSpeed(float s)
{
	speed = s;
}

float Player::Speed()
{
	return speed;
}

sf::Sprite & Player::Sprite()
{
	return sprite;
	// TODO: insert return statement here
}

