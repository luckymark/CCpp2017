#include "Player.h"

Player::Player()
{
	if (!texture.loadFromFile("C:\\Users\\q9160\\Desktop\\Iphone.png"))
	{
		//
	}
	sprite.setTexture(texture);
	sprite.setPosition(720.f, 682.f);
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
