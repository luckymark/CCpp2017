#ifndef BULLET_H
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#define BULLET_H

struct info {
	sf::Texture bullet_texture;
	sf::Sprite bullet_sprite;
	float x, y;
	float speed;
	bool ifExist;
};
class bullet {
	public:
		info * bulletInfo;
		bullet(int max=50);
		void appendBullet(float x, float y, char type);
		void moveBullet();
		void showBullet(sf::RenderWindow &thisWindow);
		bool isExist(int index);
	protected:
		
		int max;
		int tail;

};
#endif
