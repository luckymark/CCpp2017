
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
	void shoot(int j);
	void AddScore(int score);
	void AddLife();
	int unbeatable = -10;
	int life = 3;
	int GetLife();
	int GetScore();
	void set_bulletmuch(int BulletMuch);
	int get_bulletmuch();
	void set_bonusmuch(int bonusmuch);
	int get_bonusmuch();

	friend class World;
protected:

private:
	int score;
	int BulletMuch = 1;
	int bonusmuch = 0;
	sf::Texture texture=RTexture::PLAYER2 ;
};

#endif // HERO_H
