#ifndef PLANE_H
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#define PLANE_H
class plane {

	public:
		
		plane(int x, int y,char type);
		void setPlane(int x,int y);
		void showPlane(sf::RenderWindow &thisWindow);
	protected:
		sf::Texture plane_texture;
		sf::Sprite plane_sprite;
		int x, y;
};

#endif
