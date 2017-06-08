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
sf::Texture RTexture::LIFE;
sf::Font RTexture::FONT;
sf::Texture RTexture::BOSS;
sf::Texture RTexture::BOSS1;
sf::Texture RTexture::BOSSBULLET;
sf::Texture RTexture::BOSSBULLET1;
sf::Texture RTexture::BOSSNULLET2;
sf::Texture RTexture::PLAYER2;
sf::Texture RTexture::BULLETBONUS;
sf::Texture RTexture::RANDBONUS;
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
	BOSS.loadFromFile("resource/image/BOSS.png");
	BOSS1.loadFromFile("resource/image/boss1.png");
	BOSSBULLET.loadFromFile("resource/image/bossbullet.png");
	BOSSBULLET1.loadFromFile("resource/image/bossbullet1.png");
	BOSSNULLET2.loadFromFile("resource/image/bossbullet2.png");
	RANDBONUS.loadFromFile("resource/image/randBonus.png");
	BULLETBONUS.loadFromFile("resource/image/bulletBonus.png");
	PLAYER2.loadFromFile("resource/image/hero1.png");
	PLAYER1.loadFromFile("resource/image/NULL.png");
	PLAYER.loadFromFile("resource/image/hero.png");
	BULLET1.loadFromFile("resource/image/bullet.png");
	BULLET2.loadFromFile("resource/image/bullet1.png");
	BULLET3.loadFromFile("resource/image/bullet3.png");
	ENEMY.loadFromFile("resource/image/enemy1.png");
	BACK_GROUND.loadFromFile("resource/image/back.jpg");
	BOOM1.loadFromFile("resource/image/boom.png");
	LIFE.loadFromFile("resource/image/life.png");
	FONT.loadFromFile("resource/font/font.ttf");
}
