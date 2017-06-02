/*
 * map.h
 *
 *  Created on: 2017年5月28日
 *      Author: chen
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
		sprite.scale(2,2);
	}
	Map();
	sf::Sprite Getsprite(){
		return sprite;
	}
};




#endif /* MAP_H_ */
