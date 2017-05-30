#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class FO
{
public:
	void crash();
	FO();
	FO(int flag);
	~FO();
	sf::Sprite hero, HSAmmo, LSAmmo;
	//sf::Texture frame;

public:
	int HealthPoint, Score, width, height, staticFrame, dynamicFrame;
	sf::Vector2f velocity;
	double damage, speed, theta;
	int type;

};

