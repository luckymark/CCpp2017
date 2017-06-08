#ifndef RTEXTURE_H
#define RTEXTURE_H
#include <SFML/Graphics.hpp>


class RTexture
{
public:
	RTexture();
	virtual ~RTexture();
	static sf::Texture PLAYER;
	static sf::Texture ENEMY;
	static sf::Texture BULLET1;
	static sf::Texture BULLET2;
	static sf::Texture BACK_GROUND;
	static sf::Texture BOOM1;
	static sf::Texture BULLET3;
	static sf::Texture PLAYER1;
	static sf::Texture LIFE;
	static sf::Texture BOSS;
	static sf::Texture BOSS1;
	static sf::Texture BOSSBULLET;
	static sf::Texture BOSSBULLET1;
	static sf::Texture BOSSNULLET2;
	static sf::Texture PLAYER2;
	static sf::Texture BULLETBONUS;
	static sf::Texture RANDBONUS;
	static sf::Font FONT;
	static void load();

protected:

private:
};

#endif // RTEXTURE_H
