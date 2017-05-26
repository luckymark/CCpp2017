/*
 * control2.cpp
 *
 *  Created on: 2017年5月18日
 *      Author: mark
 */
#include"advanced.h"
#include"flight.h"
#include <SFML/System.hpp>
#include<time.h>
#include<stdlib.h>
#include<iostream>
void Flight::control2()
{
		sf::Mutex mutex;
		srand(time(0));
		static sf::Clock clock ;
		while(sprite.getPosition().y<800){
			int choice = rand()%4;
			mutex.lock();
			s = 0 ;
			switch (choice){
			case 0 :
				sprite.move(0,10);
				break;
			case 1 :
				if(sprite.getPosition().x<1225){
					sprite.move(20,0);
				}
				break;
			case 2 :
				if(sprite.getPosition().x>0){
					sprite.move(-20,0);
				}
				break;
			case 3 :
					s = 1 ;
					break;
			}
			mutex.unlock();
			sf::sleep(sf::milliseconds(100));
		}
}



