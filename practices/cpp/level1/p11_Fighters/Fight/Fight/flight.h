/*
 * flight.h
 *
 *  Created on: 2017年5月16日
 *      Author: CHEN
 */

#ifndef FLIGHT_H_
#define FLIGHT_H_
#include <SFML/Graphics.hpp>
#include<time.h>
#include<stdlib.h>
#include<iostream>

class Flight
{
public:
	Flight(){
		life = 1 ;
		sprite.scale(0.5,0.5);
		sprite.setPosition(500,500);
		x1 = 500;
		y1 = 500;
		x2 = x1+130;
		y2 = y1;
		live = 1;
		speed = 0 ;
		acc= 0;
		direction = 0 ;
	}
	virtual ~Flight(){
		std::cout<"destory";
	}

	void SetTexture(sf::Texture globaltexture){
		texture = globaltexture ;
		sprite.setTexture(texture);
	}

	void SetPosiontion(int x , int y){
		sprite.setPosition(x,y);
		if(x<750)direction = 1;
		if(x>450)direction = 2;
		if(x>=450&&x<=750)direction = 0;
		x1 = x-130 ;
		x2 = x;
		y1 = y -80 ;
		y2 = y -80 ;
	}

	int control();

	int control2();


	sf::Sprite &GetSprite(){
		return sprite ;
	}

	void ankel(){
		sprite.setRotation(180);
	}

	void setlive(){
		live = 0;
	}

	void setlife(int n){
		life = life + n;
	}

	bool ifdeath(){
		if(life==0){
			return true;
		}
		return false ;
	}
	int getx(){
		return  sprite.getPosition().x;
	}
	int gety(){
		return  sprite.getPosition().y ;
	}
	int getlive(){
		return live;
	}

private:
	int life ;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock clock;
	int live ;
public:
	int x1 ;
	int y1 ;
	int x2 ;
	int y2 ;
	int speed ;
	int acc;
	int direction;
};




#endif /* FLIGHT_H_ */
