/*
 * t.cpp
 *
 *  Created on: 2017年5月5日
 *      Author: mark
 */
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<iostream>
#include"advanced.h"
#include"flight.h"
#include"map.h"
#include"bullet2.h"
#define WIDE 1300
#define HIGH 1000

int main()
{
	sf::Mutex mutex;

    sf::RenderWindow window(sf::VideoMode(WIDE,HIGH), "Fly to Dream");

    Flight MyFlight("timg.jpg");
    Flight EnemeyFlight;
    Map map("map.jpg");

    ArrayBullet Bullet;

    sf::Thread EnemeyControl(&Flight::control2,&EnemeyFlight);
    sf::Thread BulletControl(&ArrayBullet::control_bullet,&Bullet);

    EnemeyControl.launch();
    BulletControl.launch();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            	window.close();
        }
        int b=MyFlight.control();

        if(b)Bullet.add_m(MyFlight.getx(),MyFlight.gety());
        mutex.lock();

        window.clear(sf::Color::Black);
        window.draw(map.Getsprite());
        window.draw(MyFlight.GetSprite());
        window.draw(EnemeyFlight.GetSprite());
        for(int i= 0 ; i < Bullet.A.size();i++){
        	window.draw(Bullet.A[i].getsprite());
        }
        window.display();

        mutex.unlock();
    }

    return 0;

}
