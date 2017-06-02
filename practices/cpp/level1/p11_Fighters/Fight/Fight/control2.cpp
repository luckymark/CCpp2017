/*
 * control2.cpp
 *
 *  Created on: 2017年5月28日
 *      Author: chen
 */
#include"advanced.h"
#include"flight.h"
#include <SFML/System.hpp>
#include<time.h>
#include<stdlib.h>
#include<iostream>
int Flight::control2()
{
		sf::Mutex mutex;

			if(direction == 0){
			if(sprite.getPosition().y<1000){
					sprite.move(0,20);
				}
			}

			if(direction == 1){
				acc++;
				speed = speed + acc;
				if(acc==3){
					direction=2;
				}
			}
			if(direction == 2){
				acc--;
				speed = speed +acc ;
				if(acc==-3){
					direction= 1 ;
				}
			}
			if(sprite.getPosition().y<1000&&sprite.getPosition().x<1000&&sprite.getPosition().x>0){
				sprite.move(speed,10);
				x1 = x1 +speed;
				x2 = x1 ;
				y1 = y1 + 20;
				y2 = y1;
			}
			else{
				live = 0;
				return 0;
			}
		if(clock.getElapsedTime()>sf::milliseconds(1000)){
			clock.restart();
			return 1;
		}
		return 0;

}




