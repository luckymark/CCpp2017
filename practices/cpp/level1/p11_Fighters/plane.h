#ifndef PLANE_H
#include "stdafx.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>
#define PLANE_H
class plane {

	public:
		plane(float x, float y,char type);
		void setPlane(float x,float y);
		void movePlane(float x, float y);
		void showPlane(sf::RenderWindow &thisWindow);
		void Fire();
		void moveBullet();
	protected:
		bullet plane_bullet;
		sf::Texture plane_texture;
		sf::Sprite plane_sprite;
		float x, y;

};

#endif
