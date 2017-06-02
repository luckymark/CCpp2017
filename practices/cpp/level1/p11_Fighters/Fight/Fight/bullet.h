/*
 * bullet.h
 *
 *  Created on: 2017年5月28日
 *      Author: chen
 */

#ifndef BULLET_H_
#define BULLET_H_

#include <SFML/Graphics.hpp>
class bullet
{
public:
	bullet(char a){
		b = 1 ;
		x = 0 ;
		y = 0 ;
		status = 1;
//		std::cout<<"enemey bullet"<<std::endl;
	}
	bullet(int a){
		b = 0 ;
		x = 0 ;
		y = 0 ;
		status = 1;
//		std::cout<<"my bullet"<<std::endl;
	}

	~bullet(){
//		std::cout<<"bullet start to destruct"<<std::endl;
	}

	int fly1(){
		if(sprite.getPosition().y<1000&&sprite.getPosition().y>0){
			sprite.move(0,-1);
			y--;
			return 1 ;
		}
		else return 0;
	}
	int fly2(){
		if(sprite.getPosition().y<1000&&sprite.getPosition().y>0){
			sprite.move(0,1);
			y++;
			return 1 ;
		}
		else return 0;
	}

	int getx(){
		return x ;
	}

	int gety(){
		return y ;
	}

	int getb(){
		return b ;
	}
	void set(int x1 , int y1){
			sprite.setPosition(x1,y1);
			x = x1 ;
			y = y1 ;
	}

	sf::Sprite getsprite(){
		return sprite;
	}

	void setstatus(){
		status = 0;
	}

	sf::Sprite sprite;
	int b ;
	int x ;
	int y ;
	int status;
};




#endif /* BULLET_H_ */
