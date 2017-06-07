#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Audio.hpp>
#include "MMusic.h"
#include "Plane.h"

class Enemy :public Plane
{
public:
	Enemy(World *world);
	virtual ~Enemy();
	void enemyMove();
	void Fire();
	void AddEnemyBullet();
	void boomCheck(int state);
	int state = 0;
	int mark;

protected:
	sf::Vector2f direction;
	int num = 1;
	int *_num;

private:
};

#endif // ENEMY_H
