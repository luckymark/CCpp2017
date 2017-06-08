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
	int live;
	void set_bossState(int i);
	int get_bossState();
	int bulletState = 0;

protected:
	sf::Vector2f direction;
	int bossState = 0;

private:
	//int bulletState = 0;
};

#endif // ENEMY_H
