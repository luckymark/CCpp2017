/*
 * explosin.h
 *
 *  Created on: 2017年5月28日
 *      Author: chen
 */

#ifndef EXPLOSION_H_
#define EXPLOSION_H_
class Explosion{
public:
	Explosion(sf::Texture &Global){
		texture = Global;
		sprite.setTexture(texture);
	}
	void setposition(int x , int y){
		sprite.setPosition(x-50,y-50);
	}
	sf::Clock clock ;
	sf::Sprite sprite ;
	sf::Texture texture ;
};




#endif /* EXPLOSIN_H_ */
