#ifndef BULLET_H
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#define BULLET_H
struct info {
	sf::Texture bullet_texture;
	sf::Sprite bullet_sprite;
	float x, y;
	float speed;
};
class bullet {
	public:
		bullet(int max=100);
		void appendBullet(float x, float y, char type);
		void moveBullet();
		void showBullet(sf::RenderWindow &thisWindow);
	protected:
		info bulletInfo[100];
		int head;
		int tail;
		int max;
		bool flag_full, flag_null;

};
#endif
