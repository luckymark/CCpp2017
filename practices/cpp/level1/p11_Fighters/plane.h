#ifndef PLANE_H
#include "stdafx.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>
#define PLANE_H

class plane {

	public:
		bullet * plane_bullet;
		plane(float x=0, float y=0,char type='e');
		void setPlane(float x,float y);
		void movePlane(float x, float y);
		void movePlane();
		void showPlane(sf::RenderWindow &thisWindow);
		void Fire();
		void moveBullet();
		void lifeChange(int delta);
		bool isExist();
		bool isCollision(float x, float y, float Xsize, float Ysize);
		bool collision(bullet & bp);
		bool collision(plane & p);
	protected:
		
		sf::Texture plane_texture;
		sf::Sprite plane_sprite;
		short life;
		float x, y;
		float speed;
		float half_sizeX, half_sizeY;

};
void appendEnemy(plane * enemy,int index);
void moveEnemy(plane * enemy, plane & player,int max, bool & ifCollision);
void showEnemy(sf::RenderWindow &thisWindow,plane * enemy,int max);
#endif
