/*
 * map.h
 *
 *  Created on: 2017年5月16日
 *      Author: mark
 */

#ifndef MAP_H_
#define MAP_H_
#include <SFML/Graphics.hpp>
class Map
{
private:
	sf::Texture texture ;
	sf::Sprite sprite ;
public:
	Map(const char* namefile){
		texture.loadFromFile(namefile);
		sprite.setTexture(texture);
		sprite.scale(1.3,1.5);
	}
	Map();
	sf::Sprite Getsprite(){
		return sprite;
	}
};

#endif /* MAP_H_ */
