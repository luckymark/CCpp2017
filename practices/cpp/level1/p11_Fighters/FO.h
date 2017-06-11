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
	void setSButterfly(double x, double y);
	sf::Vector2f getJulgeArea();
	~FO();
	

public:
	sf::Sprite hero, HSAmmo, LSAmmo;
	sf::Texture Reimu, Marisa, Sanae, Enemy1, Enemy2;
	//sf::Texture frame;
	int HealthPoint, Score, width, height, staticFrame, dynamicFrame, phase;
	sf::Vector2f velocity;
	double damage, speed, theta;
	bool isSym;
	int type, gap, born, score, bounds;

};

