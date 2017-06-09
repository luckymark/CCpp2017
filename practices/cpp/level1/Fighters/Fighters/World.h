#ifndef MAINLOOP_H
#define MAINLOOP_H
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include<unordered_set>
#include "Bullet.h"
#include "RTexture.h"
#include "Enemy.h"
#include "Bonus.h"
class Hero;
using namespace std;
class World :public sf::Sprite
{
public:
	World(sf::RenderWindow *window);
	virtual ~World();
	bool killed();
	void add(Hero *Hero);
	void addEnemy();
	void addBullet(Bullet *bullet, int mark);
	void Refresh();
	void moveBullet();
	void cleanBullet();
	void EnemyShoot();
	void ClearAll(bool mark);
	void AddBonus(float x,float y);
	void BonusFunction();
	void Skill();
	int bonusState = 0;
	sf::RenderWindow *window;
	Hero *hero;
	bool loading = true;
protected:

private:
	sf::Texture texture = RTexture::BACK_GROUND;
	unordered_set<Enemy * > enemyPlanes;
	unordered_set<Bullet * > heroBullets;
	unordered_set<Bullet * > enemyBullets;
	unordered_set<Bullet * > smallBossBullet;
	unordered_set<Enemy * > smallBoss;
	unordered_set<Bonus * > bonuss;
};

#endif // MAINLOOP_H
