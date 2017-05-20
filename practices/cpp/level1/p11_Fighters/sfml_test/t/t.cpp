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

    sf::RenderWindow window(sf::VideoMode(WIDE,HIGH), "Fly to Dream");

    Flight MyFlight("timg.jpg");
    Flight EnemeyFlight;
    Map map("map.jpg");

    ArrayBullet bullet;

    sf::Thread thread(&Flight::control2,&EnemeyFlight);

    thread.launch();


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            	window.close();
        }

        if(MyFlight.control())
        	bullet.add_m(MyFlight.getx(),MyFlight.getx());

        window.clear(sf::Color::Black);

        window.draw(map.Getsprite());
        window.draw(MyFlight.GetSprite());
        for(int i= 1 ; i <= bullet.size&&bullet.size!=0;i++){
        	window.draw(bullet.A[i].getsprite());
        }
        window.draw(EnemeyFlight.GetSprite());

        window.display();
    }

    return 0;
}
