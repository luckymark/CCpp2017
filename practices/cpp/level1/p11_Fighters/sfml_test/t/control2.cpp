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
	srand(time(0));

	while(sprite.getPosition().y<800){
	int choice = rand()%3;

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
	}
	sf::sleep(sf::milliseconds(100));

	}

}



