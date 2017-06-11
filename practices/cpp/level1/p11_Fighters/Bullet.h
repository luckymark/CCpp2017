#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#define HERO_BULLET 1
#define ENEMY_BULLET 2
class Bullet:public sf::Sprite{
public:
	Bullet(){};
	Bullet(const Bullet& bullet);
	Bullet(int type);
	int getType();
private:
	int type;
};
#endif