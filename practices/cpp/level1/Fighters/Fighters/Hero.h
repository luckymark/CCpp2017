
#ifndef HERO_H
#define HERO_H
#include "Plane.h"
#include "MMusic.h"
#include "RTexture.h"
#include <SFML/System.hpp>
class Hero :public Plane
{
public:
	Hero(World *world);
	virtual ~Hero();
	bool dead();
	void init();
	void shoot();
	void AddScore(int score);
	void AddLife();
	int unbeatable = -10;
	int life = 3;
	int GetLife();
	int GetScore();
	friend class World;
protected:

private:
	int score;
	sf::Texture texture = RTexture::PLAYER;
};

#endif // HERO_H
