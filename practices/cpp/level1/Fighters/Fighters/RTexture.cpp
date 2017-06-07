#include "RTexture.h"
#include <SFML/Graphics.hpp>
sf::Texture RTexture::PLAYER;
sf::Texture RTexture::BULLET1;
sf::Texture RTexture::BULLET2;
sf::Texture RTexture::BULLET3;
sf::Texture RTexture::ENEMY;
sf::Texture RTexture::BACK_GROUND;
sf::Texture RTexture::BOOM1;
sf::Texture RTexture::PLAYER1;
sf::Font RTexture::FONT;
RTexture::RTexture()
{
	//ctor
}

RTexture::~RTexture()
{
	//dtor
}

void RTexture::load()
{
	PLAYER1.loadFromFile("resource/image/NULL.png");
	PLAYER.loadFromFile("resource/image/hero.png");
	BULLET1.loadFromFile("resource/image/bullet.png");
	BULLET2.loadFromFile("resource/image/bullet1.png");
	BULLET3.loadFromFile("resource/image/bullet3.png");
	ENEMY.loadFromFile("resource/image/enemy1.png");
	BACK_GROUND.loadFromFile("resource/image/back.jpg");
	BOOM1.loadFromFile("resource/image/boom.png");
	FONT.loadFromFile("resource/font/font.ttf");
}
