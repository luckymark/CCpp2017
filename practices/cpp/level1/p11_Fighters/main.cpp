// skyLegend.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include "plane.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Sky Legend");
	plane playersPlane(350,500,'p');
	sf::SoundBuffer buffer;
	buffer.loadFromFile("bgm1.flac");
	sf::Sound sound;
	sound.setBuffer(buffer);
	sound.play();
	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		playersPlane.showPlane(window);
		window.display();
		
	}

	return 0;
}