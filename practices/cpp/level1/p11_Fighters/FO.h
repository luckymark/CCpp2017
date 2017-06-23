#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
class FO
{
public:
	FO();
	FO(int flag);
	void setSButterfly(double x, double y);
	sf::Vector2f getJulgeArea();
	~FO();
	

public:
	sf::Vector2f velocity;
	sf::Sprite hero, HSAmmo, LSAmmo;
	sf::Texture Reimu, Marisa, Sanae, Enemy1, Enemy2;
	int HealthPoint, Score, width, height, staticFrame, dynamicFrame, phase;
	int type, gap, born, score, bounds;
	double damage, speed, theta;
	bool isSym;
};

